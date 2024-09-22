#include "Campground.h"


/**
 * print functions
 */
void Campground::printCampsites(){
    for(int i=0; i<campsite_arr_len; i++){
        campsite_arr[i].print();
    }
}

void Campground::printCampers(int site_number){
    Campsite c = getCampsite(site_number);
    c.printCampers();
}

Campsite Campground::getCampsite(int& site_number){
    for(int i=0; i<campsite_arr_len; i++){
        if(campsite_arr[i].getSiteNumber() == site_number){
            return campsite_arr[i];
        }
    }
}

void Campground::printCampsitesByCategory(cat::Category Category){
    for(int i=0; i<campsite_arr_len; i++){
        if(campsite_arr[i].getCategory() == Category){
            campsite_arr[i].print();
        }
    }
}

void Campground::printCampers(Date& date){
    // TODO: make this function
}

/**
 * other function
 */
void Campground::addCampsite(Campsite& c){
    for(int i=0; i<campsite_arr_len; i++){
        
    }
}