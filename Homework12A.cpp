#include <iostream>
#include <cmath>

using namespace std;

/*
Homework 12A
Author: Alyssa Richie
Program purpose: Does power calculations using function with a default argument
*/

int power(int x, int y = 1);
void print(string text, int number);

int main()
{
    // Variable declaration
    int x = 3;

    // Driver statements
    x = power(x, 3);
    print("Value of x after step 1 is ", x);
    x = power(x, 2);
    print("Value of x after step 2 is ", x);
    x = power(x);
    print("Value of x after step 3 is ", x);
    x = power(x, 101);
    print("Value of x after step 4 is ", x);
    x = power(3, -5);
    print("Value of x after step 5 is ", x);
    x = 10;
    x = power(x);
    print("Value of x after step 6 is ", x);

    return 0;

}

//does calculation
int power(int x, int y)
{
    if(y > 100)
    {
        return -1;
    }

    return pow(x, y);
}

//outputs calculations
void print(string text, int number)
{
    cout << text << number << endl;
}
