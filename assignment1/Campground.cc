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

void Campground::addCampsite(int site_number, cat::Category Category, const string description,
     int max_people, double price_per_day){
    if(campsite_arr_len == MAX_ARRAY){
        cout<<"Error: Campsite couldn't be added, Max array size reached"<<endl;
        return;
    }

    Campsite c = Campsite(site_number, Category, description, max_people, price_per_day);
    for(int i=0; i<campsite_arr_len; i++){
        if(campsite_arr[i].getSiteNumber() == c.getSiteNumber()){
            cout<<"Error: Campsite couldn't be added, site number was not unique"<<endl;
            return;
        }
    }

    campsite_arr[campsite_arr_len] = c;
    campsite_arr_len++;
    cout<<"Campsite was added successfully"<<endl;
}

void Campground::removeCampsite(int site_number){
    if(campsite_arr_len == 0){
        cout<<"Error: removing campsite operation failed, there are no campsites in the campground"<<endl;
        return;
    }
    for(int i=0; i<campsite_arr_len; i++){
        if(campsite_arr[i].getSiteNumber() == site_number){
            removeElem(i);
            return;
        }
    }

    cout<<"Error: removing operation failed, there are no sites with the same site number"<<endl;
}

void Campground::removeElem(int& idx){
    if(idx < 0 || idx >= campsite_arr_len){
        cout<<"Error: removing operation failed, index out of range"<<endl;
        return;
    }

    if(idx == campsite_arr_len-1){
        cout<<"Campsite:"<<campsite_arr[idx].getSiteNumber()<<" has been removed successfully"<<endl;
        campsite_arr_len--;
        return;
    }
    for(int i=idx; i<campsite_arr_len-1; ++i){
        campsite_arr[i] = campsite_arr[i+1];
    }

    campsite_arr_len--;
    cout<<"Campsite:"<<campsite_arr[idx].getSiteNumber()<<" has been removed successfully"<<endl;

}


void Campground::addCamper(int site_number, const string& name, 
    const string& plate_number, int& num_people, Date& check_in, Date& check_out){

        for(int i=0; i<campsite_arr_len; i++){
            if(site_number == campsite_arr[i].getSiteNumber()){
                if(campsite_arr[i].addCamper(name, plate_number, num_people, check_in, check_out)){
                    cout<<"The Camper: "<<name<<" was added to the site: "<<site_number<<" successfully"<<endl;
                    return;
                }
                else{
                    cout<<"There was no available spots for the camper on the campsite"<<endl;
                    return;
                }
            }
        }

        cout << "Error: The site number that is given does not exist"<<endl;
}

void Campground::removeCamper(int site_number, const string& name){
    for(int i=0; i<campsite_arr_len; i++){
        if(campsite_arr[i].getSiteNumber() == site_number){
            campsite_arr[i].removeCamper(name);
            return;
        }
    }   
    cout<<"Error: remove camper operation failed, the campsite with the site number "<<site_number<<" does not exist"<<endl;

}
