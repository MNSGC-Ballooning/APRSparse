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

    if(inputAPRS.fail()){
        cout << "ERROR opening input file";
        exit(0);}
    if(outputCSV.fail()){
        cout << "ERROR opening output file";
        exit(0);}

    string junk, comma;
    int year, day, month, hour[500], minute[500], second[500], tempC[500], i=0, startHour, startMinute, startSecond;
    char dash, colon;
    double lat[500], lon[500], alt[500], flightMinutes[500];

    outputCSV << "Month , Day , hour , minute , second , latitude , longitude , temperature (C) , altitude (ft), minutes into flight\n";

while(!inputAPRS.eof()){
    getline(inputAPRS, junk, '-');
    inputAPRS >> month >> dash >> day >> hour[i] >> colon >> minute[i] >> colon >> second[i];
    getline(inputAPRS, junk, '!');
    inputAPRS >> lat[i];
    getline(inputAPRS,junk,'/');
    inputAPRS >> lon[i];
    getline(inputAPRS,junk, '=');
    inputAPRS >> alt[i];
    getline(inputAPRS,junk,'V');
    getline(inputAPRS,junk,',');
    inputAPRS >> tempC[i];
    if(i==1){
        startHour = hour[i];
        startMinute = minute[i];
        startSecond = second [i];
    }
    for(int k=0; k<i; k++)
    {
        if(alt[i]==alt[k])
        {
            //cout << alt[i];
            break;
        }
        if(k==(i-1)){
            flightMinutes[i] = ((hour[i]-startHour)*60)+(minute[i]-startMinute)+ ((second[i]-startSecond)/60);
             //cout << i << endl;
            outputCSV << month << "," << day << "," << hour[i] << "," << minute[i] << "," << second[i] << ","
            << lat[i]/100 << " , " << lon[i]/100 << " , " << tempC[i] << " , " << alt[i] << "," << flightMinutes[i] << "\n";}
    }
    //cout << i;
    i++;}

    inputAPRS.close();
    outputCSV.close();

    return(0);
}
