//******************************************************************************
// Program name: Lab1a
//
// Description: This program takes the user input for a 2D array and
//              displays it
//
// What's on your mind about this lab? The lab gives me experience using 2D
//                                     arrays.
//
//
// Author: Alyssa Richie
//
// Date: 04/17/2021
//
// IDE Used: CodeBlocks
//
// Template Date: 04/06/2021
//******************************************************************************

#include <iostream>
#include <iomanip>

using namespace std;

const int QUARTERS = 4;
const int DATA_SPACING = 10; //used in set(w) for spacing for inputed numbers
const int DIV_SPACING = 3; //used in set(w) for spacing of div number

//prototype of printSalesData function
void printSalesData (double[][QUARTERS], int);


int main()
{
    double salesData [3][QUARTERS] {0};
    for (int div = 0; div < 3; ++div)
    {
        for (int qtr = 0; qtr < QUARTERS; ++qtr)
        {
            cin >> salesData[div][qtr];
        }
    }

    //call statement to print function
    printSalesData(salesData, 3);
    return 0;
}

//******************************************************************************
//* Function name: printSalesData
//*
//* This function prints corporation sales to the console
//*
//* Parameters:
//*    newSalesData[][QUARTERS] - holds sales data for each division at each
//*                               quarter
//*    divs - gives function knowledge of how many divisions
//*
//* Returns:
//*
//*    void
//*
//******************************************************************************
void printSalesData (double newSalesData[][QUARTERS], int divs)
{

    //label for sales report
    cout << endl;
    cout << "Corporation Sales Report" << endl;

    //Division label
    cout << "DIV";

    //Quarter 1 & 2 label
    cout << setw(DATA_SPACING) << "Q1" << setw(DATA_SPACING) << "Q2";

    //Quarter 3 & 4 label
    cout << setw(DATA_SPACING) << "Q3" << setw(DATA_SPACING) << "Q4";

    //loop that goes through each division
    for (int divCount = 0; divCount < divs; divCount++)
    {
        //prints current division in the loop
        cout << endl;
        cout << setw(DIV_SPACING) << divCount;

        //loop that goes through each quarter in the current division
        for (int qtrCount = 0; qtrCount < QUARTERS; qtrCount++)
        {
            //prints sales data for current division at current quarter
            cout << setw(DATA_SPACING) << newSalesData[divCount][qtrCount];
        }

    }
}


