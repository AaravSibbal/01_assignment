#include "Camper.h"

using namespace std;

/**
 * constructors
 */

Camper::Camper()
{
    Date check_in_date = Date();
    Date check_out_date = Date(1901, 1, 5);

    this->name = "john smith";
    this->plate_number = "abcd1234";
    this->num_people = 1;
    this->check_in = check_in_date;
    this->check_out = check_out_date;
}

Camper::Camper(const string& name, const string& plate_number, int& num_people,
               Date& check_in, Date& check_out){
                this->name = name;
                this->plate_number = plate_number;
                this->check_in = check_in;
                this->check_out = check_out;
                this->num_people = num_people;
}

/**
 * getters
 */
string Camper::getName()
{
    return name;
}

string Camper::getPlateNumber()
{
    return plate_number;
}

int Camper::getNumPeople()
{
    return num_people;
}

Date Camper::getCheckIn()
{
    return check_in;
}

Date Camper::getCheckOut()
{
    return check_out;
}

/**
 * setters
 */

void Camper::setName(const string& name)
{
    this->name = name;
}

void Camper::setPlateNumber(const string& plate_number)
{
    this->plate_number = plate_number;
}

void Camper::setNumPeople(int& num_people)
{
    if (num_people < 1)
    {
        cout<<"number of people can't be less than 1"<<endl;
        return;
    }

    this->num_people = num_people;
}

void Camper::setCheckIn(Date& check_in){
    this->check_in = check_in;
}

void Camper::setCheckOut(Date& check_out){
        this->check_out = check_out;
}

/**
 * print function
 */
void Camper::print()
{
    cout << "Camper Info: " << endl;
    cout << "Name: " << name << endl;
    cout << "Number Plate: " << plate_number << endl;
    cout << "Number of People: " << num_people << endl;
    cout << "Check in: ";
    check_in.print();
    cout << "Check out: ";
    check_out.print();
    cout << "------------------------------" << endl;
}
