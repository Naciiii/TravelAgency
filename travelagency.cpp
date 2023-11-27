#include "travelagency.h"
#include <fstream>
#include "json.hpp"
#include "flightbooking.h"
#include "booking.h"
#include "rentalcarreservation.h"
#include "hotelbooking.h"
#include "trainticket.h"


using namespace  std;
using json = nlohmann::json;

TravelAgency::TravelAgency()
{

}
TravelAgency::~TravelAgency()
{
    // Freigabe des Heap-Speichers für Buchungsobjekte
        for (const auto& booking : Bookings)
        {
            delete booking;
        }
}
void TravelAgency::readFile()
{
    double gesamtFlugPreis = 0;
    double gesamtMietwagenPreis = 0;
    double gesamtHotelPreis = 0;
    double gesamtTrainTicketPreis = 0;
    int flightCounter = 0;
    int rentalCarCounter = 0;
    int hotelCounter = 0;
    int trainticketCounter = 0;
    int bookingCounter = 0;

    for (const auto& booking : Bookings)
    {
        delete booking;
    }
    Bookings.clear();

    ifstream file("bookings.json");
    json jsonData = json::parse(file);
    try{
        for(const auto& bookingData: jsonData){
            bookingCounter++;

            const string& bookingType = bookingData["type"];

            if(bookingType == "Flight"){
                string id = bookingData["id"];
                double price = bookingData["price"];
                string fromDate = bookingData["fromDate"];
                string toDate = bookingData["toDate"];
                string fromDestination = bookingData["fromDest"];
                string toDestination = bookingData["toDest"];
                string airline = bookingData["airline"];
                string type = bookingData["type"];          //string flightId, double flightPrice, string flightDateFrom,string flightToDate, string fromDestination, string toDestination, string airline,string type

                if(id.empty()){
                    throw invalid_argument("Leeres Attribute Id ");
                }
                if (!bookingData["price"].is_number())
                {
                    throw invalid_argument("Ungültiger numerischer Wert für Price ");
                }
                if(fromDate.empty()){
                    throw invalid_argument("Leeres Attribute fromDate ");
                }
                if(toDate.empty()){
                    throw invalid_argument("Leeres Attribute toDate ");
                }
                if(fromDestination.empty()){
                    throw invalid_argument("Leeres Attribute fromDestination ");
                }

                if(toDestination.empty()){
                    throw invalid_argument("Leeres Attribute toDestination ");
                }

                if(toDestination.size() != 3){
                    throw invalid_argument("Destinationbuchstabe kann max 3 sein. ");
                }
                if(fromDestination.size() != 3){
                    throw invalid_argument("Destinationbuchstabe kann max 3 sein ");
                }
                if(airline.empty()){
                    throw invalid_argument("Leeres Attribute airline " );

                }

                FlightBooking* flightbooking = new FlightBooking(id,price,fromDate,toDate,fromDestination,toDestination,airline,type);
                flightCounter++ ;
                Bookings.push_back(flightbooking);


                gesamtFlugPreis = gesamtFlugPreis + flightbooking->getPrice();
                //cout << flightbooking->showDetails()<< endl;



            }

            else if(bookingType == "RentalCar"){
                string id = bookingData["id"];
                double price = bookingData["price"];
                string fromDate = bookingData["fromDate"];
                string toDate = bookingData["toDate"];
                string company = bookingData["company"];
                string pickupLocation = bookingData["pickupLocation"];
                string returnLocation = bookingData["returnLocation"];
                string type = bookingData["type"];

                if(id.empty()){
                    throw invalid_argument("Leeres Attribute Id");
                }
                if (!bookingData["price"].is_number())
                {
                    throw invalid_argument("Ungültiger numerischer Wert für Price ");
                }
                if(fromDate.empty()){
                    throw invalid_argument("Leeres Attribute fromDate ");
                }
                if(toDate.empty()){
                    throw invalid_argument("Leeres Attribute toDate ");
                }
                if(company.empty()){
                    throw invalid_argument("leeres Attribute company ");
                }
                if(pickupLocation.empty()){
                    throw invalid_argument("leeres Attribute pickupLocation ");
                }
                if(returnLocation.empty()){
                    throw invalid_argument("leeres Attribute returnLocation ");
                }


                RentalCarReservation* rentalCarReservation = new RentalCarReservation(id,price,fromDate,toDate,pickupLocation,returnLocation,company,type);
                Bookings.push_back(rentalCarReservation);
                rentalCarCounter++;
                gesamtMietwagenPreis = gesamtMietwagenPreis + rentalCarReservation->getPrice();
                //cout << rentalCarReservation->showDetails();

            }
            else if(bookingType == "Hotel"){
                string id = bookingData["id"];
                double price = bookingData["price"];
                string fromDate = bookingData["fromDate"];
                string toDate = bookingData["toDate"];
                string hotel = bookingData["hotel"];
                string town = bookingData["town"];
                string type = bookingData["type"];
                if(id.empty()){
                    throw invalid_argument("Leeres Attribute Id ");
                }
                if (!bookingData["price"].is_number())
                {
                    throw invalid_argument("Ungültiger numerischer Wert für Price ");
                }
                if(fromDate.empty()){
                    throw invalid_argument("Leeres Attribute fromDate ");
                }
                if(toDate.empty()){
                    throw invalid_argument("Leeres Attribute toDate ");
                }
                if(hotel.empty()){
                    throw invalid_argument("Leeres Attribute hotel ");
                }
                if(town.empty()){
                    throw invalid_argument("Leeres Attribute town ");
                }

                HotelBooking* hotelbooking = new HotelBooking(id,price,fromDate,toDate,hotel,town,type);
                Bookings.push_back(hotelbooking);
                hotelCounter++;  //string hotelId, double hotelPrice, string hotelFromDate, string hotelToDate, string hotel, string town, string type
                gesamtHotelPreis = gesamtHotelPreis + hotelbooking->getPrice();
                //cout << hotelbooking->showDetails();


            }
            else if(bookingType == "Train"){
                string id = bookingData["id"];
                double price = bookingData["price"];
                string fromDate = bookingData["fromDate"];
                string toDate = bookingData["toDate"];
                string fromDestination = bookingData["fromStation"];
                string toDestination = bookingData["toStation"];
                string departureTime = bookingData["departureTime"];
                string arrivalTime = bookingData["arrivalTime"];
                vector<string>connectingStations = bookingData["connectingStations"];
                string type = bookingData["type"];

                if(id.empty()){
                    throw invalid_argument("Leeres Attribute Id ");
                }
                if (!bookingData["price"].is_number())
                {
                    throw invalid_argument("Ungültiger numerischer Wert für Price ");
                }
                if(fromDate.empty()){
                    throw invalid_argument("Leeres Attribute fromDate ");
                }
                if(toDate.empty()){
                    throw invalid_argument("Leeres Attribute toDate ");
                }
                if(fromDestination.empty()){
                    throw invalid_argument("Leeres Attribute fromDestination ");
                }
                if(toDestination.empty()){
                    throw invalid_argument("Leeres Attribute toDestination ");
                }
                if(departureTime.empty()){
                    throw invalid_argument("Leeres Attribute departureTime ");
                }

                if(arrivalTime.empty()){
                    throw invalid_argument("Leeres Attribute arrivalTime ");
                }



                TrainTicket* trainticket = new TrainTicket(id,price,fromDate,toDate,fromDestination,toDestination,departureTime,arrivalTime,type,connectingStations);
                Bookings.push_back(trainticket);
                trainticketCounter++;
                gesamtTrainTicketPreis = gesamtTrainTicketPreis + trainticket->getPrice();
                //cout << trainticket->showDetails();


            }

        }

        cout << "Es wurden " << flightCounter << " Flugbuchungen im Wert von " << gesamtFlugPreis << " Euro , " <<endl<< rentalCarCounter << " Mietwagenbuchungen im Wert von " << gesamtMietwagenPreis
             << " Euro , "<<endl<< hotelCounter << " Hotelreservierungen im Wert von "<< gesamtHotelPreis <<" Euro und "<<endl<< trainticketCounter<< " Zugbuchungen im Wert von "<< gesamtTrainTicketPreis
             << " Euro , angelegt."<<endl;
    }
    catch(const exception&e){
        cerr << "Fehler beim Lesen der JSON-Datei: " << e.what() <<" Bookingsnummer : "<< bookingCounter<< endl;

    }
    file.close();



}
void TravelAgency::readBinaryFile()
{
    double gesamtFlugPreis = 0;
    double gesamtMietwagenPreis = 0;
    double gesamtHotelPreis = 0;
    double gesamtTrainTicketPreis = 0;
    int flightCounter = 0;
    int rentalCarCounter = 0;
    int hotelCounter = 0;
    int trainticketCounter = 0;

    ifstream inputFile("bookingsBinary.bin", ios::binary | ios::in);
    if(!inputFile.is_open()){
        cerr << " Datei kann nett geoffnet werden"<< endl;
        return;
    }

    while (!inputFile.eof()) {
        char bookingType;

        // initialize Booking object
        char id[38];
        double price;
        char fromDate[8];
        char toDate[8];

        inputFile.read(&bookingType, 1);
        inputFile.read(id, sizeof(id));
        inputFile.read(reinterpret_cast<char *>(&price), sizeof(price));
        inputFile.read(fromDate, sizeof(fromDate));
        inputFile.read(toDate, sizeof(toDate));

        string idStr = convertToString(id, 38);
        string fromDateStr = convertToString(fromDate, 8);
        string toDateStr = convertToString(toDate, 8);

        if (bookingType == 'F') {

            char fromDestination[3];
            char toDestination[3];
            char airline[15];
            inputFile.read(fromDestination, sizeof(fromDestination));
            inputFile.read(toDestination, sizeof(toDestination));
            inputFile.read(airline, sizeof(airline));
            string fromDestinationStr = convertToString(fromDestination, 3);
            string toDestinationStr = convertToString(toDestination, 3);
            string airlineStr = convertToString(airline, 15);

            FlightBooking* flightbooking = new FlightBooking(idStr, price, fromDateStr, toDateStr, fromDestinationStr, toDestinationStr, airlineStr, type);
            Bookings.push_back(flightbooking);
            gesamtFlugPreis = gesamtFlugPreis + flightbooking->getPrice();
            //cout << flightbooking->showDetails();
            flightCounter++;



        } else if (bookingType == 'R') {
            char pickupLocation[15];
            char returnLocation[15];
            char company[15];
            inputFile.read(pickupLocation, sizeof(pickupLocation));
            inputFile.read(returnLocation, sizeof(returnLocation));
            inputFile.read(company, sizeof(company));
            string pickupLocationStr = convertToString(pickupLocation, 15);
            string returnLocationStr = convertToString(returnLocation, 15);
            string companyStr = convertToString(company, 15);

            RentalCarReservation* rentalCarReservation = new RentalCarReservation(idStr,price,fromDateStr,toDateStr,pickupLocationStr,returnLocationStr,companyStr,type);
            Bookings.push_back(rentalCarReservation);
            rentalCarCounter++;
            //cout << rentalCarReservation->showDetails();
            gesamtMietwagenPreis = gesamtMietwagenPreis + rentalCarReservation->getPrice();


        } else if (bookingType == 'H') {
            char hotel[15];
            char town[15];
            inputFile.read(hotel, sizeof(hotel));
            inputFile.read(town, sizeof(town));
            string hotelStr = convertToString(hotel, 15);
            string townStr = convertToString(town, 15);

            HotelBooking* hotelbooking = new HotelBooking(idStr,price,fromDateStr,toDateStr,hotelStr,townStr,type);
            Bookings.push_back(hotelbooking);
            hotelCounter++;  //string hotelId, double hotelPrice, string hotelFromDate, string hotelToDate, string hotel, string town, string type
            gesamtHotelPreis = gesamtHotelPreis + hotelbooking->getPrice();
            //cout << hotelbooking->showDetails();


        } else if (bookingType == 'T') {
            char fromDestination[15];
            char toDestination[15];
            char departureTime[5];
            char arrivalTime[5];
            int connectingStationsCount;
            char connectingStations[15];

            inputFile.read(fromDestination, sizeof(fromDestination));
            inputFile.read(toDestination, sizeof(toDestination));
            inputFile.read(departureTime, sizeof(departureTime));
            inputFile.read(arrivalTime, sizeof(arrivalTime));
            inputFile.read(reinterpret_cast<char *>(&connectingStationsCount), sizeof(int));

            string fromDestinationStr = convertToString(fromDestination, 15);
            string toDestinationStr = convertToString(toDestination, 15);
            string departureTimeStr = convertToString(departureTime, 5);
            string arrivalTimeStr = convertToString(departureTime, 5);

            //read connecting stations depending on connecting stations count
            vector<string> stations;
            for (int i = connectingStationsCount; i > 0; i--) {
                inputFile.read(connectingStations, sizeof(connectingStations));
                string connectingStationsStr = convertToString(connectingStations, 15);
                stations.push_back(connectingStationsStr);
            }
            TrainTicket* trainticket = new TrainTicket(idStr, price, fromDateStr, toDateStr, fromDestinationStr, toDestinationStr,departureTimeStr
                                                       ,arrivalTimeStr,type,stations);
            Bookings.push_back(trainticket);
            trainticketCounter++;
            gesamtTrainTicketPreis = gesamtTrainTicketPreis + trainticket->getPrice();
            //cout << trainticket->showDetails();
            delete trainticket;

        }
    }
    cout << "Es wurden " << flightCounter << " Flugbuchungen im Wert von " << gesamtFlugPreis << " Euro , " <<endl<< rentalCarCounter << " Mietwagenbuchungen im Wert von " << gesamtMietwagenPreis
         << " Euro , "<<endl<< hotelCounter << " Hotelreservierungen im Wert von "<< gesamtHotelPreis <<" Euro und "<<endl<< trainticketCounter<< " Zugbuchungen im Wert von "<< gesamtTrainTicketPreis
         << " Euro , angelegt."<<endl;

}

string TravelAgency::convertToString(char *arrayOfChars, int size) {
    string value{""};
    for (int i = 0; i < size; i++) {
        value += arrayOfChars[i];
    }
    //remove empty chars in the end of string
    while (!value.empty() && isspace(value.back())) {
        value.pop_back();
    }
    return value;
}
