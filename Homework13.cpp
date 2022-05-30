#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

/*
Homework 13
Author: Alyssa Richie
Program purpose: Counts vowel occurrences in a user input
*/


const int VOWEL_ARRAY_SIZE = 5;
const char UPPER_VOWELS [] = "AEIOU";  // upper-case vowels
const char LOWER_VOWELS [] = "aeiou";  // lower-case vowels

int isVowel(char charInput);

int main()
{
    char name[300]; //user input
    int occurCounts[VOWEL_ARRAY_SIZE] = {0, 0, 0, 0, 0}; //counts for every time a vowel is found
    int highestOccurLocation = 0; // index number for what character in occurCounts is highest

    cout << "This program counts the vowel occurrences in input phrase" << endl;
    cout << "Enter a phrase and hit ENTER (maximum length 299): ";

    cin.getline(name, 300);
    int userLength = strlen(name);

    //loops through program until user does not enter anything
    while (userLength != 0)
    {
        // goes through each character the user entered
        for(int i = 0; i < userLength; i++)
            {
                occurCounts[isVowel(name[i])] = occurCounts[isVowel(name[i])] + 1;
            }

        //outputs count results
        cout << "Vowel" << setw(10) << "Count" << endl << endl;
        cout << "a - A" << setw(10) << occurCounts[0] << endl;
        cout << "e - E" << setw(10) << occurCounts[1] << endl;
        cout << "i - I" << setw(10) << occurCounts[2] << endl;
        cout << "o - O" << setw(10) << occurCounts[3] << endl;
        cout << "u - U" << setw(10) << occurCounts[4] << endl;
        cout << endl;
        cout << "Total of vowels is " << (occurCounts[0] + occurCounts[1] + occurCounts[2] + occurCounts[3] + occurCounts[4]) << endl;

        //finds the highest vowel occurrence
       for (int i = 1; i < VOWEL_ARRAY_SIZE; i++)
        {
            if (occurCounts[i] > occurCounts[highestOccurLocation])
            {
                highestOccurLocation = i;
            }
        }


        //outputs what is the vowel with the highest occurrence
        switch (highestOccurLocation)
        {
            case 0:
                cout << "Vowel with highest occurrence is A" << endl << endl;
                break;
            case 1:
                cout << "Vowel with highest occurrence is E" << endl << endl;
                break;
            case 2:
                cout << "Vowel with highest occurrence is I" << endl << endl;
                break;
            case 3:
                cout << "Vowel with highest occurrence is O" << endl << endl;
                break;
            case 4:
                cout << "Vowel with highest occurrence is U" << endl << endl;
                break;
        }


        //resets vowel counts for next input
        occurCounts[0] = 0;
        occurCounts[1] = 0;
        occurCounts[2] = 0;
        occurCounts[3] = 0;
        occurCounts[4] = 0;
        highestOccurLocation = 0;

        cout << "Enter a phrase and hit ENTER (maximum length 299): ";

        cin.getline(name, 300);
        userLength = strlen(name);
    }

    return 0;
}


//Function takes a character (c) and returns an index number IF c is a vowel
int isVowel(char c)
{
    // loop that checks if input character matches a e i o u
            // returns index number for occurrence Counter
        for (int i = 0; i < VOWEL_ARRAY_SIZE; i++)
        {
            if(c == UPPER_VOWELS[i] || c == LOWER_VOWELS[i])
            {
                return i;
            }
        }

        return -1;
}
