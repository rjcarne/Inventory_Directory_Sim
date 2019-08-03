/*************************
* Ryan Carney
* CPSC 1020 Sm19
* rjcarne
*************************/

#include "Truck.h"

using namespace std;

Truck::Truck(ifstream& inFile) : Vehicle(inFile) {
        inFile >> bedType;
}

void Truck::printInfo(ofstream& outFile) {
        outFile << "ID: " << id << endl;
        outFile << year << " " << make << " " << model << endl << "Color: ";
        outFile << color << endl << "Miles: " << miles << endl << "Condition: ";
        outFile << condition << endl;
        outFile << "Bed Type: " << bedType << endl;
        outFile << "Price: $" << salesPrice << endl << endl;
}

void Truck::printInfo() {
        cout << "ID: " << id << endl;
        cout << year << " " << make << " " << model << endl << "Color: ";
        cout << color << endl << "Miles: " << miles << endl << "Condition: ";
        cout << condition << endl;
        cout << "Bed Type: " << bedType << endl;
        cout << "Price: $" << salesPrice << endl << endl;
}
