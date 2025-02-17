// pc13.cpp : #15 Order Status pg 402
// Calculates the total price for number of spools sold and if stock 
// can cover the entire order. Final price includes $10 shipping per order and additional sales price
// if deemed neccesary by the user
// Adam Tucker
// HW #5
// 02/18/18

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void orderStatus();
void printReciept(int&, int&, double&, double = 10.0); // Prototype for stock price calculation


int main()
{
	
	bool working = true; // Sentinel for program
	char choice; // Choice for user to close or continue program
	do {
		cout << "Welcome to Middletown Wholesale Copper Wire Company" << endl; // Start of program
		
		orderStatus(); // Check current order status input by the user

		// Ask if the user wants to run the calculator again and set sentinel to close program
		cout << "\nWould you like to run the program again? (y or n)" << endl;
		cin >> choice;
		if (choice == 'n' || choice == 'N') {
			working = false; // User selected n for no so set sentinel to false to close program
			cout << "\nThank you! Program will now end. Goodbye..." << endl;
		}
		cout << "\n\n\n\n";
	} while (working);
	// end of do while loop

	return 0;
}

// Asks the user for number of spools order and number of spools currently in stock
void orderStatus() {

	int spoolsOrdered, spoolsInStock; // Input variable
	double additionalShipping;

	cout << "Please enter the number of spools to order" << endl;
	cin >> spoolsOrdered;
	// If user inputs negative or zero repeat until number is pos
	while (spoolsOrdered <= 0) {
		cout << "Please enter the number of spools that is 1 or greater!" << endl;
		cin >> spoolsOrdered;
	}
	cout << "Please enter the number of spools to currently in stock" << endl;
	cin >> spoolsInStock;
	// If user inputs negative or zero repeat until number is pos
	while (spoolsInStock <= 0) {
		cout << "Please enter the number of spools in stock that are 1 or greater!" << endl;
		cin >> spoolsInStock;
	}
	cout << "Please enter any additional shipping or 0 if no additional shipping is needed\n$";
	cin >> additionalShipping;
	// If user inputs negative or zero repeat until number is pos
	while (additionalShipping < 0.0) {
		cout << "Please enter positive number for additional shipping!\n$";
		cin >> additionalShipping;
	}
	printReciept(spoolsOrdered, spoolsInStock, additionalShipping); //Print the status
}

// Prints the reciept of the order
// Parameters are Number of Spools ordered, number of spools in stock, additional shipping and shipping price
void printReciept(int &myNumOrdered, int &myInStock, double &addShipping, double shippingPrice)
{
	double pricePerUnit = 100.0; // $100 is price per spool set to double if price changes to a number such as $149.99
	double salesPrice; // This is the result of checking number of spools ordered exceeds our spools in stock
						// Multiply the results in salesPrice by pricePerUnit and that equals total sales price

	double totalShipping = shippingPrice + addShipping; // Total price of all shipping costs for each order
	cout << "The number of ordered spools ready to ship from current stock is " << myInStock << endl;
	if (myNumOrdered > myInStock) { // If myNumOrdered is greater than total stock then there is a backorder
									// and we have sold our whole stock therefore sales price is price per * num in stock
		cout << "The number of ordered spools on backorder is " << (myNumOrdered - myInStock) << endl;
		salesPrice = (double)myInStock * pricePerUnit;
	}
	else { // Number ordered is not greater or equal too num in stock
		   // than we can fill the entire order therefore sales price * price per unit is sales price
		cout << "Stock is able to cover the entire order" << endl;
		salesPrice = (double)myNumOrdered * pricePerUnit;
	}
	cout << "Total selling price of the portion ready to ship is $" << salesPrice << endl; // Print sales price
	cout << fixed << setprecision(2);
	cout << "Total shipping and handling charges is $" << totalShipping << endl; // print total shipping
	cout << "Total Price of the order ready to ship is $" << totalShipping + salesPrice << endl; // print total

}
