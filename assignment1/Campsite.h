#ifndef CAMPSITE_H
#define CAMPSITE_H


#include <string>
#include "Category.h"
#include "Camper.h"
#include "defs.h"
#include "Date.h"

using namespace std;

class Campsite
{
private:
    int site_number;
    cat::Category Category;
    string description;
    int max_people;
    double price_per_day;
    int camper_arr_len;
    Camper campers_arr[MAX_ARRAY];

    void removeElem(int& idx);
    /* data */
public:
    
    /**
     *  Constructors
     */

    Campsite();
    Campsite(int site_number, cat::Category Category, const string description, int max_people, double price_per_day);
    
    
    /**
     * Getters
     */

    int getSiteNumber();
    cat::Category getCategory();
    string getDescription();
    int getMaxPeople();
    double getPricePerDay();

    /**
     * setters
     */
    void setSiteNumber(int& site_number);
    
    void setCategory(cat::Category& Category);
    void setDescription(const string& description);
    void setMaxPeople(int& max_people);
    void setPricePerDay(double& price_per_day);

    /**
     * other functions
     */

    bool addCamper(const string& name, const string& plate_number, int& num_people,Date& check_in, Date& check_out);
    void removeElem(int& idx);
    bool addElem(int& idx, Camper& c);
    void setElem(int& idx, Camper& c);
    Camper getElem(int& idx);
    bool isIdxValid(int& idx);
    bool removeCamper(const string& name);
    int findCamperIdx(Camper& c);
    void print();
    void printCampers();
    void printCamper(Date& date);
    
};



#endif