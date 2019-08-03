/*************************
* Ryan Carney
* CPSC 1020 Sm19
* rjcarne
*************************/

#include "Person.h"

using namespace std;

//Define static variable for person ID
int Person::customerCount = 0;

//Default constructor
Person::Person() : last("Last"), first("Name"), email("Email"),
        address(1, "street", "city", "state", 12345), bday(1,1,200) {
        customerCount++;
        customerID = customerCount;
}

//Normal Constructor. Used for customer sign in
Person::Person(string last, string first, string email, int house,
               string street, string city, string state, int zip,
               int month, int day, int year) : last(last), first(first),
        email(email), address(house, street, city, state, zip),
        bday(month, day, year) {
        customerCount++;
        customerID = customerCount;
        cout << "You have been added to our directory" << endl;
}
//Constructor used for inputting from file
Person::Person(ifstream& inFile) : address(), bday() {
        char eater;
        inFile >> last >> first;
        int house, zip, month, day, year;
        string street, city, state;
        inFile >> house >> street >> city >> state >> zip >> email;
        inFile >> month >> eater >> day >> eater >> year;
        address.setAddress(house, street, city, state, zip);
        bday.setDay(day);
        bday.setMonth(month);
        bday.setYear(year);
        customerCount++;
        customerID = customerCount;
}

//returns address obviously
Address Person::getAddress() {
        return address;
}

//changes person values.
void Person::setPerson(string last, string first, string email, int house,
                       string street, string city, string state, int zip,
                       int month, int day, int year) {
        this->last = last;
        this->first = first;
        this->email = email;
        this->address.setAddress(house, street, city,
                                 state, zip);
        this->bday.setMonth(month);
        this->bday.setDay(day);
        this->bday.setYear(year);
}

//returns age
int Person::getAge() {
        return bday.getAge();
}

//Prints info to file for directory
void Person::printInfo(ofstream& outFile) {
        outFile << last << " " << first << endl;
        outFile << email << endl;
        address.printAddress(outFile);
        bday.printDate(outFile);
}

//prints info to terminal. used in recognizing customer function
void Person::printInfo() {
        cout << last << " " << first << endl;
        cout << email << endl;
        address.printAddress();
        bday.printDate();
}

//changes person values with prompts. used for changing personal info
//for recognized people
void Person::changeInfo() {
        int house1, zip1, day1, month1, year1, testbday = -1;
        string street1, city1, state1;
        cout << "Enter your last name: ";
        cin >> last;
        last += ',';
        cout << "Enter your first name: ";
        cin >> first;
        cout << "Enter your email: ";
        cin >> email;
        cout << "Enter your address(Example: 123 Street Clemson SC 29670): ";
        cin >> house1 >> street1 >> city1 >> state1 >> zip1;
        address.setAddress(house1, street1, city1, state1, zip1);
        while (testbday != 1) {
                cout << "Enter your date of birth(Example: 10 31 1994): ";
                cin >> month1 >> day1 >> year1;
                testbday = testBday(month1, day1, year1);
        }
        bday.setMonth(month1);
        bday.setDay(day1);
        bday.setYear(year1);
        ofstream outFile("customerOutEC2.txt");
        if (outFile.fail()) {
          cout << "Could not print customerOutEC2.txt" << endl;
        }
        printInfo(outFile);
}

int Person::getID() {
        return customerID;
}

string Person::getLast() {
        return last;
}

string Person::getFirst() {
        return first;
}

string Person::getEmail() {
        return email;
}
