#include "Date.h"
#include "Camper.h"

using namespace std;

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

void Camper::print()
{
    cout << "Camper Info: " << endl;
    cout << "Name: " << name << endl;
    cout << "Number Plate: " << plate_number << endl;
    cout << "Number of People" << num_people << endl;
    cout << "Check in: ";
    check_in.print();
    cout << "Check out: ";
    check_out.print();
    cout << "------------------------------" << endl;
}
