//******************************************************************************
// Program name: Lab5b
//
// Description: The program uses a linked list to manipulate a sequence 
//              of numbers.
//
// What's on your mind about this lab? I learned about how a pointer to a 
//              linked list uses -> instead of . to access functions
//
// Author: Alyssa Richie
//
// Date: 06/12/2021
//
// IDE Used: Visual Studio Code
//
// Template Date: 04/06/2021
//******************************************************************************

#include <iostream>
#include <iomanip>
#include <sstream>
#include "NumberList.h"

using namespace std;

NumberList *getInsertData(istream &, NumberList *);
NumberList *getDeleteData(istream &, NumberList *);

int main() 
{
    //1. Define an instance variable of NumberList
    NumberList listObject;

    //2. Call getInsertData to get numbers from cin and insert them into 
    //   the list.
    //   (You can do this by calling the function and passing cin and the 
    //    address of the list as the arguments.)
    getInsertData(cin, &listObject);

    //3. Display the list.
    cout << "Displaying list after inserting numbers" << endl;
    listObject.displayList();

    //4. Call getDeleteData to get the numbers from cin and delete them 
    //   from the list.
    getDeleteData(cin, &listObject);

    //5. Display the list again.
    cout << "Displaying list after deleting numbers" << endl;
    listObject.displayList();
    
    return 0;
}

//******************************************************************************
//* Function Name: getInsertData
//*
//* Description: This function gets integers from the input stream
//*     object in continuously. It assumes the integers are separated by
//*     white spaces. The function inserts each of the integers
//*     into the given NumberList. It stops getting the
//*     the integers when it sees -1 which will not be inserted.
//*
//* Parameters:
//*
//*    in - The input stream object.
//*    list - The pointer that points to a NumberList object.
//*
//* Returns:
//*    The pointer to the NumberList object is returned.
//*
//******************************************************************************

NumberList *getInsertData(istream &in, NumberList *list)
{
    // 1. define the variable for holding a number
    int number {0};
    
    // 2. extract a number from the input stream
    in >> number;

    // 3. if the stream is ok and the number is not -1, do the following.
    //    insert the number into the list
    //    extract a number from the input stream
    //    repeat step 3
    while(in && number != -1) 
    {
        list->insertNode(number);
        in >> number;
    }

    return list;
}

//******************************************************************************
//* Function Name: getDeleteData
//*
//* Description: This function gets integers from the input stream
//*     object in continuously. It assumes the integers are separated by
//*     white spaces. The function delete each of those integers
//*     from the given NumberList. It stops
//*     getting the integers when it sees -1 and throws away.
//*
//* Parameters:
//*
//*    in - The input stream object.
//*    list - The pointer that points to a NumberList object.
//*
//* Returns:
//*    The pointer to the NumberList object is returned.
//*
//******************************************************************************
NumberList *getDeleteData(istream &in, NumberList *list)
{
    //define variable for holding a number
    int number {0};

    //extract number from input stream
    in >> number;

    // 3. if the stream is ok and the number is not -1, do the following.
    //    delete the number from the list
    //    extract a number from the input stream
    //    repeat step 3
    
    while(in && number != -1) 
    {
        list->deleteNode(number);
        in >> number;
    }
    return list;
}

