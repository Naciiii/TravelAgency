#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H

#include "booking.h"

class FlightBooking : public Booking
{
public:
    FlightBooking(string flightId, double flightPrice, string flightDateFrom,string flightToDate, string fromDestination, string toDestination, string airline, string type);
    ~FlightBooking() override ;


    string showDetails() override;

    string getFromDestination() const;
    void setFromDestination(const string &value);

    string getToDestination() const;
    void setToDestination(const string &value);

    string getAirline() const;
    void setAirline(const string &value);

    string getType() const;

private:
    string fromDestination;
    string toDestination;
    string airline;
    string type;
};

#endif // FLIGHTBOOKING_H
