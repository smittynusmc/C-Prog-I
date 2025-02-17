// pc1.cpp
// This program keeps track of how many pounds of food each of its three monkeys eats each day during a typical week.
// The program stores this information in arrays that simulate two - dimensional 3 × 7 array as well as a two dimensional array, 
// where each row represents a different monkey and each column represents a different day of the week.
// Class Zoo has an array that equals the 3 rows in a two dimensional array
// The monkey struct has an array the equals the 7 columns in a two dimensional array
// Adam Tucker
// 03/24/18

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int NUMBER_OF_DAYS_IN_WEEK = 7; // constant for the number of days in a week
const int NUMBER_OF_MONKIES = 3; // Number of monkies in the zoo

/********************************************
* Monkey struct *
* A monkey has a name and a record of amount of food eaten in one week *
********************************************/
struct Monkey {
	string name; // name of monkey
	double recordOfFoodConsumed[NUMBER_OF_DAYS_IN_WEEK]; // food record an array sized by number of days in the week
														// This would be the amount of columns in a two dimensional array

	// Constructor for Monkey with default name if no paramater is passed and initializing the food record array
	Monkey(string myName = "") : recordOfFoodConsumed{ 0,0,0,0,0,0,0 } {
		name = myName;
	}
};

// A Zoo represented by its 3 monkeys
// The zoo can calculate the average food eaten by each monkey, as well as the least and most amount of food
//
class Zoo {

public:

	Monkey monkies[NUMBER_OF_MONKIES]; // Array of monkeys in the zoo. This would be the number of rows in a two dimensional array

	Zoo(); // defualt contructor
		   // Class does not need a programmer defined deconstructor. Compiler will automatically create one
	double average(Zoo &); // Function the gets the average of an array of numbers
	void report(Zoo &); // prints a report for each monkey
	double lowestValue(double[]); // finds the lowest value in an array
	double highestValue(double[]); // finds the highest value in an array

};

// Main Function
int main()
{
	int inNum; // number entered by user to be check if negative
	double consumed[NUMBER_OF_MONKIES][NUMBER_OF_DAYS_IN_WEEK]; // Two dimensional array as required by problem in book
	Zoo zoo = Zoo(); // The initalized zoo
	cout << "Welcome to the The Zoo of the " << NUMBER_OF_MONKIES << " Monkies" << endl;
	cout << "You are now the the record keeper for our " << NUMBER_OF_MONKIES << " Monkies " << endl;
	// Outer loops goes through each monkey at the zoo
	for (int i = 0; i < NUMBER_OF_MONKIES; i++) { 
		cout << zoo.monkies[i].name << " needs the amount of food eaten each day entered" << endl; // Prints the monkeys name
		// Inner loop gets each day of the week (Day 1 to Day 7) and puts the number into the monkies food record
		for (int j = 0; j < NUMBER_OF_DAYS_IN_WEEK; j++) {
			cout << "Please enter the amount of food eaten in pounds by " << zoo.monkies[i].name << " on day #" << (j+1) << endl;
			cin >> inNum;
			while (inNum < 0) { // Loops until user puts a positive number
				cout << "You have entered " << inNum << " which is a negative number. Please enter a positive number" << endl;
				cin >> inNum;
			}
			zoo.monkies[i].recordOfFoodConsumed[j] = inNum; // insert number into monkey i at food record j
			consumed[i][j] = inNum; // input the value entered in the two dimensional array as required
		}
	}

	zoo.report(zoo); // prints the monkies stats. Average amount consumed by all monkies
					// , lowest amount eaten by any monkey and highest amount eaten this week by any monkey
	return 0;
}

/********************************************
* Zoo::Zoo *
* Default Constructor sets defualt values *
********************************************/

Zoo::Zoo()
{	
	Monkey bobo = Monkey("Bobo"); // Monkey #1
	Monkey apollo = Monkey("Apollo"); // Monkey #2
	Monkey athena = Monkey("Athena"); // Monkey #3

	monkies[0] = bobo; // insert monkey number 1
	monkies[1] = apollo;  // insert monkey number 2
	monkies[2] = athena; // insert monkey number 3
}

/********************************************
* Zoo::average *
* Finds average food eaten each day *
* Loops through the amount of food eaten each day, add up the total and divides by the number of days in a week *
********************************************/
double Zoo::average(Zoo &myZoo)
{
	double total = 0; // variable for total eaten in a week
	// Loop through the food eaten each day
	for (int count = 0; count < NUMBER_OF_MONKIES; count++) {
		for (int i = 0; i < NUMBER_OF_DAYS_IN_WEEK; i++) {
			total += myZoo.monkies[count].recordOfFoodConsumed[i]; // add the food eaten that day to the total
		}
	}
	return total / (NUMBER_OF_DAYS_IN_WEEK*NUMBER_OF_MONKIES); // divide total by number of days in a week to return the average
}

/********************************************
* Zoo::report *
* Prints out the stats requested by the zoo. Average for all monkies, lowest consumed by any monkey this week *
* and highest consumed by any monkey this week *
********************************************/
void Zoo::report(Zoo &myZoo)
{
	cout << fixed << setprecision(2);
	cout << "\nThe average pounds of food eaten by all the monkies per day was " << myZoo.average(myZoo) << " pound(s) per day." <<  endl;
	Monkey highestMonkey = myZoo.monkies[0], lowestMonkey = myZoo.monkies[0]; // init highest and lowest monkey with first value 
	double tempLowest, tempHighest; // temp variable to cut down the times lowestValue() and highestValue() is called
	double highestEaten = myZoo.monkies[0].recordOfFoodConsumed[0], lowestEaten = myZoo.monkies[0].recordOfFoodConsumed[0]; // init highest and lowest amount consumed with first value 
	for (int i = 0; i < NUMBER_OF_MONKIES; i++) { // Loop through all the monkies
		Monkey temp = myZoo.monkies[i]; // Get the monkey and index i
		tempLowest = myZoo.lowestValue(temp.recordOfFoodConsumed); // find monkies lowest value
		if (tempLowest < lowestEaten) { // checks if the lowest value is lower than previous values
			lowestEaten = tempLowest; // save new lowest value
			lowestMonkey = temp; // Save the new lowest monkey
		}
		tempHighest = myZoo.highestValue(temp.recordOfFoodConsumed); // find monkies highest value
		if (tempHighest > highestEaten) { // checks if the lowest value is higher than previous values
			highestEaten = tempHighest; // save new highest value
			highestMonkey = temp; // Save the new highest monkey
		}
	}
	cout << "\nThe lowest amount food eaten by all monkies was by " << lowestMonkey.name << " who ate " << lowestEaten << " pound(s) of food" << endl;
	cout << "\nThe highest amount food eaten by all monkies was by " << highestMonkey.name << " who ate " << highestEaten << " pound(s) of food" << endl;
}

/********************************************
* Zoo::highestValue *
* Loops through the food eaten in a week and keeps track of the highest amount *
********************************************/
double Zoo::highestValue(double foodEaten[])
{
	int count; // count for array indices
	double highest; // variable to keep track of highest value
	highest = foodEaten[0]; // get the first amount of food eaten
	// Loop until until all days of the week have been checked
	for (count = 1; count < NUMBER_OF_DAYS_IN_WEEK; count++) { 
		if (foodEaten[count] > highest) { // Check if foodEaten at index count is higher than the current highest
			highest = foodEaten[count]; // if so save the new highest value
		}
	}
	return highest; // return the highest amount of food eaten this week
}

/********************************************
* Zoo::lowestValue *
* Loops through the food eaten in a week and keeps track of the lowest amount *
********************************************/
double Zoo::lowestValue(double foodEaten[])
{
	int count; // count for array indices
	double lowest; // variable to keep track of lowest value
	lowest = foodEaten[0]; // get the first amount of food eaten
	// Loop until until all days of the week have been checked
	for (count = 1; count < NUMBER_OF_DAYS_IN_WEEK; count++) {
		if (foodEaten[count] < lowest) { // Check if foodEaten at index count is less than the current lowest
			lowest = foodEaten[count]; // if so save the new lowest value
		}
	}
	return lowest; // return the lowest amount of food eaten this week
}
