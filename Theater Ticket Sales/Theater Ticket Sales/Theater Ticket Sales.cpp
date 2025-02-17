// Theater Ticket Sales.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TicketManager.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

static bool userChoice();

int isGoodInput(int, int); // helper function to prompt user for input and check of negative number


int main()
{
	bool isDone = false;
	int numSeatsDesired = 0, desiredRowNum, startingSeatNum ;
	TicketManager ticketManager = TicketManager();

	cout << "Welcome to Group 3's Theater!" << endl;
	cout << "Type the number for the menu choice you want then press 'Enter' \n" << endl;

	cout << fixed << setprecision(2);
	while (!isDone) {
		int menuChoice;

		cout << "1 - Display Seats" << endl;
		cout << "2 - Request Ticket(s)" << endl;
		cout << "3 - Display Sales Report" << endl;
		cout << "4 - Quit, cause you can't handle this show or have a wonderful movie!" << endl;
		menuChoice = isGoodInput(1, 4);

		switch (menuChoice)
		{
		case 1:
			//display seats
			cout << ticketManager.displaySeats() << endl;
			break;

		case 2:
			cout << "How many seats would you like to purchase?" << endl;
			numSeatsDesired = isGoodInput(1, 30);
			cout << "Which Row number would you like to purchase seats? Your choice is between Row 1 and 15" << endl;
			desiredRowNum = isGoodInput(1, 15);
			cout << "Which starting seat would you like purchase? For example if you want seat 2 through 5 the starting seat is 2." << endl;
			startingSeatNum = isGoodInput(1, 30);
			while ((startingSeatNum + numSeatsDesired)-1 > TicketManager::TOTAL_NUMBER_OF_COLUMNS) {
				cout << "***\nPlease note there are only 30 seats in a row so you cannot \nfor example request 5 seats and select a starting seat 26 or greater." << endl;
				cout << "That would mean you are selecting seat 26 thru 31. Please be careful!\n***" << endl;
				startingSeatNum = isGoodInput(1, 30);
			}
			cout << ticketManager.requestTicket(desiredRowNum, startingSeatNum, numSeatsDesired) << endl;
			break;

		case 3:
			//sales report written last
			cout << ticketManager.salesReport(numSeatsDesired) << endl;
			break;

		case 4:
			//quit
			cout << "Thanks for using Group 3 Theater Ticket Sales! Have a nice life!!!" << endl;
			isDone = true;
			break;
		}
	}
	return 0;
}

bool userChoice()
{
	bool booleanChoice;
	int choice;
	cin >> choice;
	while (!(choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')) { // User input a character or string or an incorrect value
		cout << "\n" << choice << " is not a valid option!" << "\nPlease enter Y or y to continue or N or n." << endl; // prompt user input correct choice
		cin >> choice;
	}
	if (choice == 'y' || choice == 'Y') {
		booleanChoice = true;
	}
	else {
		booleanChoice = false;
	}
	return booleanChoice;
}

/************************************
isGoodInput
Asks the user the number of test scores to be input
and checks if the user entered a positive number greater than min and less than max
*************************************/
int isGoodInput(int min, int max)
{
	int isGoodInput;
	while (!(cin >> isGoodInput) || isGoodInput < min || isGoodInput > max) { // check if the user input a number and check it is greater than zero
		cout << "Bad Input!!! Please enter a positive number between " << min << " and " << max << endl; // Inform user of bad input
		cin.clear(); // Clear cin of errors
		cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
	}
	return isGoodInput; // return positive integer for number of test scores
}