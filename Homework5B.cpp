#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*
Homework 5B
Author: Alyssa Richie
Program purpose: displays variables in a specific format / table
*/

int main()
{

    //declares and establishes values for the variables
    string col1 = "Column 1",
          col2 = "Column 2",
          col3 = "Column 3";
    double d1 =  1.2,
            d2 = 3454.456,
            d3 = 456.6,
            d4 = 23,
            d5 = 89569.84,
            d6 = 4.454,
            d7 = 676.5,
            d8 = 334.1,
            d9 = 34.4544;

    //displays the row 1 which is all the columns
    cout << setw(15) << col1 <<  setw(15) << col2 <<  setw(15) << col3 << endl;

    //sets precision of digits after decimal point
    cout << fixed << setprecision(3);

    //displays rows of numbers
    cout << setw(15) << d1 <<  setw(15) << d2 <<  setw(15) << d3 << endl;
    cout << setw(15) << d4 <<  setw(15) << d5 <<  setw(15) << d6 << endl;
    cout << setw(15) << d7 <<  setw(15) << d8 <<  setw(15) << d9 << endl;

    return 0;
}
