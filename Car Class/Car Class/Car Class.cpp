// Car Class.cpp
// A program that creates a Car object and then calls the accelerate function five times. 
// After each call to the accelerate function, the program gets the current speed of the car and display it. 
// Program Calls the brake function five times.
// After each call to the brake function, the program gets the current speed of the car and display it
// Adam Tucker
// 03/18/18

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

// Car represented by its year, make and speed
// This car can accelerate and brake and print its current speed
class Car {

private:
	int year; // member variable represnting a cars year
	string make; // make of the car
	int speed; // speed of the car

public:

	Car(); // defualt contructor
	Car(int, string); // Constructor that sets all member variables
	// Class does not need a programmer defined deconstructor. Compiler will automatically create one
	int getYear(); // Gets the Cars Year
	string getMake(); // Gets the Cars Make
	int getSpeed(); // Gets the Cars Speed
	void setYear(int); // sets the cars year
	void setMake(string); // sets the car make
	void setSpeed(int); // sets the cars speed
	void accelerate(Car &, int); // increase cars speed by amount sent in parameter
	void brake(Car &, int); // decrease speed by amount sent in paramter
	void printSpeed(Car &); // print cars new speed
};

// Main Function
int main()
{
	int inYear, inSpeed; // cin variables
	string inMake; // cin variables
	//Car myCar; // 

	cout << "Welcome to the Car Simulator" << endl;
	cout << "Please enter the year of the car" << endl;
	cin >> inYear;
	while (inYear < 0) { // Year must be positive. Loop til inYear is greater than zero
		cout << "Please enter a number great than zero for the Year of the car" << endl;
		cin >> inYear;
	}

	cout << "Please enter the make of the car" << endl; // No check here because a car model could have any combinations of character
	cin.ignore();
	getline(cin,inMake); // Some makes are more than one word. cin.ignore() basically ignores user pressing enter and gets the entire line
	
	Car myCar = Car(inYear, inMake); // Initialize the car object. Speed is default to zero as required in book instructions

	cout << "Car Simulator will know begin" << endl; // print begginning of simulation
	cout << "Your " << myCar.getYear() << " " << myCar.getMake() << " is starting with a speed of " << myCar.getSpeed() << endl;

	for (int i = 1; i <= 5; i++) { // run accelerate function 5 times
		myCar.accelerate(myCar, 5); // increase car speed by 5
	}

	for (int i = 1; i <= 5; i++) { // run brake function 5 times
		myCar.brake(myCar, 5); // decrease speed by 5
	}

	cout << "Car Simulator end results are:" << endl; // Print out simulator results
	cout << "Your " << myCar.getYear() << " " << myCar.getMake() << " ended with a speed of " << myCar.getSpeed() << endl;
	cout << "Congratulations on a successful run!!! Have Nice Day!!!" << endl;

    return 0;
}

/********************************************
* Car::Car *
* Default Constructor sets defualt values *
********************************************/

Car::Car()
{
	year = 0;
	make = "Unknown";
	speed = 0;
}


/********************************************
* Car::Car *
* Overloaded Constructor sets member variables from parameters Speed defualt to zero*
********************************************/
Car::Car(int myYear, string myMake)
{
	year = myYear;
	make = myMake;
	speed = 0;
}

/********************************************
* Car::getYear *
* This function gets the value of Car member variable year *
* Year is the cars year as an int
********************************************/
int Car::getYear()
{
	return year;
}

/******************************************** 
* Car::getMake *
* This function gets the value of Car member variable make *
* Make is the cars make as a string
********************************************/

string Car::getMake()
{
	return make;
}

/********************************************
* Car::getSpeed *
* This function gets the value of Car member variable speed *
* Speed is the cars current speed as a int
********************************************/
int Car::getSpeed()
{
	return speed;
}

/********************************************
* Car::setYear *
* This function sets the value of Car member variable year *
* Year is checked to see if the value is >= 0. Year is set to a default of zero if negative
********************************************/
void Car::setYear(int newYear)
{
	if (newYear >= 0) {
		year = newYear;
	}
	else {
		year = 0;
	}

}

/********************************************
* Car::setMake *
* This function sets the value of Car member variable make *
* Make return value is void because the car make is up to the user
* No constriants have been set for the make of a car 
* Since the parameter is a string we know the car make will be a string as required by the member variable
********************************************/
void Car::setMake(string newMake)
{
	make = newMake; // set parameters to member variable make
}

/********************************************
* Car::setSpeed *
* This function sets the value of Car member variable speed *
* Speed is checked to see if the value is >= 0 if not speed is set to zero
* A car does not have a negative speed. A speed of zero indicates the car is stopped
********************************************/
void Car::setSpeed(int newSpeed)
{
	if (newSpeed >= 0) {
		speed = newSpeed; // Car is stil moving
	}
	else {
		speed = 0; // car has stopped
	}
}

/********************************************
* Car::accelerate *
* This function increase the value of Car member variable speed by variable increaseBy*
* myCar is accelerated by increaseBy and then the speed is printed
********************************************/
void Car::accelerate(Car &myCar, int increaseBy)
{
	setSpeed(getSpeed() + increaseBy); // increase car current speed by parameters increaseBy
	printSpeed(myCar); // print cars new speed
}

/********************************************
* Car::brake *
* This function decreases the value of Car member variable speed by variable decreaseBy*
* myCar speed is decreased by braking and then the speed is printed
********************************************/
void Car::brake(Car &myCar, int decreaseBy)
{
	setSpeed(getSpeed() - decreaseBy); // decrease car current speed by parameters decreaseBy
	printSpeed(myCar); // print cars new speed
}

/********************************************
* Car::printSpeed *
* Prints the cars current speed in MPH
********************************************/
void Car::printSpeed(Car &car)
{
	cout << "Your speed is now " << car.getSpeed() << " MPH." << endl;
}
