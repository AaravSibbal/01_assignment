#ifndef CAMPGROUND_H
#define CAMPGROUND_H

#include "Campsite.h"
#include "Category.h"

using namespace std;

class Campground{
    private:
        Campsite campsite_arr[MAX_ARRAY];
        int campsite_arr_len;

    public:
        /**
         * print functions
         */

        void printCampsites();
        void printCampers(int site_number);
        void printCampers(Date& date);
        void printCampsitesByCategory(cat::Category Category);

        /**
         * other functions
         */
        void addCampsite(Campsite& c);
        void removeCampsite(int& site_number);

        void addCamper(int& site_number, const string& name, 
        const string& plate_number, int& num_people, Date& check_in, Date& check_out);
        void removeCamper(int& site_number, const string& name);
        Campsite getCampsite(int& site_number);
};


#endif