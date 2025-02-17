// Lab 4 areas.cpp 
// WRITE A COMMENT BRIEFLY DESCRIBING THE PROGRAM. 
// PUT YOUR NAME HERE.
#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


int main()
{
	int hours;
	double mph, distance;
	bool done = false;


	while (!done) {
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		cout << "WELCOME TO THE DISTANCE TRAVELED CALCULATOR" << endl;
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
		cout << "What is the speed of the vehicle in mph?" << endl;
		cin >> mph;
		while (mph <= 0.0) {
			cout << "You entered " << mph << ". Please enter a number greater than zero and try again\n" << endl;
			cout << "What is the speed of the vehicle in mph?" << endl;
			cin >> mph;
		}

		cout << "How many hours has it traveled rounded to the nearest whole number?" << endl;
		cin >> hours;

		while (hours <= 0) {
				cout << "You entered " << hours << ". " << endl;
				cout << "Please enter a number greater than zero and try again\n" << endl;
				cout << "How many hours has it traveled?" << endl;
				cin >> hours;
		}

		cout << "Hours\t\tMiles Traveled" << endl;
		cout << "------------------------" << endl;

		
		for (int count = 1; count <= hours; count++) {
				done = true;
				distance = count * mph;
				cout << fixed << setprecision(2) << count << "\t\t" << distance << endl;
			}
		}

	return 0;
}
