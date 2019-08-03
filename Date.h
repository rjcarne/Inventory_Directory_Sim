/*************************
* Ryan Carney
* CPSC 1020 Sm19
* rjcarne
*************************/

#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

class Date
{
  private:
    int month;
    int day;
    int year;


  public:
    Date();
    Date(int, int, int);
    void setMonth(int);
    void setDay(int);
    void setYear(int);
    int getMonth();
    int getDay();
    int getYear();
    void printDate();
    void printDate(ofstream&);
    int getAge();
    int dayCounter(int month, int day);

};
#endif
