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
    int no_of_campers;
    Camper campers_arr[MAX_ARRAY];
    /* data */
public:
    
    /**
     *  Constructors
     */

    Campsite();
    Campsite(int& site_number, cat::Category& Category, const string& description, 
                int& max_people, double& price_per_day);
    
    
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
    
    // TODO: figure out wheater I can actually set the category because I alost dont think so
    // void setCategory(cat::Category& Category);
    void setDescription(const string& description);
    void setMaxPeople(int& max_people);
    void setPricePerDay(double& price_per_day);

    /**
     * other functions
     */

    //     string name;
    // string plate_number;
    // int num_people;
    // Date check_in;
    // Date check_out;
    bool addCamper(const string& name, const string& plate_number, int& num_people,
                    Date& check_in, Date& check_out);
    bool removeCamper(const string& name);


};



#endif