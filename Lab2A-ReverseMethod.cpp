//******************************************************************************
// Program name: Lab2a
//
// Description: <Write the program description here.>
//
// What's on your mind about this lab? <Write what you've learned here.>
//
// Author: Alyssa Richie
//
// Date: 05/08/2021
//
// IDE Used: CodeBlocks
//
// Template Date: 04/06/2021
//******************************************************************************

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Define a data structure named Sale.
// The structure has the following fields:
struct Sale {
    string itemName;  // name of sale item
    int quantity;     // quantity of item
    double unitPrice; // unit price of item
};

//function prototypes
Sale *getUserInput(int *items);
double getItemTotal(const Sale *sale);
double getTotal(const Sale *salePtr, int items);
void printData(const Sale *salePtr, int items);

int main()
{
    int items {0};
    Sale* users = getUserInput(&items);
    printData(users, items);
    delete [] users;

    return 0;
}

//******************************************************************************
//* getUserInput - This function gets a list of Sale item from the user.
//*   This functions dynamically allocates an array and returns a pointer
//*   to the allocated array. The caller is responsible for deleting
//*   the allocated array.
//*
//* Parameters:
//*   items - pointer to the callers variable for item counts.
//*
//* Return:
//*   The pointer to the first Sale item in the allocated array of Sale
//*   items.
//*
//******************************************************************************
Sale *getUserInput(int *items)
{
    int userItems {0};
    cin >> userItems;

    //cout << "userItems " << userItems << endl;
    Sale *ptr = new Sale[userItems] {};

    Sale *tptr = ptr;
    while (tptr < ptr + userItems) {
        // This is necessary because the previous operation is a >>
        // that left the newline in the buffer.
        cin.ignore();
        getline(cin, tptr->itemName);
        cin >> tptr->quantity;
        cin >> tptr->unitPrice;
        ++tptr;
    }
    *items = userItems;
    return ptr;
}

//******************************************************************************
//* getItemTotal - This function returns the total price of one
//*     sale item.
//*
//* Parameters:
//*   salePtr - pointer to one sale item
//*
//* Return:
//*   The total price of the item.
//*
//******************************************************************************
double getItemTotal(const Sale *sale)
{
    //variable used to make output easier
    double itemTotal = 0;

    //gets quantity of sale object multiplied by unit price
    itemTotal = sale->quantity * sale->unitPrice;
    return itemTotal;
}

//******************************************************************************
//* getTotal - This function returns the total price of the sale items.
//*
//* Parameters:
//*   salePtr - pointer to the first sale item
//*   items - number of sale items
//*
//* Return:
//*   The total price of the items.
//*
//******************************************************************************
double getTotal(const Sale *salePtr, int items)
{
    double total = 0;
    //goes through array (Backwards - salePtr is at last iteration from the
    // for loop in printData function)
    //   for(int ptrIndex = items; ptrIndex >= 0; ptrIndex--)
   for(int current = 0; current < items; current++)
   {
       //calls getTotalItem for current object pointer is pointing to
       //then adds the total price for the current object to overall total
        total += getItemTotal(salePtr);
        salePtr--;
   }
    return total;
}

//******************************************************************************
//* printData - This function prints a report of the sale items.
//*
//* Parameters:
//*   salePtr - pointer to the first sale item
//*   items - number of sale items
//*
//* Return:
//*   void
//*
//******************************************************************************
void printData(const Sale *salePtr, int items)
{
    //create temporary copy of pointer for purposes of iterating through
    //the for loop
    const Sale *tempSalePtr = salePtr;
    //prints report heading
   cout << "\nSales" << endl;
   cout << "Item" << setw(18) << "Qty" << setw(9) << "Unit" << setw(8) << "Amt";
   cout << endl;
   cout << setw(40) << setfill('=') << "=" << endl;
   cout << setfill(' ');

   //Forces program to always have money in a correct format (dollars.cents)
   cout << fixed << setprecision(2) << showpoint;


   //Goes through the array and prints item, quantity, unit price
    // and amount price
   for(int index = 0; index < items; index++)
   {
       //print statements and formatting
       //uses left alignment for item names and right alignment for prices
       cout << setw(18) << left << tempSalePtr->itemName << right << setw(4)
            << tempSalePtr->quantity << setw(9)
            << tempSalePtr->unitPrice << setw(9) << getItemTotal(tempSalePtr)
            << endl;
       tempSalePtr++;
   }

   //resets alignment to left
   cout << left << endl;
   //prints out overall total of all item amounts
   cout << setw(32) << "Total: " << right << setw(8) << getTotal(salePtr, items);
}
