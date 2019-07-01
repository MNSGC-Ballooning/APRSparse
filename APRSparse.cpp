#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    ifstream inputAPRS;
    inputAPRS.open("rawAPRS.txt");

    ofstream outputCSV;
    outputCSV.open("filteredAPRS.csv");

    if(inputAPRS.fail())
    {
        cout << "ERROR opening input file";
        exit(0);
    }
    if(outputCSV.fail())
    {
        cout << "ERROR opening output file";
        exit(0);
    }

    string junk, comma;
    int year, day, month, hour, minute, second, tempC, i=0;
    char dash, colon;
    double lat, lon, alt;

    outputCSV << "Month , Day , hour , minute , second , latitude , longitude , altitude (m) , temperature (C)\n";



while(!inputAPRS.eof()){
    getline(inputAPRS, junk, '-');
    inputAPRS >> month >> dash >> day >> hour >> colon >> minute >> colon >> second;
    getline(inputAPRS, junk, '!');
    inputAPRS >> lat;
    getline(inputAPRS,junk,'/');
    inputAPRS >> lon;
    getline(inputAPRS,junk, '=');
    inputAPRS >> alt;
    getline(inputAPRS,junk,'V');
    getline(inputAPRS,junk,',');
    inputAPRS >> tempC;

    outputCSV << month << "," << day << "," << hour << "," << minute << "," << second << ","
            << lat/100 << " , " << lon/100 << " , " << alt << " , " << tempC << "\n";
    i++;

    }


    inputAPRS.close();
    outputCSV.close();

    return(0);


}
