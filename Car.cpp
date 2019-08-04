

#include "Car.h"

using namespace std;

//Constructor from file
Car::Car(ifstream& inFile) : Vehicle(inFile){
        available = true;
}

//Gets age, condition and miles of car and checks to see if it can be rented
void Car::isRentable() {
        time_t t = time(0);
        struct tm * now = localtime( &t );

        int age = (now->tm_year + 1900) - year;
        if (age <= 2 && miles < 20000 && condition == "Excellent") {
                rentable = true;
        }
        else {
                rentable = false;
        }
}

//Prints car info to file
void Car::printInfo(ofstream& outFile) {
        outFile << "ID: " << id << endl;
        outFile << year << " " << make << " " << model << endl << "Color: ";
        outFile << color << endl << "Miles: " << miles << endl << "Condition: "
                << condition << endl;
        outFile << "Price: $" << salesPrice << endl << endl;
}

//Prints car info to terminal
void Car::printInfo() {
        cout << "ID: " << id << endl;
        cout << year << " " << make << " " << model << endl << "Color: ";
        cout << color << endl << "Miles: " << miles << endl << "Condition: "
             << condition << endl;
        cout << "Price: $" << salesPrice << endl << endl;
}

//returns whether car is rentable for vector creation in inventory
bool Car::getRentable() {
        return rentable;
}
