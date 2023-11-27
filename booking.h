#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
#include <string>

using namespace std;

class Booking
{
public:
    Booking(string id, double price, string fromDate, string toDate);

    virtual ~Booking();
    virtual string showDetails() = 0;

    string getId() const;

    double getPrice() const;

    string getFromDate()const;

    string getToDate() const;

    void setPrice(double value);

    void setFromDate(const string &value);

    void setToDate(const string &value);

protected:
    string id;
    double price;
    string fromDate;
    string toDate;
};

#endif // BOOKING_H
