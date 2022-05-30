#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

/*
Homework 6
Author: Alyssa Richie
Program purpose: Create simple computer web store that sells 5 different computer models
*/


int main()
{
    //Declares constants
    //sales tax rate for purchasing computer as decimal
    const double TAX_RATE = 9.75;

    //computer "A" Acer Model 100-AC high and low price
    const int PRICE_A_LOW = 500;
    const int PRICE_A_HIGH = 580;

    //computer "B" Lenovo Model 200-XU high and low price
    const int PRICE_B_LOW = 560;
    const int PRICE_B_HIGH = 635;

    //computer "C" Asus Model 300-KN high and low price
    const int PRICE_C_LOW = 600;
    const int PRICE_C_HIGH = 675;

    //computer "C" HP Model 400-TR  high and low price
    const int PRICE_D_LOW = 640;
    const int PRICE_D_HIGH = 705;

    //computer "D" Dell Model 500-DB high and low price
    const int PRICE_E_LOW = 680;
    const int PRICE_E_HIGH = 745;

    //declares variables used for selection of computer, quantity, and price
    int quantity;
    char selectedModel;
    double price;
    double totalPrice;
    double taxAmount;
    double totalOrder;

    //displays welcoming message and store's menu
    cout << "Welcome to the Alyssa Richie PC Store!" << endl;
    cout << "These are our current products:" << endl << endl;
    cout << "A- Acer Model 100-AC      - Price: $500 - $580" << endl;
    cout << "B- Lenovo Model 200-XU    - Price: $560 - $635" << endl;
    cout << "C- Asus Model 300-KN      - Price: $600 - $675" << endl;
    cout << "D- HP Model 400-TR        - Price: $640 - $705" << endl;
    cout << "E- Dell Model 500-DB      - Price: $680 - $745" << endl << endl;
    cout << "Enter a menu item (A, B, C, D, E) followed by a space and quantity: ";

    //gets user input
    cin >> selectedModel >> quantity;

    //checks if there is a valid amount of
    if (quantity < 0)
    {
        cout << "Invalid quantity!" << endl;
        return 0;
    }

    // makes generator random price every time within range
    srand(time(0));

    //generate price based on selection
    if (selectedModel == 'A')
    {
        price = rand() % (PRICE_A_HIGH - PRICE_A_LOW + 1) + PRICE_A_LOW;
    }
    else if (selectedModel == 'B')
    {
        price = rand()  % (PRICE_B_HIGH - PRICE_B_LOW + 1) + PRICE_B_LOW;
    }
    else if (selectedModel == 'C')
    {
        price = rand() % (PRICE_C_HIGH - PRICE_C_LOW + 1) + PRICE_C_LOW;
    }
    else if (selectedModel == 'D')
    {
        price = rand() % (PRICE_D_HIGH - PRICE_D_LOW + 1) + PRICE_D_LOW;
    }
    else if (selectedModel == 'E')
    {
        price = rand() % (PRICE_E_HIGH - PRICE_E_LOW + 1) + PRICE_E_LOW;
    }
    else
    {
        cout << "Invalid menu item!" << endl;
        return 0;
    }

    //Calculation for totalPrice, taxAmount, and totalOrder
    totalPrice = price * quantity;
    taxAmount = totalPrice * (TAX_RATE * 0.01);
    totalOrder = totalPrice + taxAmount;

    //outputs receipt
    cout << "\nHere is your receipt: " << endl << endl;
    //formats prices to all be two digits after decimal place
    cout << fixed << setprecision(2);
    cout << setw(20) << "Unit price: $" << setw(15) << price << endl;
    cout << setw(20) << "Total price: $" << setw(15) << totalPrice << endl;
    cout << setw(20) << "Tax amount: $" << setw(15) << taxAmount << endl;
    cout << setw(20) << "Total order: $" << setw(15) << totalOrder << endl;

    return 0;
}
