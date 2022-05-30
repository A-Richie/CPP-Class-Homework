#include <iostream>
#include <iomanip>

using namespace std;

/*
Homework 5C
Author: Alyssa Richie
Program purpose: Calculate quotient, remainder of two numbers
*/

int main()
{
    //declares variables
    int num1, num2;
    //says program's purpose and gets input that is assigned to the variables
    cout << "This program calculates quotient, remainder of two numbers" << endl << endl;
    cout << "Enter 2 whole numbers separated by a space: ";
    cin >> num1 >> num2;

    //outputs integer division quotient
    cout << "\nThe quotient of integer division (" << num1 << "/" << num2 << ") is: " << num1 / num2 << endl;

    //outputs integer division remainder
    cout << "The remainder of integer division (" << num1 << "/" << num2 << ") is: " << num1 % num2 << endl;

    //sets amount of digits after decimal point
    cout << fixed << setprecision(9);

    //typecasts variable to do floating-point division
    cout << "The result of floating-point division (" << num1 << "/" << num2 << ") is: " << (double)num1 / num2 << endl;
    return 0;
}
