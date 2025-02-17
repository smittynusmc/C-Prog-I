// Lottery Assignment.cpp : A lottery ticket buyer purchases 10 tickets a week, always playing the same 10 five-digit “lucky” combinations. 
// Program initializes an array with pre decided numbers and then lets the player enter this week’s winning five-digit number. 
// The program performs a linear search through the list of the player’s numbers and report whether or not one of the tickets is a winner this week.
// Program asks if the user would like to try next weeks lottery 
// Adam Tucker
// 04/08/18

#include "stdafx.h"
#include <iostream>
using namespace std;

const int SIZE_OF_LOTTERY_NUMBER_ARRAY = 10; // size of the array

bool search(int[], int); // prototype for linear search

// Main Function
int main()
{
	int lotteryNumbers[10] = { 13579,26791,26792,33445,55555,62483,77777,79422,85647,93121 }; // array for 10 five digit winning lottery numbers
	int possibleLotteryNumber; // User input possible winning or losing lottery number
	char choice; // choice to quit program or run next weeks lottery
	bool done = false; // flag to end program

	cout << "Welcome to the Lottery!!!\n" << endl; // initial program greeting

	while (!done) {
		cout << "Please enter this weeks lottery number to see if you are a WINNER!!!" << endl; // prompt user for lottery number
		
		if (!(cin >> possibleLotteryNumber) || possibleLotteryNumber < 0) { // Checks if the number is an integer or if the number is positive
			cout << "Bad Input!!! Your lucky lottery number must be a postive number." << endl; // User either input a negative number or some kind of string or char
			cin.clear(); // Clear cin of errors
			cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
		}
		else { // user has input a positive number or zero
			if (!(search(lotteryNumbers, possibleLotteryNumber))) { // linear search returned false meaning it did not find the a winning number
				cout << possibleLotteryNumber << " is not a winning number.... Try again next week!" << endl;
			}
			else { // winning number was found
				cout << "CONGRATULATIONS!!! YOU HAVE WON THE LOTTERY!!! 1 BILLION IMAGINARY DOLLARS IS NOW BEING WIRED TO YOUR IMAGINARY ACCOUNT!!!" << endl;
			}
			cout << "\nWould you like run next weeks lottery and try again? (Enter Y or y for yes and N or n for no)" << endl; // prompt user to continue or quit
			cin >> choice;
			while (!(choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')) { // User input a character or string or an incorrect value
				cout << "\n" << choice << " is not a valid option!" << "\nPlease enter Y or y to continue the Lottery or N or n to quit." << endl; // prompt user input correct choice
				cin >> choice;
			}
			if (choice == 'y' || choice == 'Y') { // user choose to run lottery for next week
				continue;
			}
			else {
				done = true; // user felt unlucky and quit program
			}
		}
		
	}

    return 0; // program is done
}

/***************************************************
Search
Linearly search for lotteryNumToFind in arrOfLotteryNumbers[].  
If lotteryNumToFind is present then return true, otherwise return false
***************************************************/
bool search(int arrOfLotteryNumbers[], int lotteryNumToFind)
{

	for (int i = 0; i < SIZE_OF_LOTTERY_NUMBER_ARRAY; i++) { // Loop through array using its index as i
		if (arrOfLotteryNumbers[i] == lotteryNumToFind) { // checks if value at i equals the value being searched for
			return true; // value was found return true to indicate value is in the array
		}
	}
	return false; // value was not found
}