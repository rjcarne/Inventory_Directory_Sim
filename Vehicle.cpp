/*************************
* Ryan Carney
* CPSC 1020 Sm19
* rjcarne
*************************/

#include "Vehicle.h"

using namespace std;

//Vehicle ID
int Vehicle::inventoryCount = 0;

//Vehicle constructor from file
Vehicle::Vehicle(ifstream& inFile) {
        inFile >> make >> model >> year >> color
        >> salesPrice >> miles
        >> condition;
        inventoryCount++;
        id = inventoryCount;

}

int Vehicle::getYear() {
        return year;
}

int Vehicle::getMiles() {
        return miles;
}

string Vehicle::getCondition() {
        return condition;
}

int Vehicle::getCount() {
        return inventoryCount;
}

int Vehicle::getID() {
        return id;
}

void printInfo(ofstream& outFile) {
        
}
