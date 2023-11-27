#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H

#include <booking.h>

class RentalCarReservation : public Booking
{
public:
    RentalCarReservation(string id, double price, string fromDate, string toDate, string pickupLocation, string returnLocation, string company, string type);
    ~RentalCarReservation();

    string showDetails();


    string getPickupLocation() const;
    void setPickupLocation(const string &value);

    string getReturnLocation() const;
    void setReturnLocation(const string &value);

    string getCompany() const;
    void setCompany(const string &value);

private:
    string pickupLocation;
    string returnLocation;
    string company;
    string type;
};

#endif // RENTALCARRESERVATION_H
