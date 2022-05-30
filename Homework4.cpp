#include <iostream>
#include <cmath>

using namespace std;
/*
    Homework 4
    Author: Alyssa Richie
    Program Purpose: Calculates the focus, area, and circumference of an ellipse
*/

int main()
{
    //declares two input variables
    double majorRadius;
    double minorRadius;

    //obtains values for declared variables
    cout << "This program calculates the focus, area, and circumference of an ellipse." << endl << endl;
    cout << "Enter the semi-major axis value: ";
    cin >> majorRadius;
    cout << "Enter the semi-minor axis value: ";
    cin >> minorRadius;

    //calculates focus
    double focus = sqrt((pow(majorRadius, 2)) - (pow(minorRadius, 2)));

    //calculates area
    double area = M_PI * majorRadius * minorRadius;

    //Calculates circumference
        //double h is an intermediate value used for circumference calculation
    double h = (majorRadius - minorRadius) / (majorRadius + minorRadius);
    double circumference = M_PI * (majorRadius + minorRadius) * (1 + (3 * h) / (10 + sqrt( 4 - (3 * h) ) ) );

    //outputs focus, area and circumference
    cout << "\nThe ellipse focus is: " << focus << endl;
    cout << "The ellipse area is: " << area << endl;
    cout << "The ellipse circumference is: " << circumference << endl;
    return 0;
}
