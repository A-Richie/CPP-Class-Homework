#include <iostream>
#include <iomanip>

using namespace std;

/*
Homework 8
Author: Alyssa Richie
Program purpose: displays all numbers divisible by a certain divisor (start from 10 and has max of 500)
*/

int main()
{
    //variables / constants for program
    const int MIN_GENERATED = 10;
    const int MAX_GENERATED = 500;
    int totalsum = 0;
    int generated = 0;
    int userGenerateNumber;
    int divisor;
    double average;


    cout << "This program displays all numbers divisible by a certain divisor starting from 10." << endl;

    //asks for divisor
    cout << "Enter a divisor from 2 to 10: ";
    cin >> divisor;

    //checks if divisor is valid
    while (divisor < 2 || divisor > 10)
    {
        cout << "Input " << divisor << " is not in the range of 2 to 10." << endl;
        cout << "Enter a divisor from 2 to 10: ";
        cin >> divisor;
    }

    //asks for generate number
    cout << "Enter the largest number to be generated. It must be in the range of 10-500: ";
    cin >> userGenerateNumber;

    //checks if valid input for generate number
    while (userGenerateNumber < MIN_GENERATED || userGenerateNumber > MAX_GENERATED)
    {
        cout << "Input " << userGenerateNumber << " is not in the range of " << MIN_GENERATED << "-" << MAX_GENERATED << endl;
        cout << "Enter the largest number to be generated. It must be in the range of 10-500: ";
        cin >> userGenerateNumber;
    }

    //generates numbers within range
    cout << "\nGenerated numbers divisible by " << divisor << " from " << MIN_GENERATED << " to " << userGenerateNumber << ":" << endl;
    for(int counter = MIN_GENERATED; counter <= userGenerateNumber; counter++)
    {
        //checks if number is divisible by the divisor
        if (counter % divisor == 0)
        {
            cout << setw(6) << counter;
            generated++;
            totalsum += counter;

            //does new line if 15 lines were posted
            if (generated % 15 == 0)
            {
                cout << endl;
            }
        }
    }

    //outputs the generated list.
    cout << endl << endl;
    cout << "Total sum: " << setw(10) << totalsum << endl;
    cout << "Count: " << setw(14) << generated << endl;

    //calculate average -- converts totalsum to double to prevent integer division
    average = (double) totalsum / generated;
    cout << "Average: " << setw(12) << average;
    return 0;
}
