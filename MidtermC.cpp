#include <iostream>
#include <iomanip>

/*
Midterrm C
Author: Alyssa Richie
Program purpose: Create a pc store
*/


using namespace std;

int main()
{
    //declare variables used in selection of computer
    char selectedModel;
    char shipping;
    double shipcost;
    int memory;
    int quantity;
    double price;
    double totalPrice;
    double taxAmount;
    double totalOrder;

    //sales tax rate for purchasing computer as decimal
    const double TAX_RATE = 9.75;

    //displays welcoming message and store's menu
    cout << "Welcome to the Alyssa Richie PC Store. Here is the price list: " << endl << endl << endl;
    cout << "Memory Size/Brand" << setw(15) << "HP" << setw(15) << "Dell" << setw(15) <<"Lenovo" << endl;
    cout << setw(15) << "16 gigabytes" << setw(19) << "899.99" << setw(14) << "869.99" << setw(14) << "809.99" << endl;
    cout << setw(15) << "8 gigabytes" << setw(19) << "819.99" << setw(14) << "779.99" << setw(14) << "739.99" << endl << endl;

    //Asks for PC brand selection
    cout << "Enter the brand name of the PC (D for Dell, H for HP, L for Lenovo): ";
    cin >> selectedModel;

    //checks if user's PC brand selection is valid
    if (selectedModel != 'D' && selectedModel != 'H' && selectedModel != 'L')
    {
        cout << "\nInvalid brand code. Chose D, H, or L.";
        return 0;
    }

    //Asks for memory size
    cout << "\nEnter the memory size of the PC (8 or 16 gigabytes): ";
    cin >> memory;

    //checks if user's memory choice is valid
    if (memory != 8 && memory != 16)
    {
        cout << "\nInvalid memory size. Chose 8 or 16.";
        return 0;
    }

    //Asks for quantity of PCs
    cout << "\nEnter PC quantity want to buy: ";
    cin >> quantity;

    //checks if user's quantity choice is valid
    if (quantity < 0)
    {
        cout << "\nInvalid quantity!" << endl;
        return 0;
    }
    else if (quantity > 10)
    {
        cout << "\nInvalid quantity! It cannot exceed 10" << endl;
        return 0;
    }


    //assigns prices / brands to price variable (for calculations)
    if (selectedModel == 'D' && memory == 8)
    {
        price = 779.99;
    }
    else if (selectedModel == 'D' && memory == 16)
    {
         price = 869.99;
    }
    else if (selectedModel == 'H' && memory == 8)
    {
         price = 779.99;
    }
    else if (selectedModel == 'H' && memory == 16)
    {
         price = 779.99;
    }
    else if (selectedModel == 'L' && memory == 8)
    {
        price = 779.99;
    }
    else
    {
         price = 779.99;
    }




    //Calculation for totalPrice, taxAmount, and totalOrder
    totalPrice = price * quantity;
    taxAmount = totalPrice * (TAX_RATE * 0.01);
    totalOrder = totalPrice + taxAmount;


    //formats prices to all be two digits after decimal place
    cout << fixed << setprecision(2);

    //output prices / sales tax. Different widths so they're all lined up
    if (selectedModel == 'D')
    {
        cout << "\nThe item price for (" << quantity << " x Dell) is " << setw(3) << "$" << setw(10) << totalPrice << endl;
        cout << "The sales tax is " << setw(19) << "$" << setw(10) << taxAmount << endl << endl;
    }
    else if (selectedModel == 'H')
    {
        cout << "\nThe item price for (" << quantity << " x HP) is " << setw(3) << "$" << setw(10) << totalPrice << endl;
        cout << "The sales tax is " << setw(17) << "$" << setw(10) << taxAmount << endl << endl;
    }
    else
    {
        cout << "\nThe item price for (" << quantity << " x Lenovo) is " << setw(3) << "$" << setw(10) << totalPrice << endl;
        cout << "The sales tax is " << setw(21) << "$" << setw(10) << taxAmount << endl << endl;
    }


    //Asks for shipping method
    cout << "Enter shipping method (S for Standard, E for Express): ";
    cin >> shipping;

    //Checks if input is valid
    if (shipping == 'S')
    {
        totalOrder = totalPrice + taxAmount + 10.00;
        shipcost = 10.00;
    }
    else if (shipping == 'E')
    {
        totalOrder = totalPrice + taxAmount + 20.00;
        shipcost = 20.00;
    }
    else
    {
        cout << "\nInvalid shipping method. Select S or E.";
        return 0;
    }

    // final recipt
    if (selectedModel == 'D')
    {
         cout << "Shipping cost is " << setw(19) << "$" << setw(10) << shipcost << endl << endl;
         cout << "Your total bill is" << setw(18) << "$" << setw(10) << totalOrder;
    }
    else if (selectedModel == 'H')
    {
         cout << "Shipping cost is " << setw(17) << "$" << setw(10) << shipcost << endl << endl;
         cout << "Your total bill is" << setw(16) << "$" << setw(10) << totalOrder;
    }
    else
    {
         cout << "Shipping cost is " << setw(21) << "$" << setw(10) << shipcost << endl << endl;
         cout << "Your total bill is" << setw(20) << "$" << setw(10) << totalOrder;
    }

    return 0;
}
