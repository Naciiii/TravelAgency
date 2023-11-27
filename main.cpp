#include <iostream>
#include <booking.h>
#include <string>
#include <flightbooking.h>
#include "travelagency.h"
#include <fstream>

using namespace std;

int main()
{

    TravelAgency travelAgency;
    char eingabe;

    do{
        cout << "JSON - oder Binaerdatei lesen? (q beendet das Programm)"<<endl;


        cin >> eingabe;
        switch (eingabe) {

            case'j':
                travelAgency.readFile();
            break;

            case'b':
                travelAgency.readBinaryFile();
            break;

            case'q':
            cout << "Das Programm wird beendet"<<endl;
            break;
        default:
            cout << "falsche Eingabe. Bitte erneut versuchen."<< endl;
        }
    }while(eingabe != 'q');


    return  0;
}
