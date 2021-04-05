// Project3_CalculatingShippingCost.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <algorithm>

using namespace std;


// define USA shipping costs
const double USA_SHIP_ORDER_TOTAL_50_OR_LESS = 6.00;
const double USA_SHIP_ORDER_TOTAL_50_01_TO_100 = 9.00;
const double USA_SHIP_ORDER_TOTAL_100_01_TO_150 = 12.00;
const double SHIP_ORDER_TOTAL_OVER_150 = 0.00;

// Define Canada shipping costs 
const double CAN_SHIP_ORDER_TOTAL_50_OR_LESS = 8.00;
const double CAN_SHIP_ORDER_TOTAL_50_01_TO_100 = 12.00;
const double CAN_SHIP_ORDER_TOTAL_100_01_TO_150 = 15.00;


// Define Australia Shipping costs
const double AUS_SHIP_ORDER_TOTAL_50_OR_LESS = 10.00;
const double AUS_SHIP_ORDER_TOTAL_50_01_TO_100 = 14.00;
const double AUS_SHIP_ORDER_TOTAL_100_01_TO_150 = 17.00;

// define shipping costs to ship to Mars
const double MARS_SHIP_ORDER_TOTAL_50_OR_LESS = 6000.00;
const double MARS_SHIP_ORDER_TOTAL_50_01_TO_100 = 7500.00;
const double MARS_SHIP_ORDER_TOTAL_100_01_TO_150 = 8000.00;
const double MARS_SHIP_ORDER_TOTAL_OVER_150 = 8500.00;

const double FRAGILE_COST = 2.00;

int main()
{
    //Declare file stream variable 
    ofstream outData;


    // Open file stream text file
    outData.open("Order.txt");
    if (!outData)
    {
        cout << "There was a problem opening the file." << endl;  // Generate an error message if the file was not successfully opened
        return -1; //quit
    }


    // variables used in stream manipulators
    string s = " ";
    string c = ":";
    string z = "";
    string title = "ITCS 2530 Programming Assignment for Week #3";
    string itemName;
    string isFragile;
    double orderTotal;
    string orderDestination;
    string ending = "Thank You!";

    cout << fixed << showpoint << setprecision(2); // decimal place is set to 2 (for money calculations)


    //Formats and displays the heading/title  of the Program
    cout << setfill('.');
    cout << setw(50) << s << endl; // Displays a row of dots
    cout << title << endl;  // title is displayed
    cout << setw(50) << s << endl; // displays a row of dots beneath the title
    cout << endl;
    cout << endl;


    // Prompt user to enter item name and display it on screen
    cout << left;
    cout << setfill('.');
    cout << setw(48) << "Please enter the item name (no spaces)" << c << itemName;
    cin >> itemName;
    transform(itemName.begin(), itemName.end(), itemName.begin(), ::toupper);    // Transform the user-input to all uppercase letter


    // Prompt user to enter whether item is fragile and display it on screen
    cout << setw(48) << "Is the item fragile? (y=yes/n=no)" << c << isFragile;
    cin >> isFragile;

    if (isFragile == "Y" || isFragile == "y" || isFragile == "n" || isFragile == "N") {

    }
    else {
        cout << "\nInvalid output, exiting";
        exit(EXIT_FAILURE);
    }

    transform(isFragile.begin(), isFragile.end(), isFragile.begin(), ::toupper); // Transform the user-input to all uppercase letter

    // Prompt user to enter order total ,display it
    cout << setw(48) << "Enter your order total" << c;
    cin >> orderTotal;

    //Prompt user to enter destination 
    cout << setw(48) << "Enter your destination. (usa/can/aus)" << c;
    cin >> orderDestination;
    cout << endl;

    // Restrict the intput of the shipping location to be only three countries(both upper and lowercase), otherwise system exits
    if (orderDestination == "USA" || orderDestination == "CAN" || orderDestination == "AUS" || orderDestination == "usa" || orderDestination == "can" || orderDestination == "aus" || orderDestination == "MARS" || orderDestination == "mars") {

    }
    else {
        cout << "\nInvalid output, exiting";
        exit(EXIT_FAILURE);
    }



    transform(orderDestination.begin(), orderDestination.end(), orderDestination.begin(), ::toupper);  //Changes  orderDestination to all uppercase

    transform(itemName.begin(), itemName.end(), itemName.begin(), ::toupper);
    cout << setw(39) << "Your item is" << itemName;  // displays item on the screen

    // Display where the item is being shipped to on scrren
    //transform(orderDestination.begin(), orderDestination.end(), orderDestination.begin(), ::toupper);


    outData.open("Order.txt");  // opens the output file "Order.txt"


    cout << endl;

    string d = "$";  // used to display $ before monetary values in stream manipulation

    // If-statements calculate total shipping costs, shipping costs based on whether it is fragile and country it is being shipped to
    if (isFragile == "Y" && orderDestination == "USA") {
        if (orderTotal < 50.00) {
            orderTotal = orderTotal + USA_SHIP_ORDER_TOTAL_50_OR_LESS + FRAGILE_COST;
            cout << setw(39) << "Your shipping costs is" << d << USA_SHIP_ORDER_TOTAL_50_OR_LESS + FRAGILE_COST;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }
        else if (orderTotal >= 50.01 && orderTotal <= 100.1) {
            orderTotal = orderTotal + USA_SHIP_ORDER_TOTAL_50_01_TO_100 + FRAGILE_COST;
            cout << setw(39) << "Your shipping costs is" << d << USA_SHIP_ORDER_TOTAL_50_01_TO_100 + FRAGILE_COST;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }
        else if (orderTotal >= 100.01 && orderTotal <= 150.00) {
            orderTotal = orderTotal + USA_SHIP_ORDER_TOTAL_100_01_TO_150 + FRAGILE_COST;
            cout << setw(39) << "Your shipping costs is" << d << USA_SHIP_ORDER_TOTAL_100_01_TO_150 + FRAGILE_COST;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }
        else {
            orderTotal = orderTotal + SHIP_ORDER_TOTAL_OVER_150 + FRAGILE_COST;
            cout << setw(39) << "Your shipping costs is" << d << SHIP_ORDER_TOTAL_OVER_150 + FRAGILE_COST;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }

    }

    // If being shipped to USA and the shipment is not fragile.....
    else if (isFragile == "N" && orderDestination == "USA") {
        if (orderTotal < 50.00) {
            orderTotal = orderTotal + USA_SHIP_ORDER_TOTAL_50_OR_LESS;
            cout << setw(39) << "Your shipping costs is" << d << USA_SHIP_ORDER_TOTAL_50_OR_LESS;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }
        else if (orderTotal >= 50.01 && orderTotal <= 100.1) {
            orderTotal = orderTotal + USA_SHIP_ORDER_TOTAL_50_01_TO_100;
            cout << setw(39) << "Your shipping costs is" << d << USA_SHIP_ORDER_TOTAL_50_01_TO_100;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }
        else if (orderTotal >= 100.01 && orderTotal <= 150.0) {
            orderTotal = orderTotal + USA_SHIP_ORDER_TOTAL_100_01_TO_150;
            cout << setw(39) << "Your shipping costs is" << d << USA_SHIP_ORDER_TOTAL_100_01_TO_150;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }
        else {
            orderTotal = orderTotal + SHIP_ORDER_TOTAL_OVER_150;
            cout << setw(39) << "Your shipping costs is" << d << SHIP_ORDER_TOTAL_OVER_150;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }
    }

    // If being shipped to CAN and the shipment is fragile.....
    if (isFragile == "Y" && orderDestination == "CAN") {
        if (orderTotal < 50.00) {
            orderTotal = orderTotal + CAN_SHIP_ORDER_TOTAL_50_OR_LESS + FRAGILE_COST;
            cout << setw(39) << "Your shipping costs is" << d << CAN_SHIP_ORDER_TOTAL_50_OR_LESS + FRAGILE_COST;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }
        else if (orderTotal >= 50.01 && orderTotal <= 100.1) {
            orderTotal = orderTotal + CAN_SHIP_ORDER_TOTAL_50_01_TO_100 + FRAGILE_COST;
            cout << setw(39) << "Your shipping costs is" << d << CAN_SHIP_ORDER_TOTAL_50_01_TO_100 + FRAGILE_COST;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }
        else if (orderTotal >= 100.01 && orderTotal <= 150.00) {
            orderTotal = orderTotal + CAN_SHIP_ORDER_TOTAL_100_01_TO_150 + FRAGILE_COST;
            cout << setw(39) << "Your shipping costs is" << d << CAN_SHIP_ORDER_TOTAL_100_01_TO_150 + FRAGILE_COST;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }
        else {
            orderTotal = orderTotal + SHIP_ORDER_TOTAL_OVER_150 + FRAGILE_COST;
            cout << setw(39) << "Your shipping costs is" << d << SHIP_ORDER_TOTAL_OVER_150 + FRAGILE_COST;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }

    }

    // If being shipped to CAN and the shipment is not fragile.....
    if (isFragile == "N" && orderDestination == "CAN") {
        if (orderTotal < 50.00) {
            orderTotal = orderTotal + CAN_SHIP_ORDER_TOTAL_50_OR_LESS;
            cout << setw(39) << "Your shipping costs is" << d << CAN_SHIP_ORDER_TOTAL_50_OR_LESS;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }
        else if (orderTotal >= 50.01 && orderTotal <= 100.1) {
            orderTotal = orderTotal + CAN_SHIP_ORDER_TOTAL_50_01_TO_100;
            cout << setw(39) << "Your shipping costs is" << d << CAN_SHIP_ORDER_TOTAL_50_01_TO_100;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }
        else if (orderTotal >= 100.01 && orderTotal <= 150.00) {
            orderTotal = orderTotal + CAN_SHIP_ORDER_TOTAL_100_01_TO_150;
            cout << setw(39) << "Your shipping costs is" << d << CAN_SHIP_ORDER_TOTAL_100_01_TO_150;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }
        else {
            orderTotal = orderTotal + SHIP_ORDER_TOTAL_OVER_150;
            cout << setw(39) << "Your shipping costs is" << d << SHIP_ORDER_TOTAL_OVER_150;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }

    }

    // If being shipped to AUS and the shipment is fragile.....
    if (isFragile == "Y" && orderDestination == "AUS") {
        if (orderTotal < 50.00) {
            orderTotal = orderTotal + AUS_SHIP_ORDER_TOTAL_50_OR_LESS + FRAGILE_COST;
            cout << setw(39) << "Your shipping costs is" << d << AUS_SHIP_ORDER_TOTAL_50_OR_LESS + FRAGILE_COST;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }
        else if (orderTotal >= 50.01 && orderTotal <= 100.1) {
            orderTotal = orderTotal + AUS_SHIP_ORDER_TOTAL_50_01_TO_100 + FRAGILE_COST;
            cout << setw(39) << "Your shipping costs is" << d << AUS_SHIP_ORDER_TOTAL_50_01_TO_100 + FRAGILE_COST;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }
        else if (orderTotal >= 100.01 && orderTotal <= 150.00) {
            orderTotal = orderTotal + AUS_SHIP_ORDER_TOTAL_100_01_TO_150 + FRAGILE_COST;
            cout << setw(39) << "Your shipping costs is" << d << AUS_SHIP_ORDER_TOTAL_100_01_TO_150 + FRAGILE_COST;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }
        else {
            orderTotal = orderTotal + SHIP_ORDER_TOTAL_OVER_150 + FRAGILE_COST;
            cout << setw(39) << "Your shipping costs is" << d << SHIP_ORDER_TOTAL_OVER_150 + FRAGILE_COST;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }

    }

    // AUS SHIPPING COSTS WITHOUT FRAGILE
    if (isFragile == "N" && orderDestination == "AUS") {
        if (orderTotal < 50.00) {
            orderTotal = orderTotal + AUS_SHIP_ORDER_TOTAL_50_OR_LESS;
            cout << setw(39) << "Your shipping costs is" << d << AUS_SHIP_ORDER_TOTAL_50_OR_LESS;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }
        else if (orderTotal >= 50.01 && orderTotal <= 100.1) {
            orderTotal = orderTotal + AUS_SHIP_ORDER_TOTAL_50_01_TO_100;
            cout << setw(39) << "Your shipping costs is" << d << AUS_SHIP_ORDER_TOTAL_50_01_TO_100;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }
        else if (orderTotal >= 100.01 && orderTotal <= 150.00) {
            orderTotal = orderTotal + AUS_SHIP_ORDER_TOTAL_100_01_TO_150;
            cout << setw(39) << "Your shipping costs is" << d << AUS_SHIP_ORDER_TOTAL_100_01_TO_150;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }
        else {
            orderTotal = orderTotal + SHIP_ORDER_TOTAL_OVER_150 + FRAGILE_COST;
            cout << setw(39) << "Your shipping costs is" << d << SHIP_ORDER_TOTAL_OVER_150 + FRAGILE_COST;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }

    }

    if (isFragile == "Y" && orderDestination == "MARS") {
        if (orderTotal < 50.00) {
            orderTotal = orderTotal + MARS_SHIP_ORDER_TOTAL_50_OR_LESS + FRAGILE_COST;
            cout << setw(39) << "Your shipping costs is" << d << MARS_SHIP_ORDER_TOTAL_50_OR_LESS + FRAGILE_COST;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }
        else if (orderTotal >= 50.01 && orderTotal <= 100.1) {
            orderTotal = orderTotal + MARS_SHIP_ORDER_TOTAL_50_01_TO_100 + FRAGILE_COST;
            cout << setw(39) << "Your shipping costs is" << d << MARS_SHIP_ORDER_TOTAL_50_01_TO_100 + FRAGILE_COST;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }
        else if (orderTotal >= 100.01 && orderTotal <= 150.00) {
            orderTotal = orderTotal + MARS_SHIP_ORDER_TOTAL_100_01_TO_150 + FRAGILE_COST;
            cout << setw(39) << "Your shipping costs is" << d << MARS_SHIP_ORDER_TOTAL_100_01_TO_150 + FRAGILE_COST;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }
        else {
            orderTotal = orderTotal + MARS_SHIP_ORDER_TOTAL_OVER_150 + FRAGILE_COST;
            cout << setw(39) << "Your shipping costs is" << d << MARS_SHIP_ORDER_TOTAL_OVER_150 + FRAGILE_COST;
            cout << setw(40) << "\nYou are shipping to" << orderDestination;
            cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
        }

        if (isFragile == "N" && orderDestination == "MARS") {
            if (orderTotal < 50.00) {
                orderTotal = orderTotal + MARS_SHIP_ORDER_TOTAL_50_OR_LESS;
                cout << setw(39) << "Your shipping costs is" << d << MARS_SHIP_ORDER_TOTAL_50_OR_LESS;
                cout << setw(40) << "\nYou are shipping to" << orderDestination;
                cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
            }
            else if (orderTotal >= 50.01 && orderTotal <= 100.1) {
                orderTotal = orderTotal + MARS_SHIP_ORDER_TOTAL_50_01_TO_100;
                cout << setw(39) << "Your shipping costs is" << d << MARS_SHIP_ORDER_TOTAL_50_01_TO_100;
                cout << setw(40) << "\nYou are shipping to" << orderDestination;
                cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
            }
            else if (orderTotal >= 100.01 && orderTotal <= 150.00) {
                orderTotal = orderTotal + MARS_SHIP_ORDER_TOTAL_100_01_TO_150;
                cout << setw(39) << "Your shipping costs is" << d << MARS_SHIP_ORDER_TOTAL_100_01_TO_150;
                cout << setw(40) << "\nYou are shipping to" << orderDestination;
                cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
            }
            else {
                orderTotal = orderTotal + MARS_SHIP_ORDER_TOTAL_OVER_150;
                cout << setw(39) << "Your shipping costs is" << d << MARS_SHIP_ORDER_TOTAL_OVER_150;
                cout << setw(40) << "\nYou are shipping to" << orderDestination;
                cout << setw(40) << "\nYour total shipping costs are" << d << orderTotal;
            }
        }



        outData << itemName << " " << orderTotal << " " << orderDestination << " ";


        // Display the message "thank you!" on the screen 
        cout << endl;
        cout << endl;
        cout << setfill('-');
        cout << setw(39) << z << ending << setw(10) << endl;

        outData.close();  // close the text file 


        system("pause"); // pauses screen
        return 0;
    }
}
