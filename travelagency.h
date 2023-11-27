#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H

#include<iostream>
#include<vector>
#include"booking.h"


using namespace std;

class TravelAgency
{
public:
    TravelAgency();
    ~TravelAgency();

    string convertToString(char *arrayOfChars, int size);
    void readFile();
    void readBinaryFile();
    string type;


    //string getType() const;

    void flightInfoControll();

    void asdasd();

private:
    vector<Booking *> Bookings;


};

#endif // TRAVELAGENCY_H
