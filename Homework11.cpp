#include <iostream>
#include <ctime>
#include <cstdlib>


using namespace std;

/*
Homework 11
Author: Alyssa Richie
Program purpose: output 5 random numbers based on inputed vowels
*/


int main()
{
    srand(time(0)); // makes every generated number random
    char firstInput;
    char secondInput;
    char thirdInput;
    char fourthInput;
    char fithInput;
    char keepGoing = 'y';
    int createRandomFromChar(char inputChar);

    cout << "This program plays a simple random number game." << endl;
    while (keepGoing == 'y' || keepGoing == 'Y')
    {
        cout << "Enter 5 vowel characters (a,e,i,o,u or A,E,I,O,U) separated by spaces:";
        cin >> firstInput >> secondInput >> thirdInput >> fourthInput >> fithInput;
        cin.ignore();
        cout << endl;
        cout << "The random numbers are ";
        cout << createRandomFromChar(firstInput) << " " << createRandomFromChar(secondInput) << " " << createRandomFromChar(thirdInput) << " " << createRandomFromChar(fourthInput) << " " << createRandomFromChar(fithInput) << endl;
        cout << endl;
        cout << "Do you want to play another game? (Y or y to continue): ";
        cin.get(keepGoing);
    }
    cout << "Goodbye" << endl;

    return 0;
}


//function for getting numbers from the inputs
int createRandomFromChar(char inputChar)
{
    if(inputChar == 'A' || inputChar == 'a')
    {
        return rand() % (20 - 1 + 1) + 1;
    }
    else if(inputChar == 'E' || inputChar == 'e')
    {
        return rand() % (40 - 21 + 1) + 21;
    }
    else if(inputChar == 'I' || inputChar == 'i')
    {
        return rand() % (60 - 41 + 1) + 41;
    }
    else if(inputChar == 'O' || inputChar == 'o')
    {
        return rand() % (80 - 61 + 1) + 61;
    }
    else if(inputChar == 'U' || inputChar == 'u')
    {
        return rand() % (100 - 81 + 1) + 81;
    }
    else
    {
        return 0;
    }
}
