#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


/*
Final Exam - Part B
Author: Alyssa Richie
Program purpose: Reads selected file from user input then outputs
                    occurrence statistics for all the numbers (1 - user determined max value )
*/

//function prototypes
int readNumbersAndTallyOccurrences(int occurrences[], int arrSize, ifstream &inFile);
void printCounts(int occurrences[], int arrSize);
void findMostAndLeastOccurrence(int occurrences[], int arrSize, int &highestCountIndex, int &lowestCountIndex);
int findTotalOccurrenceCount(int occurrences[], int arrSize);



int main()
{
    //declare variables
    int lowCount = 0;
    int highCount = 0;
    int tally;
    int totalTally;
    int inputMax;
    string fName;
    string firstLine;

    //Tells user what program is and ask for file name to open
    cout << "This program reads a number file and displays the number occurrence statistics." << endl;
    cout << "Enter the existing file name: ";
    cin >> fName;

    //opens file
    ifstream inFile;
    inFile.open(fName);

    //checks if file name is not valid
    if(!inFile)
    {
        cout << endl;
        cout << "File " << fName << " not found.";
        return 0;
    }

    //asks for the max value to count to
    cout << "Enter the highest number to get occurrence count (must be > 0): ";
    cin >> inputMax;

    //validation loop for max value input being >= 1
    while(inputMax < 1)
    {
        cout << "Number must not be less than 0!" << endl;
        cout << "Enter the highest number to get occurrence count (must be > 0): ";
        cin >> inputMax;
    }

    //define + initializes inputMax array used for counting
    int occurrences[inputMax] = {0};

    //checks if file is completely empty
    inFile >> firstLine;
    if(firstLine ==  "")
    {
        cout << "File does not contain any numbers.";
        return 0;
    }

    tally = readNumbersAndTallyOccurrences(occurrences, inputMax, inFile); //finds occurrences

    // Checks if there is no numbers in the file
    if(tally ==  0)
    {
        cout << "File does not contain any numbers.";
        return 0;
    }

    inFile.close(); //closes file

    printCounts(occurrences, inputMax); // prints occurrences

    totalTally = findTotalOccurrenceCount(occurrences, inputMax); //finds all occurrences

    //outputs results for occurrences
    cout << "There are " << tally << " numbers in the file." << endl;
    cout << "The total number of occurrence counts for numbers in the range of [1," << inputMax << "] is " << totalTally << "." << endl;

    findMostAndLeastOccurrence(occurrences, inputMax, highCount, lowCount); //finds highest and lowest occurrences

    //outputs results for highest and lowest occurrences
    cout << "The number " << highCount << " has the highest occurrence." << endl;
    cout << "The number " << lowCount << " has the lowest occurrence." << endl;

    return 0;
}


//fills in occurrences array and outputs how many TOTAL numbers are in the file
int readNumbersAndTallyOccurrences(int occurrences[], int arrSize, ifstream& inFile)
{
    int currentNum;
    int tally = 0;
    while (inFile >> currentNum)
    {
        if(currentNum <= arrSize)
        {
            occurrences[(currentNum - 1)] = occurrences[(currentNum - 1)] + 1;
        }
         tally++;
    }

    return tally;
}

//prints occurrence counts for each number 1 - user determined max value
void printCounts(int occurrences[], int arrSize)
{
    cout << setw(10) << "Number" << setw(20) << "Occurrences" << endl;
    for(int i = 0; i <= arrSize - 1; i++)
    {
        cout << setw(7) << (i + 1) << setw(20) << occurrences[i] << endl;
    }

}

//finds what is the number with the lowest occurrence (& highest) in the range
void findMostAndLeastOccurrence(int occurrences[], int arrSize, int& highestCountIndex, int& lowestCountIndex)
{
    for(int i = 1; i < arrSize; i++)
    {
        if(occurrences[i] > occurrences[highestCountIndex])
        {
            highestCountIndex = i;
        }
        if (occurrences[i] < occurrences[lowestCountIndex])
        {
            lowestCountIndex = i;
        }
    }

    //corrects for elements being at index 0, not index 1 (only if there are numbers)
    lowestCountIndex = lowestCountIndex + 1;
    highestCountIndex = highestCountIndex + 1;

}


//tallies all the occurrences of numbers that are in the range of 1 - user determined max value
int findTotalOccurrenceCount(int occurrences[], int arrSize)
{
    int totalTally = 0;

    for(int i = 0; i < arrSize; i++)
    {
            totalTally = totalTally + occurrences[i];
    }

    return totalTally;
}
