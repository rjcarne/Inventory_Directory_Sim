/*************************
* Ryan Carney
* CPSC 1020 Sm19
* rjcarne
*************************/

#include "Date.h"

using namespace std;

//Default constructor
Date::Date() : month(1), day(1), year(2000){
}

//Regular constructor
Date::Date(int month, int day, int year) : month(month), day(day), year(year) {
}

//sets month
void Date::setMonth(int month) {
        this->month = month;
}

//sets day
void Date::setDay(int day) {
        this->day = day;
}

//sets year
void Date::setYear(int year) {
        this->year = year;
}

//returns month
int Date::getMonth() {
        return month;
}

//returns day
int Date::getDay() {
        return day;
}

//returns year
int Date::getYear() {
        return year;
}

//outputs date to file
void Date::printDate(ofstream& outFile) {
        outFile << month << "/" << day << "/" << year << endl;
}

//outputs date to terminal
void Date::printDate() {
        cout << month << "/" << day << "/" << year << endl;
}

//Uses current time + math to find age. Made a day counter function
int Date::getAge() {
        int age = 0;

        time_t t = time(0);
        struct tm * now = localtime( &t );

        age = (now->tm_year + 1900) - year;
        if (dayCounter(month, day) >= dayCounter(now->tm_mon + 1,
            now->tm_mday +1)) {
                age--;
        }
        return age;
}

//takes total days in the year that have passed up to a given date to be used
//for comparison
int Date::dayCounter(int month, int day) {
        int total = 0;
        switch (month) {
        case 2:
                total += 31;
                break;
        case 3:
                total += 59;
                break;
        case 4:
                total += 90;
                break;
        case 5:
                total += 120;
                break;
        case 6:
                total += 151;
                break;
        case 7:
                total += 181;
                break;
        case 8:
                total += 212;
                break;
        case 9:
                total += 243;
                break;
        case 10:
                total += 273;
                break;
        case 11:
                total += 304;
                break;
        case 12:
                total += 334;
                break;
        }
        total += day;
        return total;
}
