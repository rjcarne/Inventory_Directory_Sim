/*************************
* Ryan Carney
* CPSC 1020 Sm19
* rjcarne
*************************/

#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

class Vehicle
{
  protected:

    string type;
    string make;
    string model;
    int year;
    string color;
    double salesPrice;
    int miles;
    string condition;
    int id;
    static int inventoryCount;

  public:

    Vehicle();
    Vehicle(ifstream&);
    void printInfo(ofstream&);
    void printInfo();
    int getYear();
    int getMiles();
    string getCondition();
    void addInventory();
    int getCount();
    int getID();
};

#endif
