#include <iostream>

using namespace std;

/*
Homework 12B
Author: Alyssa Richie
Program purpose: Calculates a rectangles perimeter and area
                    using pass by reference variables
*/

//function prototype
bool rectangleAreaPerim(double width, double height, double *a, double *p);

int main()
{
    //declare variables
    double width, height, area, perimeter;
    cout << "This program calculates the area and perimeter of a rectangle.";

    //keeps program going as long as user desires
    while (width != 0 || height != 0)
    {
        cout << endl;
        cout << "Enter width and height separated by spaces, or enter 0 0 to stop: ";
        cin >> width >> height;

        //runs function
        bool success = rectangleAreaPerim(width, height, &area, &perimeter);

        //if statement stops an output if both the numbers are 0
        if (width != 0 || height != 0)
        {
            //if both inputs are valid and function calculated - returns output
            if (success)
            {
                cout << "Rectangle area is " << area << endl;
                cout << "Rectangle perimeter is " << perimeter << endl;
            }
            else
            {
                cout << "Invalid input" << endl;
            }
        }

    }

    cout << endl;
    cout << "Goodbye." << endl;
    return 0;
}


//returns true/false if width and height are invalid (and if perimeter and area could be calculated)
bool rectangleAreaPerim(double width, double height, double *a, double *p)
{
    if (width < 0 || height < 0)
    {
        return false;
    }

    //calculate perimeter
    *p = 2 * width + 2 * height;
    //calculate area
    *a = width * height;
    return true;
}
