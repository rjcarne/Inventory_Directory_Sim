/*************************
* Ryan Carney
* CPSC 1020 Sm19
* rjcarne
*************************/

#include "Inventory.h"

using namespace std;

int main(int argc, char* argv[]) {
	//Open and check for file input
	if (argc != 4) {
		cout << "Not enough command line arguments" << endl;
		return -1;
	}
	ofstream outCustomer("customerOut100.txt");
		if (outCustomer.fail()) {
				cout << "Problem with directory output" << endl;
				return -1;
				}
	ofstream outInventory("vehicleOut100.txt");
		if (outInventory.fail()) {
				cout << "Problem with inventory output" << endl;
				return -1;
				}
	ofstream outEC("customerOutEC1.txt");
		if (outEC.fail()) {
				cout << "Problem with extra credit 1 output" << endl;
				return -1;
				}
	ifstream inVehicles(argv[1]);
		if (inVehicles.fail()) {
				cout << "Problem with vehicle input" << endl;
				return -1;
				}
	ifstream inPeople(argv[2]);
		if (inPeople.fail()) {
				cout << "Problem with directory input" << endl;
				return -1;
				}

	//creates inventory class
	Inventory Inventory;
	int test = -1;
	//reads input files into directory and inventory
	Inventory.readInventory(inVehicles);
	Inventory.readDirectory(inPeople);
	inVehicles.close();
	inPeople.close();

//Starter menu. 1 to pretend to be a customer. 2 to test the remove file names
//for extra credit. 3 to end the program
	while (test < 1 || test > 2) {
			cout << endl << "Enter 1 to sign in as a customer or" << endl;
			cout << "Enter 2 to input file of contacts to ";
			cout << "remove from directory or" << endl;
			cout << "Enter 3 to quit program: " << endl;
			cin >> test;
			if (test == 1) {
					Inventory.displayMenu(-1);
					cout << endl << "Printing current directory to customerOut100.txt";
					cout << endl;
					Inventory.printDirectory(outCustomer);
					cout << endl << "Printing current vehicle inventory to ";
					cout << "vehicleOut100.txt";
					cout << endl;
					Inventory.printInventory(outInventory);
			}
			if (test == 2) {
					cout << endl << "Printing current vehicle inventory to ";
					cout << "vehicleOut100.txt";
					cout << endl;
					Inventory.printInventory(outInventory);
					cout << endl << "Printing current directory to ";
					cout << "customerOut100.txt" << endl;
					Inventory.printDirectory(outCustomer);
					cout << "Removing names" << endl;
					ifstream inNamestoremove(argv[3]);
					if (inNamestoremove.fail()) {
							cout << "Problem with file input of names to remove" << endl;
					}
					Inventory.removeNames(inNamestoremove);
					inNamestoremove.close();
					cout << endl << "Printing changed directory to ";
					cout << "customerOutEC1.txt" << endl;
					Inventory.printDirectory(outEC);

			}
			if (test == 3) {
					cout << "Thank you. Goodbye" << endl;
			}
			if (test < 1 || test > 3) {
					cout << "Please select a valid command" << endl;
			}
	}
}
