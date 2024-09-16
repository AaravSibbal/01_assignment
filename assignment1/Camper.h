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
    Camper(const string& name, const string& plate_number, 
    int& num_people, Date& check_in, Date& check_out);

    // getters
    string getName();
    string getPlateNumber();
    int getNumPeople();
    Date getCheckIn();
    Date getCheckOut();

    // setters
    void setName();
    void setPlateNumber();
    bool setNumPeople();
    bool setCheckIn();
    bool setCheckOut();
    
    // other functions
    bool is_num_people_valid(int& num_people);
    bool are_dates_valid(Date& check_in, Date& check_out);

    void print();

};



#endif