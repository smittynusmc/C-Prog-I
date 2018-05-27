#include "stdafx.h"
#include "TicketManager.h"
#include <algorithm>
#include <iostream>
#include <sstream> // stringstream
#include <iomanip>
#include <string>
#include <cstdio>
#include <fstream>
using namespace std;

TicketManager::TicketManager()
{
	// Object to read from file
	ifstream seatAvaliability;
	ifstream seatPrices;

	// Opening file in input mode
	seatAvaliability.open("SeatAvailability.dat");
	seatPrices.open("SeatPrices.dat");
	float currentTicketPrice;
	for (int currentRow = 0; currentRow < TOTAL_NUMBER_OF_ROWS; currentRow++) {
		seatPrices >> currentTicketPrice;
		for (int currentColumn = 0; currentColumn < TOTAL_NUMBER_OF_COLUMNS; currentColumn++) {
			SeatStructure *tempSeat = &SeatStructure();
			tempSeat->ticketPrice = currentTicketPrice;
			seatAvaliability >> tempSeat->isTicketSold;
			arrayOfSeatStructures[currentRow][currentColumn] = *tempSeat;
		}
	}
	currentNumberSeatsAvaliable = setSeatsAvaliable();
}

TicketManager::~TicketManager()
{
	ofstream seatAvaliability;

	// Opening file in input mode
	seatAvaliability.open("SeatAvailability.dat");
	for (int currentRow = 0; currentRow < TOTAL_NUMBER_OF_ROWS; currentRow++) {
		for (int currentColumn = 0; currentColumn < TOTAL_NUMBER_OF_COLUMNS; currentColumn++) {
			seatAvaliability << arrayOfSeatStructures[currentRow][currentColumn].isTicketSold;
		}
		seatAvaliability << "\n";
	}
}

//*Terrence Part*//

//*Function: void displayChart (char seats[RWS][CLS], float rowPrices[ ])*//

string TicketManager::displaySeats()
{
	string results;
	//*Print the current seating chart and prices.*//

	results += "                 Seats\n";
	results += "        123456789012345678901234567890";

	for (int r = 0; r < TOTAL_NUMBER_OF_ROWS; r++) /*loop through Rws*/
	{
		results += "\nRow " + to_string(r + 1) + "  ";
		if (r < 9) {
			results += " ";
		}
		for (int c = 0; c < TOTAL_NUMBER_OF_COLUMNS; c++) //* This should loop columns*//
		{
			results += arrayOfSeatStructures[r][c].isTicketSold;
		}
	}

	return results + "\n";

}

string TicketManager::salesReport(int numSeatsDesired) { 
	int seatTotal = 0;
	float priceTotal = 0;
	string results;
	for (int row = 0; row < 15; row++) { 
		for (int col = 0; col < 30; col++) { 
			if (arrayOfSeatStructures[row][col].isTicketSold == '*') { 
				seatTotal++;				
				priceTotal += arrayOfSeatStructures[row][col].ticketPrice;
			} 
		} 
	}	
	results += "Seats Sold: " + to_string(numSeatsDesired) + "\n";	
	results += "Seats Available: " + to_string(currentNumberSeatsAvaliable) + "\n";
	stringstream stream;
	stream << fixed << setprecision(2) << totalProfit;
	string totalProfitWithTwoDecimal = stream.str();
	results += "Money Collected: $" + totalProfitWithTwoDecimal + "\n";
	return results;
}

// Purchase Ticket Function
// Coded by Heather
string TicketManager::requestTicket(int desiredRowNum, int startingSeatNum, int numSeatsDesired)
{
	string results;
	int counter = 0, seatTaken = 0;
	int invalidSeats[2];

	int endRow = (startingSeatNum + numSeatsDesired) - 1;

	for (int i = 0; i < numSeatsDesired && seatTaken == 0; i++) //So I use a for loop to check each if each seat is taken
	{ //I assume the seat values are going to be in a two-dimensional array with the first dimension being the row
		if (arrayOfSeatStructures[desiredRowNum-1][(startingSeatNum + i)-1].isTicketSold == '#') //I also assumed that the array would be titled "seats"
			counter++; // I use a counter to make sure that as many seats are requested are open next to each other
		else
		{
			seatTaken++; //If there are seats taken I quit the loop early to avoid unneccessary executions
			invalidSeats[0] = desiredRowNum; //I also save the taken seat to tell the user later
			invalidSeats[1] = (startingSeatNum+counter);
		}
	}

	if (counter == numSeatsDesired)
	{
		cout << "Row #" << desiredRowNum << " ";
		if (numSeatsDesired == 1) {
			cout << "Seat " << startingSeatNum << " is avaliable" << endl; //If all the requested seats are available "Seats Available" is returned
		}
		else {
			cout << "Seats " << startingSeatNum << " - " << endRow << " are avaliable" << endl; //If all the requested seats are available "Seats Available" is returned
		}
		results = purchaseTicket(desiredRowNum, startingSeatNum, numSeatsDesired);
	}
	else
	{ // If not then the user is informed of the taken seat and "One or more seats taken" is returned
		results = "\nI'm sorry! The seats in Row #" + to_string(invalidSeats[0]) + " Seat(s) " + to_string(startingSeatNum) + " - " + to_string(endRow) + " are/is unavailable.";
		results += "\nRow #" + to_string(invalidSeats[0]) + " Seat " + to_string(invalidSeats[1]) + " is the first seat unavailable.\n";
	}
	return results;
}

string TicketManager::purchaseTicket(int desiredRowNum, int startingSeatNum, int numSeatsWanted) {

	float money,totalCost,change; //declare variable for money from user, totalCost, change due
	char purchase;
	bool purchaseDone = false;
	string result;

	totalCost = arrayOfSeatStructures[desiredRowNum-1][0].ticketPrice * numSeatsWanted;
	int endingSeatNum = (startingSeatNum + numSeatsWanted) - 1;

	while (!purchaseDone) {
		cout << "Number of seats requested: " << numSeatsWanted << endl;

		cout << "Individual Cost Per Seat: $" << arrayOfSeatStructures[desiredRowNum-1][0].ticketPrice << endl;
		
		cout << "Total Cost for Seats: $" << totalCost << endl;

		cout << "Would you like to confirm purchase, enter Y or N" << endl;

		cin >> purchase;

		while (!(purchase == 'y' || purchase == 'Y' || purchase == 'n' || purchase == 'N')) { // User input a character or string or an incorrect value
			cout << "\n" << purchase << " is not a valid option!" << "\nPlease enter Y or y to continue purchase or N or n to exit your ticket purchase." << endl; // prompt user input correct choice
			cin >> purchase;
		}
		if (purchase == 'y' || purchase == 'Y')
		{

			cout << "Please enter the amount of money to purchase tickets!\n$";
			while (!(cin >> money) || money < 0) { // check if the user input a number and check it is greater than zero
				cout << "Bad Input!!! Please enter a positive amount of money" << endl; // Inform user of bad input
				cin.clear(); // Clear cin of errors
				cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
			}

			if (money >= totalCost)
			{

				result = "Your tickets have been purchased!\n";
				change = money - totalCost;
				stringstream stream;
				stream << fixed << setprecision(2) << change;
				string changeWithTwoDecimal = stream.str();
				result += "Your change is $" + changeWithTwoDecimal + ". Thank you for your purchase!";
				purchaseDone = true;
				totalProfit += totalCost;
				currentNumberSeatsAvaliable -= numSeatsWanted;
				updatePurchasedSeats(startingSeatNum, endingSeatNum, desiredRowNum);
			}
			else {
				change = totalCost - money;
				cout << "You entered an insufficient amount of money. Please enter $" << change << " more to purchase tickets." << endl;
			}
		}
		else if (purchase == 'n' || purchase == 'N') {
			purchaseDone = true;
			result = "You have opted to not purchase the ticket(s) in Row #" + to_string(desiredRowNum);
			if (numSeatsWanted == 1) {
				result += " Seat # " + to_string(startingSeatNum);

			}
			else {
				result += " Seat(s) # " + to_string(startingSeatNum) + " - " + to_string(endingSeatNum);
			}
		}
	}
	return result;
}

void TicketManager::updatePurchasedSeats(int startingSeatNum, int endingSeatNum, int desiredRowNum)
{
	for (int i = startingSeatNum; i <= endingSeatNum; i++) {
		arrayOfSeatStructures[desiredRowNum-1][i - 1].isTicketSold = '*';
	}
}

int TicketManager::setSeatsAvaliable()
{
	int numSeatAvaliable = 0;
	for (int row = 0; row < TOTAL_NUMBER_OF_ROWS; row++) {
		for (int col = 0; col < TOTAL_NUMBER_OF_COLUMNS; col++) {
			if (arrayOfSeatStructures[row][col].isTicketSold == '#') {
				numSeatAvaliable++;
			}
		}
	}
	return numSeatAvaliable;
}
