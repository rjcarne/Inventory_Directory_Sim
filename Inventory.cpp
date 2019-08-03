/*************************
* Ryan Carney
* CPSC 1020 Sm19
* rjcarne
*************************/

#include "Inventory.h"
#include "Functions.h"

using namespace std;

//Adds a car to the carSale vector, tests if new enough to Rent
//If yes, adds to Rent vector also
void Inventory::addInventory(Car& carInput) {
  carInput.isRentable();
  if (carInput.getRentable() == true) {
    carRental.push_back(carInput);
  }
  carSale.push_back(carInput);
}

//Adds truck to truck vector
void Inventory::addInventory(Truck& truckInput) {
  truckSale.push_back(truckInput);
}

//Prints All vehicles to a file by category
void Inventory::printInventory(ofstream& outFile) {

  outFile << carSale.size() << " Cars Available for Sale" << endl;
  outFile << "*********************" << endl;
  for (unsigned int i = 0; i < carSale.size(); i++) {
    carSale.at(i).printInfo(outFile);
  }
  outFile << endl;

  outFile << carRental.size() << " Cars Available for Rent";
  outFile << endl << "*********************" << endl;
  for (unsigned int i = 0; i < carRental.size(); i++) {
    carRental.at(i).printInfo(outFile);
  }
  outFile << endl;

  outFile << truckSale.size() << " Trucks Available for Sale";
  outFile << endl << "*********************" << endl;
  for (unsigned int i = 0; i < truckSale.size(); i++) {
    truckSale[i].printInfo(outFile);
   }
}

//Prints Selected type of vehicle in current inventory to terminal
void Inventory::printInventory(char type) {
  type = tolower(type);
  cout << endl;
  if (type == 'r') {
    cout << carRental.size() << " Cars Available for Rent";
    cout << endl << "*********************" << endl;
    for (unsigned int i = 0; i < carRental.size(); i++) {
      carRental.at(i).printInfo();
    }
    cout << endl;
  }
  if (type == 'c') {
    cout << carSale.size() << " Cars Available for Sale";
    cout << endl << "*********************" << endl;
    for (unsigned int i = 0; i < carSale.size(); i++) {
      carSale.at(i).printInfo();
    }
    cout << endl;
  }
  if (type == 't') {
    cout << truckSale.size() << " Trucks Available for Sale";
    cout << endl << "*********************" << endl;
    for (unsigned int i = 0; i < truckSale.size(); i++) {
      truckSale.at(i).printInfo();
    }
    cout << endl;
  }
}

//Reads inventory of vehicles from file
void Inventory::readInventory(ifstream& inFile) {
  while(!inFile.eof()) {
    string type;
    inFile >> type;
    if (type == "Car") {
      Car newCar(inFile);
      addInventory(newCar);
    }
    if (type == "Truck") {
      Truck newTruck(inFile);
      addInventory(newTruck);
    }
  }
}

//Removes a vehicle from inventory by inputting an ID number
void Inventory::removeInventory(int idRem) {

  for (unsigned int i = 0; i < carRental.size(); i++) {
    if (carRental[i].getID() == idRem) {
      carRental.erase(carRental.begin() + i);
    }
  }
  for (unsigned int i = 0; i < carSale.size(); i++) {
    if (carSale[i].getID() == idRem) {
      carSale.erase(carSale.begin() + i);
    }
  }
  for (unsigned int i = 0; i < truckSale.size(); i++) {
    if (truckSale[i].getID() == idRem) {
      truckSale.erase(truckSale.begin() + i);
    }
  }
}

//Prints current directory of people to file
void Inventory::printDirectory(ofstream& outFile) {
  outFile << directory.size() << " Valued Customers";
  outFile << endl << "*********************" << endl;
  for (unsigned int i = 0; i < directory.size(); i++) {
    directory[i].printInfo(outFile);
    outFile << endl;
  }
  outFile << endl;
}

//Reads directory in from file. Used the same format from lab 7 out.txt
//removed ',' from out.txt after last name. Couldn't find how to
//remove it from input string
void Inventory::readDirectory(ifstream& inFile) {
  while(!inFile.eof()) {
    Person newPerson(inFile);
    if(newPerson.getAge() < 1000 && newPerson.getAge() > -1000) {
      directory.push_back(newPerson);
  }
  }
}

//adds customer to directory
int Inventory::addCustomer() {
  string last, first, email, street, city, state;
  int house, zip, month, day, year, findCheck = 0, testbday = 0;

  cout << "Enter your last name: ";
  cin >> last;
  last += ',';
  cout << "Enter your first name: ";
  cin >> first;
  cout << "Enter your email: ";
  cin >> email;
  findCheck = findPerson(first, last, email);
  if (findCheck == -1) {
    cout << "Enter your address(Example: 123 Street Clemson SC 29670): ";
    cin >> house >> street >> city >> state >> zip;
    while (testbday != 1) {
      cout << "Enter your date of birth(Example: 10 31 1994): ";
      cin >> month >> day >> year;
      testbday = testBday(month, day, year);
    }
    Person newPerson(last, first, email, house,
                    street,  city, state, zip,
                    month, day, year);

    directory.push_back(newPerson);
    return (directory.size() - 1);
  }
  else {
    cout << "Welcome back " << first << "!" << endl << endl;
    return findCheck;
  }

}

//removes customer from directory
void Inventory::removeCustomer(int remID) {
  for (unsigned int i = 0; i < directory.size(); i++) {
    if (directory[i].getID() == remID) {
      directory.erase(directory.begin() + i);
    }
  }
}

//checks if person is already in directory
int Inventory::findPerson(string first, string last, string email){
  int testChar = -1;
  char answer, answer2;
  for (unsigned int i = 0; i < directory.size(); i++) {
    if (directory[i].getLast() == last && directory[i].getFirst() == first
          && directory[i].getEmail() == email) {

    while(answer != 'y' && answer != 'n') {
      cout << "Is this you? (Type y for yes or n for no)" << endl << endl;
      directory[i].printInfo();
      cin >> answer;
      answer = tolower(answer);
      if (answer != 'y' && answer != 'n') {
        cout << "That is not a valid response. Please try again" << endl;
      }
    }
      if (answer == 'y') {
        testChar = i;
        while(answer2 != 'y' && answer2 != 'n') {
        cout << "Would you like to change any of your contact information?";
        cout << "(Type y for yes or n for no): " << endl;
        cin >> answer2;
        answer2 = tolower(answer2);
        if (answer2 != 'y' && answer2 != 'n') {
          cout << "That is not a valid response. Please try again" << endl;
        }
      }
        if (answer2 == 'y') {
          directory[testChar].changeInfo();
        }
      }
      else {
        testChar = -1;
      }
    }
  }
  return testChar;
}

//Validates input ID for car categories, returns vector reference
int Inventory::carSelection(vector<Car>& input, char cVal) {
  int choice, test = -1, quitVal = -1, carChosen, pleasework = 0;
  char decision1 = '\0', decision2 = '\0';

  while(test < 0) {
  cout << endl << "Enter the ID number of the vehicle you are interested in: ";
  cin >> choice;
  for (unsigned int i = 0; i < input.size(); i++) {
    if (choice == input[i].getID()) {
      test = 1;
      cout << endl << "A representative will bring you the ";
      cout << "keys for a test drive" << endl;
      carChosen = i;
      test = 0;
    }
  }
  //This part actually does work, it appears to not take input but when it
  //prints out the inventory again, it looks as if nothing happened
  if (test == -1) {
    cout << endl << "That is not a valid Vehicle ID number. Please try again";
    cout << endl << endl;
    printInventory(cVal);
  }
}
  if (cVal == 'c') {

    if (decision2 == 'n') {
      decision2 = '\0';
      return quitVal;
    }
    if (pleasework == 0) {
      while(decision1 != 'y' && decision1 != 'n') {
        cout << "Did you like the car during your test drive?" << endl;
        cout << "Enter y for yes or n for no: ";
        cin >> decision1;
        decision1 = tolower(decision1);
        if (decision1 != 'y' && decision1 != 'n') {
          cout << "That is not a valid response. Please try again" << endl;
        }
      }
  }
    if (decision1 == 'y') {
      pleasework = 200;
      cout << endl << endl << "Excellent! Thank you for your business" << endl;
      cout << "A sales representative will be with you shortly" << endl;
      return carChosen;
    }
    if (decision1 == 'n') {
      decision1 = '\0';
      while(decision2 != 'y' && decision2 != 'n') {
        cout << "We're sorry to hear that. Would you like to see other ";
        cout << "available vehicles?" << endl;
        cout << "Enter y for yes or n for no: ";
        cin >> decision2;
        decision2 = tolower(decision2);
        if (decision1 != 'y' && decision1 != 'n') {
          cout << "That is not a valid response. Please try again" << endl;
        }
      }
      if (decision2 == 'n') {
        return quitVal;
      }
      if (decision2 == 'y') {
        decision2 = '\0';
        printInventory(cVal);
        carSelection(input, cVal);
      }
  }
  }
  if (cVal == 'r') {
    cout << "Please head over to the customer service desk to fill ";
    cout << "out the remaining paperwork for your rental" << endl;
    return carChosen;
  }
  return quitVal;
}

//Validates input ID for truck, returns vector reference
int Inventory::truckSelection(vector<Truck>& input, char cVal) {
  int choice, test = -1, quitVal = -1, carChosen, pleasework = 0;
  char decision1 = '\0', decision2 = '\0';

  while(test < 0) {
  cout << endl << "Enter the ID number of the vehicle you are interested in: ";
  cin >> choice;
  for (unsigned int i = 0; i < input.size(); i++) {
    if (choice == input[i].getID()) {
      test = 1;
      cout << endl << "A representative will bring you the ";
      cout << "keys for a test drive" << endl;
      carChosen = i;
      test = 0;
    }
  }
  //This part actually does work, it appears to not take input but when it
  //prints out the inventory again, it looks as if nothing happened
  if (test == -1) {
    cout << endl << "That is not a valid Vehicle ID number. Please try again";
    cout << endl << endl;
    printInventory(cVal);
  }
}
  if (cVal == 't') {

    if (decision2 == 'n') {
      decision2 = '\0';
      return quitVal;
    }
    if (pleasework == 0) {
      while(decision1 != 'y' && decision1 != 'n') {
        cout << "Did you like the car during your test drive?" << endl;
        cout << "Enter y for yes or n for no: ";
        cin >> decision1;
        decision1 = tolower(decision1);
        if (decision1 != 'y' && decision1 != 'n') {
          cout << "That is not a valid response. Please try again" << endl;
        }
      }
  }
    if (decision1 == 'y') {
      pleasework = 200;
      cout << endl << endl << "Excellent! Thank you for your business" << endl;
      cout << "A sales representative will be with you shortly" << endl;
      return carChosen;
    }
    if (decision1 == 'n') {
      decision1 = '\0';
      while(decision2 != 'y' && decision2 != 'n') {
        cout << "We're sorry to hear that. Would you like to see other ";
        cout << "available vehicles?" << endl;
        cout << "Enter y for yes or n for no: ";
        cin >> decision2;
        decision2 = tolower(decision2);
        if (decision1 != 'y' && decision1 != 'n') {
          cout << "That is not a valid response. Please try again" << endl;
        }
      }
      if (decision2 == 'n') {
        return quitVal;
      }
      if (decision2 == 'y') {
        decision2 = '\0';
        printInventory(cVal);
        truckSelection(input, cVal);
      }
    }
  }
  return quitVal;
}

//Menu function used to call other functions
void Inventory::displayMenu(int currentGuest) {
  int vehicleChosen;
  char choice;
  if (currentGuest == -1) {
    displayGreeting();
    currentGuest = addCustomer();
  }
  choice = optionDisplay();
  printInventory(choice);
  switch (choice) {
    case 'c':
        vehicleChosen = carSelection(carSale, choice);
        if (vehicleChosen != -1) {
          removeInventory(carSale[vehicleChosen].getID());
        }
    break;
    case 'r':
      if (ageCheck(directory[currentGuest].getAge()) == true) {
        vehicleChosen = carSelection(carRental, choice);
        if (vehicleChosen != -1) {
          removeInventory(carRental[vehicleChosen].getID());
        }
      }
      else {
        cout << "I'm sorry, you must be 25 to rent a car." << endl;
        cout << "Please select another option" << endl << endl;
        displayMenu(currentGuest);
      }
    break;
    case 't':
      vehicleChosen = truckSelection(truckSale, choice);
      if (vehicleChosen != -1) {
        removeInventory(truckSale[vehicleChosen].getID());
      }
    break;
  }
cout << "Thank you so much for stopping by! Come back soon!" << endl << endl;
}

//Reads in people from file to remove from directory
void Inventory::removeNames(ifstream& inFile) {

  while (!inFile.eof()) {
    Person newPerson(inFile);
    if(newPerson.getAge() < 1000 && newPerson.getAge() > -1000) {
      for (unsigned int i = 0; i < directory.size(); i++) {
        if (directory[i].getLast() == newPerson.getLast()) {
                removeCustomer(directory[i].getID());
          }
        }
      }
  }
}
