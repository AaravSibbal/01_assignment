#ifndef CAMPER_H
#define CAMPER_H

#include <string>
#include "Date.h"
using namespace std;

class Camper
{
private:
    string name;
    string plate_number;
    int num_people;
    Date check_in;
    Date check_out;

    /* data */
public:
    // constructors
    Camper();
    Camper(const string &name, const string &plate_number,
           int &num_people, Date &check_in, Date &check_out);

    // getters
    string getName();
    string getPlateNumber();
    int getNumPeople();
    Date getCheckIn();
    Date getCheckOut();

    // setters
    void setName(const string &name);
    void setPlateNumber(const string &plate_number);
    void setNumPeople(int &num_people);
    void setCheckIn(Date &check_in);
    void setCheckOut(Date &check_out);

    // other functions
    // TODO: implement the functions below
    bool is_num_people_valid(int &num_people);
    bool are_dates_valid(Date &check_in, Date &check_out);

    void print();
};

#endif