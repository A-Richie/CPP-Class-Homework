//******************************************************************************
// Program name: Lab3A
//
// Description: This program processes nutrition information with a class.
//
// What's on your mind about this lab? I learned how there is a difference 
//                                      between inline and outside the class
//
// Author: Alyssa Richie
//
// Date: 05/28/2021
//
// IDE Used: Visual Studio Code
//
// Template Date: 04/06/2021
//******************************************************************************

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

class NutritionData 
{
    private:
        //food name
        string foodName;
        //size of serving
        int servingSize;
        //calories from carbohydrates
        double calFromCarb;
        //calories from fat
        double calFromFat;
        //calories from protein
        double calFromProtein;
        
    public:
        //default constructor
        NutritionData() 
        {
            foodName = "";
            servingSize = 0;
            calFromCarb = 0.0;
            calFromFat = 0.0;
            calFromProtein = 0.0;
        };

        //mutator member functions

        //mutator function to set the private foodName variable
        void setFoodName(string tempFoodVal) 
            { foodName = tempFoodVal; }

        //mutator function to set private servingSize variable
        void setServingSize(int tempServingSize) 
            { servingSize = tempServingSize; }

        //mutator function to set private calFromCarb variable
        void setCalFromCarb(double tempCalFromCarb)
            {  calFromCarb = tempCalFromCarb; }

        //mutator function to set private calFromFat variable
        void setCalFromFat(double tempCalFromFat)
            {  calFromFat = tempCalFromFat; }

        //mutator function to set calFromProtein variable
        void setCalFromProtein(double tempCalFromProtein)
            {  calFromProtein = tempCalFromProtein; }


        //accessor member functions

        //return foodName variable
        string getFoodName() const
            { return foodName; }

        //return servingSize variable
        int getServingSize() const
            { return servingSize; }

        //return calFromCarb variable
        double getCalFromCarb() const
            { return calFromCarb; }
        
        //return calFromFat variable
        double getCalFromFat() const
            { return calFromFat; }
        
        //return calFromProtein variable
        double getCalFromProtein() const
            { return calFromProtein; }

        //**********************************************************************
        //* Function name: getCaloriesPerServing
        //*
        //* This function gets the total calories 
        //*
        //* Parameters:
        //*    None
        //*
        //* Returns:
        //*    returns double - total of calories from carbs, fat and protein
        //**********************************************************************
        double getCaloriesPerServing() const;
};

//implementation of member function getCaloriesPerServing outside class
double NutritionData::getCaloriesPerServing() const 
{
    return calFromCarb + calFromFat + calFromProtein;
}


//function prototype for printNutritionData
void printNutritionData(const NutritionData *, int);


int main() 
{
    //tries to access text file
    ifstream infile;
    string fileName = "nutri.txt";
    infile.open(fileName);

    //if file doesn't open --> ends session
        //else --> continue with program
    if(!infile)
    {
        cout << "Failed to open " << fileName << endl;
    }
    else
    {
        //count the number of NutritionData
        int count {0};
        infile >> count;
        //skip newline character
        infile.ignore(1);

        //if everything is working; continue
        if (infile && count > 0)
        {
            //dynamically create array of NutritionData
            NutritionData *ptr = new NutritionData[count];

            //seperator character in text file
            const char DELIM = ',';

            //goes through each line in text file
            for(int index = 0; index < count; ++index)
            {
                //temparary string used to hold input from file 
                string tempString;
                // get Food name from file and adds it to array
                //reads line up to the deliminator (not including delim)
                getline(infile, tempString, DELIM);
                ptr[index].setFoodName(tempString);

                //get serving size from file and adds it to array
                getline(infile, tempString, DELIM);
                int tempServingSize = stoi(tempString);
                ptr[index].setServingSize(tempServingSize);

                //get calories from carbs from file and adds it to array
                getline(infile, tempString, DELIM);
                double tempCalFromCarb = stod(tempString);
                ptr[index].setCalFromCarb(tempCalFromCarb);

                //get calories from fat from file and adds it to array
                getline(infile, tempString, DELIM);
                double tempCalFromFat = stod(tempString);
                ptr[index].setCalFromFat(tempCalFromFat);

                //get calories from protein from file and adds it to array
                    //gets the last part of the line -> uses the new line char
                getline(infile, tempString);
                double tempCalFromProtein = stod(tempString);
                ptr[index].setCalFromProtein(tempCalFromProtein);
            }

            //start processing
            printNutritionData(ptr, count);

            //done processing. So it deletes allocated array
            delete [] ptr;
            ptr = nullptr;
        }
        else
        {   
            //error message if program can't get all the information
            cout << "Failed to get infromation from the file "
                 << fileName << endl;
        }

        //close the file
        infile.close();

    }

    return 0;
}

//******************************************************************************
//* Print an array of nutrition information.
//*
//* Parameters
//*     ptr - points to the first NutritionData in the array
//*     size - size of array
//* Return
//*     void
//******************************************************************************
void printNutritionData(const NutritionData *ptr, int size)
{
    //Formats output
    cout << fixed << showpoint << setprecision(1);

    //Iterate through array of NutritionData and print info of each item
    for(int index = 0; index < size; ++index)
    {
        cout << "Food Name: " << ptr[index].getFoodName() << endl;
        cout << "Serving Size: " << ptr[index].getServingSize() << " g" 
             << endl;
        cout << "Calories Per Serving: " << ptr[index].getCaloriesPerServing()
             << endl;
        cout << "Calories From Carb: " << ptr[index].getCalFromCarb() << endl;
        cout << "Calories From Fat: " << ptr[index].getCalFromFat() << endl;
        cout << "Calories From Protein: " << ptr[index].getCalFromProtein() 
             << endl;
        cout << endl;
    }
}
