// Test Scores 2
// Program dynamically allocates an array of test score structs large enough to hold a user-defined number of test scores and student names.
// Once all the scores are entered, the array is sorted in ascending order.
// An average function is called that calculates the average score.
// Program displays the sorted list of scores, names and the test scores average with appropriate headings.
// (Gaddis 701)
// Adam Tucker
// 04/22/18

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Struct of test scores
struct TestScore
{
	string name; // Student Name
	double testScore; // Student Test Score

	TestScore(string myName = "", double myTestScore = 0.0) // TestScores constructor with defaults
	{
		name = myName; // set name member value
		testScore = myTestScore;  // set test score member value
	}
};

// Prototype functions
double average(TestScore*, int); // Returns average of an array of test scores
int getNumberOfTestScores(); // Gets number of test scores to be input by user
void inputTestScores(TestScore*, int); // Gets the test scores input by user
bool testScore_sorter(TestScore&, TestScore&); // prototype helper function to be used for sorting

int main()
{
	bool done = false; // flag for program
	char choice; // choice by user
	while (!done)
	{
		TestScore* testScores; // init a pointer to a TestScore
		cout << "Welcome to the Test Score Database!" << endl;
		int numberOfTestScores = getNumberOfTestScores(); // User inputs number of test scores
		testScores = new TestScore[numberOfTestScores]; // Allocate array of doubles and save ptr in testScores
		inputTestScores(testScores, numberOfTestScores); // User inputs test scores
		sort(testScores, testScores + numberOfTestScores, &testScore_sorter); // sort test scores in ascending with helper function testScore_sorter
		cout << fixed << setprecision(2); // set the precision for all doubles printed
		for (int count = 0; count < numberOfTestScores; count++)   // print test scores in ascending order
		{
			cout << "Test score for " << (testScores + count)->name << " is " << (testScores + count)->testScore << endl; // print student name and test score
		}
		cout << "\nAverage test score: " << average(testScores, numberOfTestScores) << endl; // print average of test scores
		cout << "\nWould you like enter another set of test scores? (Enter Y or y for yes and N or n for no)" << endl; // prompt user to continue or quit
		cin >> choice;
		while (!(choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')) // User input a character or string or an incorrect value
		{
			cout << "\n" << choice << " is not a valid option!" << "\nPlease enter Y or y to enter more test scores or N or n to quit." << endl; // prompt user input correct choice
			cin >> choice;
		}
		if (choice == 'y' || choice == 'Y')   // user choose to enter more test scores
		{
			continue;
		}
		else
		{
			done = true; // change flag to quit program
		}
	}
	return 0;
}

/************************************
average
Calculates the average of an array of doubles
*************************************/
double average(TestScore* myArray, int size)
{
	double sum = 0; // init sum of doubles
	for (int count = 0; count < size; count++)
	{
		sum += (myArray + count)->testScore; // add all values together
	}
	return sum / (double)size; // calculate average and return average
}

/************************************
getNumberOfTestScores
Asks the user the number of test scores to be input
and checks if the user entered a positive number greater than zero
and returns the number of test scores
*************************************/
int getNumberOfTestScores()
{
	int numberOfTestScores; // init number of test scores
	cout << "Please enter a positive number of test scores to be entered." << endl; // Prompt user
	while (!(cin >> numberOfTestScores) || numberOfTestScores <= 0) // check if the user input a number and check it is greater than zero
	{
		cout << "Bad Input!!! Please enter a positive number of test scores to be entered." << endl; // Inform user of bad input
		cin.clear(); // Clear cin of errors
		cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
	}
	return numberOfTestScores; // return positive integer for number of test scores
}

/************************************
inputTestScores
Asks the user for the test scores to be input
and checks if the user entered a positive number greater than zero
and puts the test in array
*************************************/
void inputTestScores(TestScore* testScores, int size)
{
	double myTestScore; // init temp test score variable
	string myName;
	for (int count = 0; count < size; count++)
	{
		cout << "Please enter a name for Student #" << (count + 1) << ". "; /// prompt user
		while (!(cin >> myName) || any_of(myName.begin(), myName.end(), isdigit)) // check if the user input a string
		{
			cout << "Bad Input!!! Check to see if your name contained numbers!!!\nPlease enter a name for Student #" << (count + 1) << ". ";  // Inform user of bad input
			cin.clear(); // Clear cin of errors
			cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
		}
		(testScores + count)->name = myName; // input positive number into array
		cout << "Please enter a test scores out of 100 for " << (testScores + count)->name << ": "; /// prompt user
		while (!(cin >> myTestScore) || myTestScore < 0 || myTestScore > 100) // check if the user input a number and check it is greater than zero or greater than 100
		{
			cout << "Bad Input!!! Please enter a positive test score between 0 and 100.\nEnter a test score for " << (testScores + count)->name << ": ";  // Inform user of bad input
			cin.clear(); // Clear cin of errors
			cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
		}
		(testScores + count)->testScore = myTestScore; // input positive number into array

	}
}

/*
testScore_sorter
Helper function used to sort an array of TestScore structs
The Function checks if the left testscore is less than the right and returns true or false 
*/
bool testScore_sorter(TestScore& lhs, TestScore& rhs)
{
	return lhs.testScore < rhs.testScore; // True if lhs is less than and false otherwise
}