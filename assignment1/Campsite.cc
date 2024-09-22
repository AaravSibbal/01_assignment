#include "Campsite.h"

/**
 * Contructors
 */

Campsite::Campsite(){
    site_number = 0;
    Category = cat::rv_site;
    description = "this is the default description";
    max_people = 1;
    price_per_day = 20;
    camper_arr_len = 0;
}

Campsite::Campsite(int site_number, cat::Category Category, const string description, int max_people, double price_per_day){
            this->site_number = site_number;
            this->Category = Category;
            this->description = description;
            this->max_people = max_people;
            this->price_per_day = price_per_day;
            this->camper_arr_len = 0;
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
    for(int i=0; i<camper_arr_len; ++i){
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
    for(int i=0; i<camper_arr_len; ++i){
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
        if(camper_arr_len== MAX_ARRAY){
            return false;
        }

        Camper c = Camper(name, plate_number, num_people, check_in, check_out);
        int idx = findCamperIdx(c);
        if(idx == -1){
            return false;
        }
        addElem(idx, c);
        camper_arr_len++;     
        return true;  
}

bool Campsite::removeCamper(const string& name){
    int idx = -1;
    
    for(int i=0; i<camper_arr_len; ++i){
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
 * we are checking at each element for:
 * 1. if there is a range clash:
 *      if yes we return -1
 *      else we do further checks
 * 2. if we find am element that has a check in date more than the elem we are
 *  trying to add.
 *      if yes we return the idx we are on
 */
int Campsite::findCamperIdx(Camper& c){
    int idx  = -1;
    Date check_in = c.getCheckIn();
    Date check_out = c.getCheckOut();

    for(int i=0; i<camper_arr_len; i++){
        Date temp_check_in = campers_arr[i].getCheckIn();
        Date temp_check_out = campers_arr[i].getCheckOut();

        if(!isValidRange(check_in, check_out, temp_check_in, temp_check_out)){
            return -1;
        }

        if(check_in.lessThan(temp_check_in)){
            return i;
        }
        
    }

    return camper_arr_len;
}

bool isValidRange(Date& check_in, Date& check_out, Date& temp_check_in, Date& temp_check_out){
    if(temp_check_in.lessThan(check_in) && check_in.lessThan(temp_check_out)){
        return false;
    }
    if(temp_check_in.equals(check_in)){
        return false;
    }
    if(temp_check_in.lessThan(check_out) && check_out.lessThan(temp_check_out)){
        return false;
    }

    return true;
}

bool Campsite::addElem(int& idx, Camper& c){
    if(camper_arr_len == MAX_ARRAY){
        return false;
    }
    if(idx == camper_arr_len){
        campers_arr[camper_arr_len] = c;
        return true;
    }

    for(int i = camper_arr_len-1; i>idx-1; i--){
        int idx = i+1;
        setElem(idx, campers_arr[i]);
    }



    setElem(idx, c);
    return true;
}

void Campsite::setElem(int& idx, Camper& c){
    campers_arr[idx] = c;
}


Camper Campsite::getElem(int& idx){
    return campers_arr[idx];    
}

bool Campsite::isIdxValid(int& idx){
    if(idx < 0){
        return false;
    }else if(idx >= camper_arr_len){
        return false;
    }

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
    int loop_len = camper_arr_len - idx - 1;
    for(int i = idx; i<camper_arr_len-1; ++i){
        campers_arr[i] = campers_arr[i+1];
    }

    camper_arr_len--;
}