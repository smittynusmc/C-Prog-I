// Test Scores 2
// Program dynamically allocates an array large enough to hold a user-defined number of test scores. 
// Once all the scores are entered, the array is sorted in ascending order. 
// An average function is called that calculates the average score. 
// Program displays the sorted list of scores and averages with appropriate headings.
// (Gaddis 701)
// Adam Tucker
// 04/14/18

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

struct TestScores {
	string name;
	double testScore;
};

// Prototype functions
double average(TestScores *, int); // Returns average of an array of test scores
int getNumberOfTestScores(); // Gets number of test scores to be input by user
void inputTestScores(TestScores *, int); // Gets the test scores input by user

int main()
{
	bool done = false;
	char choice;
	while (!done) {
		TestScores *testScores; // init a pointer to a doublr
		int numberOfTestScores = getNumberOfTestScores(); // User inputs number of test scores
		testScores = new TestScores[numberOfTestScores]; // Allocate array of doubles and save ptr in testScores
		inputTestScores(testScores, numberOfTestScores); // User inputs test scores
		//sort(testScores->testScore, testScores->testScore + numberOfTestScores); // sort test scores in ascending 
		for (int count = 0; count < numberOfTestScores; count++) { // print test scores in ascending order
			cout << "Test score " << count + 1 << ": " << (testScores->testScore + count) << endl;
		}
		cout << "\nAverage test score: " << average(testScores, numberOfTestScores) << endl; // print average of test scores
		cout << "\nWould you like enter another set of test scores? (Enter Y or y for yes and N or n for no)" << endl; // prompt user to continue or quit
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
	return 0;
}

/************************************
average
Calculates the average of an array of doubles
*************************************/
double average(TestScores *myArray, int size)
{
	double sum = 0; // init sum of doubles
	for (int count = 0; count < size; count++)
	{
		sum += (myArray + count)-> testScore; // add all values together
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
	while (!(cin >> numberOfTestScores) || numberOfTestScores <= 0) { // check if the user input a number and check it is greater than zero
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
void inputTestScores(TestScores *testScores, int size)
{
	double myTestScore; // init temp test score variable
	for (int count = 0; count < size; count++) {
		cout << "Please enter your test scores as positive numbers to be entered.\n" << (count + 1) << ". "; /// prompt user
		while (!(cin >> myTestScore) || myTestScore <= 0) { // check if the user input a number and check it is greater than zero
			cout << "Bad Input!!! Please enter a positive number of test scores to be entered.\n" << (count + 1) << ". ";  // Inform user of bad input
			cin.clear(); // Clear cin of errors
			cin.ignore(INT_MAX, '\n'); // preferred method for flushing cin so cin can be used later
		}
		(testScores + count)->testScore = myTestScore; // input positive number into array
	}
}
