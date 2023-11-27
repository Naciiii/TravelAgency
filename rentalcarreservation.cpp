#include "rentalcarreservation.h"

RentalCarReservation::RentalCarReservation(string carId, double carPrice, string carFromDate, string carToDate, string pickupLocation, string returnLocation, string company, string type)
    :Booking(carId,carPrice,carFromDate,carToDate), pickupLocation(pickupLocation),returnLocation(returnLocation),  company(company), type(type)
{

}

RentalCarReservation::~RentalCarReservation()
{

}

string RentalCarReservation::showDetails()
{
    return "Mietwagenreservierung mit " + company +". " + "Abholung am " + getFromDate() + "in " + pickupLocation +". " + "Ruckgabe am " + getToDate() + "in " + returnLocation+
            ". "+"Preis: " + std::to_string(getPrice())+" Euro "+ "\n";
}

string RentalCarReservation::getPickupLocation() const
{
    return pickupLocation;
}

void RentalCarReservation::setPickupLocation(const string &value)
{
    pickupLocation = value;
}

string RentalCarReservation::getReturnLocation() const
{
    return returnLocation;
}

void RentalCarReservation::setReturnLocation(const string &value)
{
    returnLocation = value;
}

string RentalCarReservation::getCompany() const
{
    return company;
}

void RentalCarReservation::setCompany(const string &value)
{
    company = value;
}
