

#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Address
{
private:
  int house;
  string street;
  string city;
  string state;
  int zip;

public:

  Address ();
  Address(int, string, string, string, int);
  void setAddress(int, string, string, string, int);
  void printAddress(ofstream&);
  void printAddress();
};

#endif
