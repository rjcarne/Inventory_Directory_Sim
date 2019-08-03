/*************************
* Ryan Carney
* CPSC 1020 Sm19
* rjcarne
*************************/

#include "Address.h"

using namespace std;
//constructs address
Address::Address(int house, string street, string city, string state, int zip)
        : house(house), street(street), city(city), state(state), zip(zip) {
}

Address::Address() : house(1), street("Street Name"), city("City Name"),
        state("State Name"), zip(11111) {
}
//sets new address values
void Address::setAddress(int house, string street, string city,
                         string state, int zip) {
        this->house = house;
        this->street = street;
        this->city = city;
        this->state = state;
        this->zip = zip;
}
//prints address data to file
void Address::printAddress(ofstream& outFile) {
        outFile << house << " " << street << endl;
        outFile << city << " " << state << " " << zip << endl;
}
//prints address data to terminal
void Address::printAddress() {
        cout << house << " " << street << endl;
        cout << city << " " << state << " " << zip << endl;
}
