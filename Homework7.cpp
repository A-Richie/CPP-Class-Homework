#include <iostream>

using namespace std;

/*
Homework 7
Author: Alyssa Richie
Program purpose: Print the number of days in a month.
*/


int main()
{
    //instructions for user
    cout << "Enter a year and a month number (1-12) separated by spaces: " << endl;

    //declares then assigns variables a value
    int year, month;
    cin >> year >> month;

    //outputs days in month / if month is valid
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            cout << "There are 31 days in " << month << "/" << year;
            break;
        case 2:
            //checks if year is a leap year
            if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
            {

                year < 1582 ? cout << "There are 28 days in " << month << "/" << year: cout << "There are 29 days in " << month << "/" << year;
            }
            else
            {
                cout << "There are 28 days in " << month << "/" << year;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            cout << "There are 30 days in " << month << "/" << year;
            break;
        default:
            cout << "Invalid month!";
            return 0;
    }
    return 0;
}
