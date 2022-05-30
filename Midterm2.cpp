// Program name: Midterm2
//
// Description: This program compares the scores of two contestants
//     and declares the winner.
//
// Author: Alyssa Richie
//
// Date: 05/19/2021
//
// IDE Used: CodeBlocks
//

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

// Constants you must use for output formatting
// The width of the ID column
const int COL1 = 4;
// The width of each of the score columns
const int COLS = 8;

// Constants you must use for validating scores
const double MIN_SCORE = 0.0;
const double MAX_SCORE = 5.0;

// The Contestant data structure and
// related functions.
const int SCORES_SIZE = 4;
struct Contestant {
    // Contestant's ID
    int cid;
    // Contestant's scores
    double scores[SCORES_SIZE];
};

// Functions related to the Contestant data structure
bool readContestant(Contestant *ptr);
int getID(const Contestant *ptr);
double getAverageScore(const Contestant *ptr);
bool isValidScore(const Contestant *ptr);
int compareContestants(const Contestant &, const Contestant &);
void printHeading();
void printContestantData(const Contestant *ptr);

int main() {
    // Create contestant variables
    Contestant contestant1;
    Contestant contestant2;

    // Read contestant information
    bool isValid1 = readContestant(&contestant1);
    bool isValid2 = readContestant(&contestant2);

    // Print the contest report
    if (isValid1 && isValid2) {
        // Print the header
        printHeading();
        // Print the first contestant data
        printContestantData(&contestant1);
        // Print the second contestant data
        printContestantData(&contestant2);
        // Compare the scores
        int winner = compareContestants(contestant1, contestant2);
        if (!winner) {
            // Both scored the same
            cout << "Both contestants scored the same.\n";
        }
        else {
            // Print the winner
            cout << "The winner of the contest between contestant "
                 << getID(&contestant1)
                 << " and contestant "
                 << getID(&contestant2)
                 << " is contestant "
                 << winner
                 << ".\n";
        }
    }
    else if (!isValid1) {
        // First contestant's data is invalid
        cout << "First contestant's data invalid." << endl;
    }
    else if (!isValid2) {
        // Second contestant's data is invalid
        cout << "Second contestant's data invalid." << endl;
    }

    return 0;
}

//*****************************************************************************
//* Given a pointer to a Contestant data structure,
//* return the contestant's id contained in the data structure.
//*
//* Parameters
//*   ptr - pointer to a Contestant struct
//*
//* Returns
//*    The contestant's id.
//*****************************************************************************
int getID(const Contestant *ptr) {
    return ptr->cid;
}

//*****************************************************************************
//* The function named readContestant receives a pointer parameter that points
//* to a Contestant data structure to be filled with a contestant's data.
//*
//* It reads the contestant's ID and some double numbers from the keyboard and
//* stores the ID in the contestant's id field and the scores in the
//* scores array.
//*
//* This function expects an integer and some double numbers from the keyboard
//* all entered in one line.
//*
//* If the read is successful and the input is validated, the function
//* returns true. Otherwise it returns false and the Contestant
//* data structure is unchanged.
//*
//* Parameters
//*   ptr - pointer to a Contestant struct
//*
//* Returns
//*    true if successful or false otherwise.
//*****************************************************************************
bool readContestant(Contestant *ptr) {
    bool isValid = false;

    // Create a temporary Contestant for receiving the keyboard input
    Contestant temp;

    // Read one line from the keyboard and save it.
    string input;
    getline(cin, input);

    if (cin) {
        // Use a stringstream object to help the input process
        stringstream sstr;
        sstr.str(input);

        // Use the input stream extraction operator to
        // retrieve data from the line of input.
        sstr >> temp.cid;
        for (int index = 0; index < SCORES_SIZE; ++index) {
            sstr >> temp.scores[index];
        }

        // Check for input success and then validate
        if (sstr && isValidScore(&temp)) {
            // Fill the given data structure
            // with data from the input line.
            *ptr = temp;
            isValid = true;
        }
    }

    return isValid;
}

//*****************************************************************************
//* Get the average score of the contestant.
//*
//* Parameters
//*    ptr - pointer to a Contestant struct
//*
//* Returns
//*    The average score.
//*****************************************************************************
double getAverageScore(const Contestant *ptr) {
    double average = 0.0;

    // Calculate the total score
    double total = 0.0;
    for (int index = 0; index < SCORES_SIZE; ++index) {
        total += ptr->scores[index];
    }
    // Calculate the average score
    average = total / SCORES_SIZE;

    return average;
}

//*****************************************************************************
//* Velidate that the given contestant info is valid. That is its ID is > 0 and
//* all scores are in the range between MIN_SCORE and MAX_SCORE inclusive.
//*
//* Parameters
//*
//*    ptr - a pointer to Contestant.
//*
//* Returns
//*    true if the info is valid or false otherwise.
//*****************************************************************************
bool isValidScore(const Contestant *ptr) {
    bool isValid = true;

    //first check if id is < 0 to be valid.
    if(getID(ptr) > 0)
    {
        //goes through scores of contestant
        for(int index = 0; index < SCORES_SIZE; index++)
        {
            //if score is bad set isvalid to false
            if(ptr->scores[index] < MIN_SCORE
               || ptr->scores[index] > MAX_SCORE)
            {
                isValid = false;
            }
        }
    }
    else
    {
        //set isvalid to false if id is invalid
        isValid = false;
    }
    //isvalid will be true if both the scores and id are valid.

    return isValid;
}

//*****************************************************************************
//* Compare two contestant's scores and determine the winner. The winner is
//* the contestant whose average score is higher. If the average scores are
//* equal, return 0.
//*
//* Parameters
//*
//*    c1 - The first contestant's scores.
//*    c2 - The second contestant's scores.
//*
//* Returns
//*    The contestant's id who is the winner among the two contestants
//*    or 0.
//*****************************************************************************
int compareContestants(const Contestant &c1, const Contestant &c2) {
    int winner = 0;

    //if c1s scores are better the winner is contestant 1
    if( getAverageScore(&c1) > getAverageScore(&c2))
    {
        //winner is set to contestant 1's ID
        winner = getID(&c1);
    }
    //if c2s scores are better the winner is contestant 2
    else if( getAverageScore(&c1) < getAverageScore(&c2))
    {
        //winner is set to contestant 2's ID
        winner = getID(&c2);
    }

    // does not do anything if they are tied so it returns 0
    return winner;
}

//*****************************************************************************
//* Print the report heading.
//*
//* Parameters
//*
//* Returns
//*    void
//*****************************************************************************
void printHeading() {
    // Print the labels at the top of each column
    cout << setw(COL1) << "P#";
    for (int index = 0; index < SCORES_SIZE; ++index) {
        // Use a stringstream object to prepare
        // a header label that starts with 'S'
        // followed by a number.
        stringstream sstr;
        sstr << 'S' << index + 1;
        cout << setw(COLS) << sstr.str();
    }
    cout << setw(COLS) << "Average" << endl;

    // Print a line under the labels
    cout << setfill('-');
    cout << setw(COL1 + COLS * (SCORES_SIZE + 1)) << '-' << endl;
    cout << setfill(' ');
}

//*****************************************************************************
//* Print the contestant's ID, test sccores and average score.
//*
//* Parameters
//*    ptr - pointer to a Contestant struct
//*
//* Returns
//*    void
//*****************************************************************************
void printContestantData(const Contestant *ptr) {
    //used to make sure only one ID per participant is printed
    bool printID = false;

    //goes through all of scores for a single participant
     for (int index = 0; index < SCORES_SIZE; ++index)
     {
        cout << fixed << setprecision(1);
        //if contestant's id was not printed. print it.
        if(printID == false)
        {
            cout << setw(COL1) << getID(ptr);
            printID = true;
        }
        cout << setw(COLS) << ptr->scores[index];
    }

    //set precision to 2 for averages
    cout << fixed << setprecision(2);
    //prints average for the contestant
    cout << setw(COLS) << getAverageScore(ptr);
    cout << endl;


}

/*
 Test case 1
 -----------

 12 5.0 4.3 4.6 4.3
 23 4.4 4.5 4.9 4.0

 The output should be exactly as follows.

 P#      S1      S2      S3      S4 Average
 --------------------------------------------
 12     5.0     4.3     4.6     4.3    4.55
 23     4.4     4.5     4.9     4.0    4.45
 The winner of the contest between contestant 12 and contestant 23 is contestant 12.


 Test case 2
 -----------

 12 5.0 4.3 4.6 4.3
 23 5.1 4.5 4.9 4.0

 The output should be exactly as follows.

 Second contestant's data invalid.

 Test case 3
 -----------

 12 5.0 4.3 4.3
 23 4.4 4.5 4.9 4.0


 The output should be exactly as follows.

 First contestant's data invalid.

 */



