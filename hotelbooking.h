#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H

#include "booking.h"

class HotelBooking : public Booking
{
public:
    HotelBooking(string id, double price, string fromDate, string toDate, string hotel, string town, string type);

    string showDetails();

private:
    string hotel;
    string town;
    string type;
};

#endif // HOTELBOOKING_H
