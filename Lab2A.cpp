//******************************************************************************
// Program name: Lab2a
//
// Description: Gets a list of items from the user through <number items for
//              the whole list> <item's name> <quantity of item> <unit price>
//              which repeats item name, quantity and unit price for all items
//              Then outputs the cost for each item and overall total.
//
// What's on your mind about this lab? I thought about how a pointer can be
//              passed to another function within a function and it will still
//              retain what it was pointing to within the function. So I had to
//              think of a solution that made the pointer stay on the first
//              sale item.
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
    //goes through salesPtr
   for(int current = 0; current < items; current++)
   {
       //calls getTotalItem for current object pointer is pointing to
       //then adds the total price for the current object to overall total
        total += getItemTotal(salePtr);
        salePtr++;
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
    //create temporary copy of salePtr for purposes of iterating through
    //a for loop (so salePtr won't change to later sale items)
    const Sale *TEMP_SALE_PTR = salePtr;

    //prints report heading
   cout << "\nSales" << endl;
   cout << "Item" << setw(18) << "Qty" << setw(9) << "Unit" << setw(8) << "Amt";
   cout << endl;
   cout << setw(40) << setfill('=') << "=" << endl;
   cout << setfill(' ');

   //Forces program to always have money in a correct format (dollars.cents)
   cout << fixed << setprecision(2) << showpoint;

   //Goes through the TEMP_SALE_PTR and prints item, quantity, unit price
    // and amount price
   for(int index = 0; index < items; index++)
   {
       //print statements and formats output
       //uses left alignment for item names and right alignment for prices
       cout << setw(18) << left << TEMP_SALE_PTR->itemName << right << setw(4)
            << TEMP_SALE_PTR->quantity << setw(9)
            << TEMP_SALE_PTR->unitPrice << setw(9)
            << getItemTotal(TEMP_SALE_PTR) << endl;
       TEMP_SALE_PTR++;
   }

   //resets alignment to left
   cout << left << endl;

   //prints out overall total of all item amounts
    cout << setw(32) << "Total: " << right << setw(8)
         << getTotal(salePtr, items);
}
/* 5
Milk
1
5.85
Whole Wheat Bread
2
3.75
Napkin
3
2.35
Paper Towel
3
2.95
Soap
1
1.95

Sales
Item               Qty     Unit     Amt
========================================
Milk                 1     5.85     5.85
Whole Wheat Bread    2     3.75     7.50
Napkin               3     2.35     7.05
Paper Towel          3     2.95     8.85
Soap                 1     1.95     1.95

Total                              31.20

*/