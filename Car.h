

#ifndef CAR_H
#define CAR_H
#include <fstream>
#include <iostream>
#include "Vehicle.h"



class Car : public Vehicle
{
  private:
      bool rentable;
      bool available;

  public:
      Car();
      Car(ifstream&);
      void isRentable();
      void printInfo(ofstream& out);
      void printInfo();
      bool getRentable();
      virtual ~Car() {}
};

#endif
