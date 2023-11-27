#ifndef TRAINTICKET_H
#define TRAINTICKET_H

#include <booking.h>
#include <vector>


class TrainTicket : public Booking
{
public:
    TrainTicket(string id, double price, string fromDate, string toDate, string fromDestination, string toDestination, string departureTime,string arrivalTime,string type);
    TrainTicket(string id, double price, string fromDate, string toDate, string fromDestination, string toDestination, string departureTime, string arrivalTime, string type,
                std::vector<string>& connectingStations);
    ~TrainTicket();
    string showDetails();



private:
    string fromDestination;
    string toDestination;
    string departureTime;
    string arrivalTime;
    string type;

    vector<string>connectingStations;
};

#endif // TRAINTICKET_H
