//******************************************************************************
// Program name: Lab4a
//
// Description: The program instantiates and uses instances of a derived class 
//              with default and parameterized constructors.
//
// What's on your mind about this lab? I thought about how I got a chance to
//                              use the special syntax to initalize the 
//                                  private fields
//                         
//
// Author: Alyssa Richie
//
// Date: 06/05/2021
//
// IDE Used: Visual Studio Code
//
// Template Date: 04/06/2021
//******************************************************************************

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//class RealProperty
class RealProperty {
    private:
        //street address of property
        string streetAddress;
        //size of property in sqaurare feet
        int squareFootage;
        //taxes on the property
        double taxes;

    public:
        //default class constructor and inialization of the data members
            //using the data member initialization list
        RealProperty(): streetAddress(""), squareFootage(0), taxes(0.0) {

        };
        //paramatized class constructor initalize with user input
        RealProperty(string streetVal, int propSize, double taxRate): 
        streetAddress(streetVal), taxes(taxRate) 
        { setSquareFootage(propSize); }
        
        //mutator function declarations

        //mutator function to set the private streetAddress variable
        void setStreetAddress(string streetVal);

        //mutator function to set the private squareFootage variable
        void setSquareFootage(int propSize);

        //mutator function to set the private taxes variable
        void setTaxes(double taxRate);

        //accessor function (inline)

        //return streetAddress variable
        string getStreetAddress() const
            { return streetAddress; }

        //return squareFootage variable
        int getSquareFootage() const
            { return squareFootage; }

        //return taxes variable
        double getTaxes() const
            { return taxes; }

};

//implementation of mutaor method setStreetAddress
void RealProperty::setStreetAddress(string streetVal)
{
    streetAddress = streetVal;
};

//implementation of mutaor method setSquareFootage
void RealProperty::setSquareFootage(int propSize)
{   
    //checks validity of square footage 
    if(propSize >= 0)
    {
        squareFootage = propSize;
    }
    else
    {
        cout << "Square footage must be a positive number." << endl;
        exit(EXIT_FAILURE);
    }
};

//implementation of mutaor method setTaxes
void RealProperty::setTaxes(double taxRate)
{
    //checks validity of tax rate just in case
    if(taxRate < 0)
    {
        cout << "Tax rate can't be negative." << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        taxes = taxRate;
    }
};

// A derived class of RealProperty

class Apartment: public RealProperty
{
    private:
        //rent of the porperty every month
        double monthlyRent;
    public:
         //default class constructor and inialization of the data members
            //using the data member initialization list
        Apartment(): RealProperty(), monthlyRent(0.0) {}

        //paramatized class constructor
        Apartment(string streetVal, int propSize, double taxRate, double rent):
        RealProperty(streetVal, propSize, taxRate), monthlyRent(rent) {}

        //mutator method to set monthlyRent variable
        void setMonthlyRent(double rent) { monthlyRent = rent; }

        //accessor method to retrive monthlyRent variable
        double getMonthlyRent() const { return monthlyRent; }
};

// Function prototypes

// Declares a function named displayPropertyInfo that receives one reference 
// to const parameter representing a real property.
// The function has no return value.
void displayPropertyInfo (const RealProperty &rp);

// Declares a function named displayApartmentInfo that receives one reference 
// to const parameter representing an apartment. 
// The function has no return value.
void displayApartmentInfo (const Apartment &apt);


int main() 
{
    //create object (apartment type)
    Apartment lakeside;

    //seperator character in user input
    const char DELIM = ',';

    //temparary strings used to hold user input
    string address;
    string squareFeet;
    string taxRate;
    string rentAmount;
    int numSquareFeet;
    double numTaxAmount;
    double numRentAmount;

    // get address from input and adds it to array
    //reads line up to the deliminator (not including delim)
    //sets object's address
    getline(cin, address, DELIM);
    lakeside.setStreetAddress(address);

    // get sqfeet from input and adds it to array
    //reads line up to the deliminator (not including delim)
      //sets object's square feet
    getline(cin, squareFeet, DELIM);
    numSquareFeet = stoi(squareFeet);
    lakeside.setSquareFootage(numSquareFeet);

    // get tax rate from input and adds it to array
    //reads line up to the deliminator (not including delim)
      //sets object's tax amount
    getline(cin, taxRate, DELIM);
    numTaxAmount = stod(taxRate);
    lakeside.setTaxes(numTaxAmount);

    // get address from input and adds it to array
    //reads to end of the line
    //set objects monthly rent
    getline(cin, rentAmount);
    numRentAmount = stod(rentAmount);
    lakeside.setMonthlyRent(numRentAmount);


    //prints information about the property
    displayPropertyInfo(lakeside);

    //seperates property information and apartment information
    cout << endl;

    //displays information about the apartment
    displayApartmentInfo(lakeside);    
    
    return 0;
}

//******************************************************************************
//* Print the real property information.
//*
//* Parameter
//*     rp - a reference to const referencing to caller's RealProperty
//*          variable.
//*
//* Return
//*     void
//******************************************************************************
void displayPropertyInfo(const RealProperty &rp) 
{
    cout << "Property is located at: " << rp.getStreetAddress() << endl;
    cout << "Square footage: " << rp.getSquareFootage() << endl;
    //standardizes any strange numbers
    cout << "Taxes: " << rp.getTaxes() << endl;
}

//******************************************************************************
//* Print the apartment information.
//*
//* Parameter
//*     rp - a reference to const referencing to caller's Apartment
//*          variable.
//*
//* Return
//*     void
//******************************************************************************
void displayApartmentInfo(const Apartment &apt) 
{
    cout << "Property is located at: " << apt.getStreetAddress() << endl;
    cout << "Square footage: " << apt.getSquareFootage() << endl;
    cout << "Taxes: " << apt.getTaxes() << endl;
    cout << setprecision(2) << fixed;
    cout << "Monthly rent: " << apt.getMonthlyRent() << endl;
}

