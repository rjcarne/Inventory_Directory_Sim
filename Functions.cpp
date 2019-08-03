/*************************
* Ryan Carney
* CPSC 1020 Sm19
* rjcarne
*************************/

#include "Functions.h"
#include "Inventory.h"

using namespace std;

//just text
void displayGreeting() {
  cout << endl << "Welcome to Jon Snow's Car and Truck Showroom!" << endl;
  cout << "If the White Walkers had seen our prices, they wouldn't have ";
  cout << "been walking!" << endl;
  cout << endl << endl << "Please sign in to begin the process" << endl;
  cout << "None of your information will be sold" << endl;
  cout << "Thank you for visiting our showroom!" << endl << endl;
}

//part of the menu text
char optionDisplay() {
  int firstChoice = -1, secondChoice = -1;
  cout << endl << "Would you like to see a list of cars or trucks?" << endl;
  cout << "Enter 1 for cars, 2 for trucks, or 3 to quit to menu: ";
  cin >> firstChoice;
  if (firstChoice == 1) {
    cout << endl << "Are you interested in buying or renting a car?" << endl;
    cout << "Enter 1 to see a list of cars for sale," << endl;
    cout << "Enter 2 to see a list of cars for rent: " << endl;
    cin >> secondChoice;
    if (secondChoice == 1) {
      return 'c';
    }
    if (secondChoice == 2) {
      return 'r';
    }
  }
  if (firstChoice == 2) {
    return 't';
  }
  if (firstChoice == 3) {
    return 'q';
  }
cout << "Something has gone wrong with your choices. Please select again";
cout << endl;
return optionDisplay();
}

//checks to see if a person is old enough to rent a car
bool ageCheck(int age) {
  if (age < 25) {
    return false;
  }
  else {
    return true;
  }
}

//Tests to make sure birthday is possible
int testBday(int month, int day, int year){
  if (month < 1 || month > 12) {
    cout << "The month you entered is not valid on this planet,";
    cout << " please try again" << endl;
    return 0;
  }
  if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
      || month == 10 || month == 12) {
    if (day > 31 || day < 1) {
      cout << "That day isn't possible, please try again" << endl;
      return 0;
    }
  }
  if (month == 4 || month == 6 || month == 9 || month == 11) {
    if (day > 30 || day < 1) {
      cout << "That day isn't possible, please try again" << endl;
      return 0;
    }
  }
  if (month == 2) {
    if (day > 29 || day < 1) {
      cout << "That day isn't possible, please try again" << endl;
      return 0;
    }
  }
  return 1;
}
