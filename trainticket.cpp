#include "trainticket.h"

TrainTicket::TrainTicket(string trainTicketId, double trainTicketPrice, string ticketFromDate, string ticketToDate, string fromDestination, string toDestination, string departureTime,string arrivalTime, string type)
    :Booking(trainTicketId,trainTicketPrice,ticketFromDate,ticketToDate), fromDestination(fromDestination),toDestination(toDestination),departureTime(departureTime),arrivalTime(arrivalTime), type(type)
{

}
TrainTicket::TrainTicket(string trainTicketId, double trainTicketPrice, string ticketFromDate, string ticketToDate, string fromDestination, string toDestination, string departureTime,string arrivalTime,string type,
                         std::vector<string> &connectingStations)
    :Booking(trainTicketId,trainTicketPrice,ticketFromDate,ticketToDate), fromDestination(fromDestination),toDestination(toDestination),departureTime(departureTime),arrivalTime(arrivalTime),type(type)
    ,connectingStations(connectingStations)
{

}


TrainTicket::~TrainTicket()
{

}

string TrainTicket::showDetails()
{
    string connectingStationsString;
    for(string station: connectingStations){
        connectingStationsString += station + ", ";
    }

    return "Zugticket von "+ fromDestination + " nach "+ toDestination + " am "+ fromDate + " um " + departureTime +" bis " + " ueber "
            +connectingStationsString + ". " + "Preis: "+ std::to_string(price)+"\n" ;
}



