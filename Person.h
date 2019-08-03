/*************************
* Ryan Carney
* CPSC 1020 Sm19
* rjcarne
*************************/

#ifndef PERSON_H
#define PERSON_H

#include "Address.h"
#include "Date.h"
#include "Functions.h"
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>

class Person
{
  private:

    string last;
    string first;
    string email;
    Address address;
    Date bday;
    int customerID;
    static int customerCount;

  public:

    Person();
    Person(string, string, string, int, string, string, string, int,
            int, int, int);
    Person(ifstream&);
    Address getAddress();
    void setPerson(string last, string first, string email, int house,
                    string street, string city, string state, int zip,
                    int month, int day, int year);
    string getLast();
    string getFirst();
    string getEmail();
    int getAge();
    int getID();
    void printInfo(ofstream&);
    void printInfo();
    void changeInfo();
};

#endif
