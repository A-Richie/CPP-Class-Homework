#include <iostream>
#include <string>

using namespace std;
/*
     Homework 3
     Author: Alyssa Richie
     Purpose: To calculate the area and circumference of a circle with a
                predetermined radius
*/


int main()
{
    //defines & assigns values to variables / constants (except variables area and circumference)
    double radius;
    double area;
    double circumference;
    const double PI = 3.14159;
    const string AREA_STR = "Area of the circle with radius";
    const string CIRCUM_STR = "Circumference of the circle with radius";
    radius = 3;

    //calculations
    area = PI * radius * radius;
    circumference = 2 * PI * radius;

    //outputs
    cout << "My name is Alyssa Richie." << endl;
    cout << AREA_STR << " " << radius << " is " << area << "." << endl;
    cout << CIRCUM_STR << " " << radius << " is " << circumference << ".";
    return 0;
}
