//******************************************************************************
// Program name: Lab1d
//
// Description: Capitalizes each first letter of a new word after punctuation
//
// What's on your mind about this lab? The lab gives me experience using
//                                  a pointer that points to a C-String
//
// Author: Alyssa Richie
//
// Date: 05/01/2021
//
// IDE Used: CodeBlocks
//
// Template Date: 04/06/2021
//******************************************************************************

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

void sentenceCapitalizer(char *userString);

int main()
{
    const int MAX_SIZE = 1024;

    char userString[MAX_SIZE];

    //get user string
    cin.getline(userString, MAX_SIZE);

    //print userString uncapitalized
    cout << "The text before the modification:";
    cout << userString << '\n';
    cout << endl;

    //capitalize userString
    sentenceCapitalizer(userString);

    //print userString again
    cout << "The text after the modification:";
    cout << userString << '\n';

    return 0;
}

//******************************************************************************
//* Function name: sentenceCapitalizer
//*
//* This function capitalizes the first letter in each sentence contained
//* in a passed C-string.
//*
//* Parameters:
//*    userString - pointer to the caller's C-string to be capitalized
//*
//* Returns:
//*
//*    void
//*
//******************************************************************************

void sentenceCapitalizer(char *userString)
{

    //used to capitalize only the letter after a punctuation
    bool newSentence = true;

    //goes through all of userString
    while (*userString)
    {
        //checks the character is a letter AND a new sentence
        if(isalpha(*userString) && newSentence == true)
        {
            *userString = toupper(*userString);
            newSentence = false;
        }

        //sets newSentence to true if the current character is: . or ! or ?
        else if(*userString == '.' || *userString == '!' || *userString == '?')
        {
            newSentence = true;
        }

        //Goes to next character
        ++userString;
    }

}
