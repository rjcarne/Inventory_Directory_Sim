/*************************
* Ryan Carney
* CPSC 1020 Sm19
* rjcarne
*************************/

#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include "Car.h"
#include "Vehicle.h"
#include "Truck.h"
#include <vector>
#include "Person.h"
#include <cctype>
#include "Functions.h"



class Inventory
{
  private:

    vector<Car> carRental;
    vector<Car> carSale;
    vector<Truck> truckSale;
    vector<Person> directory;

  public:

    void addInventory(Car&);
    void addInventory(Truck&);
    void removeInventory(int);
    void printInventory(ofstream&);
    void printInventory(char);
    void printDirectory(ofstream&);
    void readDirectory(ifstream&);
    void readInventory(ifstream&);
    int addCustomer();
    int carSelection(vector<Car>&, char);
    int truckSelection(vector<Truck>&, char);
    void removeCustomer(int);
    void displayMenu(int);
    int findPerson(string, string, string);
    void removeNames(ifstream&);
    virtual ~Inventory() {}
};

#endif
