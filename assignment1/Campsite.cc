#include "Campsite.h"
#include <optional>

/**
 * Contructors
 */

Campsite::Campsite(){
    site_number = 0;
    Category = cat::rv_site;
    description = "this is the default description";
    max_people = 1;
    price_per_day = 20;
    no_of_campers = 0;
}

Campsite::Campsite(int& site_number, cat::Category& Category, const string& description, int& max_people, double& price_per_day){
            this->site_number = site_number;
            this->Category = Category;
            this->description = description;
            this->max_people = max_people;
            this->price_per_day = price_per_day;
            this->no_of_campers = 0;
}


/**
 * getter functions
 */
int Campsite::getSiteNumber(){
    return site_number;
}

cat::Category Campsite::getCategory(){
    return Category;
}

string Campsite::getDescription(){
    return description;
}

int Campsite::getMaxPeople(){
    return max_people;
}

double Campsite::getPricePerDay(){
    return price_per_day;
}

/**
 * setters
 */

void Campsite::setSiteNumber(int& site_number){
    this->site_number = site_number;
}

void Campsite::setCategory(cat::Category& Category){
    this->Category = Category;
}

void Campsite::setDescription(const string& description){
    this->description = description;
}

void Campsite::setMaxPeople(int& max_people){
    this->max_people = max_people;
}

void Campsite::setPricePerDay(double& price_per_day){
    this->price_per_day = price_per_day;
}

/**
 * Print Functions
 */

void Campsite::print(){
    cout<<"Site Number: "<<site_number<<endl;
    cout<<"Category: "<<cat::categoryToString(Category)<<endl;
    cout<<"Description: "<<description<<endl;
    cout<<"Max People: "<<max_people<<endl;
    cout<<"Price Per Day: "<<price_per_day<<endl;
}

void Campsite::printCampers(){
    for(int i=0; i<no_of_campers; ++i){
        campers_arr[i].print();
    }
}


/**
 * basically doing a check of
 * if the check in date is less than the given date or
 * check in date is equal to the date
 * and if the date is check out date is more than date or
 * not equalling the check out date
 */
void Campsite::printCamper(Date& date){
    for(int i=0; i<no_of_campers; ++i){
        if((campers_arr[i].getCheckIn().lessThan(date) || 
            campers_arr[i].getCheckIn().equals(date)) 
        && (!campers_arr[i].getCheckOut().lessThan(date)) ||
            (!campers_arr[i].getCheckOut().equals(date))
        ){

            campers_arr[i].print();
            return;

        }
    }
}

/**
 * Other Functions
 */

bool Campsite::addCamper(const string& name, const string& plate_number, 
    int& num_people,Date& check_in, Date& check_out){
        if(no_of_campers == MAX_ARRAY){
            return false;
        }
        //TODO: Campers needs to be sorted by date while making sure there is only one camper at one date

        Camper c = Camper(name, plate_number, num_people, check_in, check_out);
        campers_arr[no_of_campers] = c;
        no_of_campers++;     
        return true;  
}

bool Campsite::removeCamper(const string& name){
    int idx = -1;
    
    for(int i=0; i<no_of_campers; ++i){
        if(campers_arr[i].getName() == name){
            idx = i;
        }
    }

    if(idx == -1){
        return false;
    }

    removeElem(idx);

    return true;
}


/**
 * the last value of the array is now not references
 * thus it is a garbage value and it wont be accessed
 * unless there is a new value added at that index.
 * and because we already have that space for the length of
 * the program this shouldn't cause memory leak issues.
 */
void Campsite::removeElem(int& idx){
    int loop_len = no_of_campers - idx - 1;
    for(int i = idx; i<no_of_campers-1; ++i){
        campers_arr[i] = campers_arr[i+1];
    }

    no_of_campers--;
}