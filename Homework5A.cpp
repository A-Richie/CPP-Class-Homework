#include <iostream>
#include <string>

using namespace std;

/*
Lab 3A
Author: Alyssa Richie
Program purpose: Get the date from the user and format it to be yy-mm-day
*/


int main()
{
    //declares variables that get assigned values by user
    string day;
    string month;
    string year;
    string dateString;

    //Asks for user to assign day, month, year then displays result in yy-mm-day format
    cout << "My name is Alyssa Richie" << endl << endl;
    cout << "Enter a day number, month number then year separated by spaces: ";
    cin >> day >> month >> year;

    //combines day month year to one string variable
     dateString = "The formatted date is '" + year + "-" + month + "-" + day + "'.";

    //displays the single string output date
    cout << dateString;
    return 0;
}
