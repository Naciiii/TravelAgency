#include "hotelbooking.h"

HotelBooking::HotelBooking(string hotelId, double hotelPrice, string hotelFromDate, string hotelToDate, string hotel, string town, string type)
    :Booking(hotelId,hotelPrice,hotelFromDate,hotelToDate), hotel(hotel), town(town), type(type)
{

}

string HotelBooking::showDetails()
{
 return "Hotelreservierung im " + hotel + " in " + town + " vom " + getFromDate() + " bis zum " + getToDate() + " Preis: "+ std::to_string(getPrice())+" Euro "+ "\n";

}
