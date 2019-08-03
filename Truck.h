/*************************
* Ryan Carney
* CPSC 1020 Sm19
* rjcarne
*************************/

#ifndef TRUCK_H
#define TRUCK_H
#include <iostream>
#include <fstream>
#include "Vehicle.h"


class Truck : public Vehicle
{
  private:

    string bedType;

  public:
    Truck();
    Truck(ifstream& inFile);
    void printInfo(ofstream&);
    void printInfo();
};

#endif
