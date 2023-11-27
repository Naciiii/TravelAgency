#include "booking.h"

Booking::Booking(string id, double price, string fromDate, string toDate)
{

    this->id = id;
    this->price = price;
    this->fromDate = fromDate;
    this->toDate = toDate;



}

Booking::~Booking()
{

}

string Booking::getId() const
{
    return id;
}

double Booking::getPrice() const
{
    return price;
}

string Booking::getFromDate() const
{
    return fromDate;
}

string Booking::getToDate() const
{
    return toDate;
}

void Booking::setPrice(double value)
{
    price = value;
}

void Booking::setFromDate(const string &value)
{
    fromDate = value;
}

void Booking::setToDate(const string &value)
{
    toDate = value;
}
