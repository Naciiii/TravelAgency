#include "flightbooking.h"



FlightBooking::FlightBooking(string flightId, double flightPrice, string flightDateFrom,string flightToDate, string fromDestination, string toDestination, string airline,string type)
    :Booking(flightId,flightPrice,flightDateFrom,flightToDate),fromDestination(fromDestination), toDestination(toDestination), airline(airline), type(type)

{


}

FlightBooking::~FlightBooking()
{

}



string FlightBooking::showDetails()
{

     return "Flugbuchunng von " + fromDestination + " nach " + toDestination + " mit " + airline + " am " + fromDate + "." + " Preis: "
             + std::to_string(getPrice()) + " Euro "+"\n";

}

string FlightBooking::getFromDestination() const
{
    return fromDestination;
}

void FlightBooking::setFromDestination(const string &value)
{
    fromDestination = value;
}

string FlightBooking::getToDestination() const
{
    return toDestination;
}

void FlightBooking::setToDestination(const string &value)
{
    toDestination = value;
}

string FlightBooking::getAirline() const
{
    return airline;
}

void FlightBooking::setAirline(const string &value)
{
    airline = value;
}

string FlightBooking::getType() const
{
    return type;
}
