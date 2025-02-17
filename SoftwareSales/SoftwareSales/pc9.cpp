// SoftwareSales
// Software sales takes the number of items sold, checks if a discount needs to be applied and applies discounts if needed
// The program outputs a reciept stating total price, total discount and final price
// Programming Challenge # 9 -"Software Sales" of our textbook on page 237 - Starting out with C++ by Tony Gaddis
// Adam Tucker
// 02/04/18

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{

	// Package sales constant
	double PACKAGE_PRICE = 199.00;
	// Intialized variables
	int unitsPurchashed;
	double total = 0.0, totalDiscount = 0.0, finalTotal = 0.0;

	// Ask user to enter items purchased and set variable
	cout << "Enter number of units Purchased" << endl;
	cin >> unitsPurchashed;

	// Calculates the total without discount and sets the finalTotal to be used if 
	// no discount is applied
	total = (double) unitsPurchashed * PACKAGE_PRICE;
	finalTotal = total;
	string discount = "You do not get a discount"; // discount variable will state how much discount is to be applied

	// Conditionals checking how many items were purchased
	// Sets discount message to inform the amount to be discounted
	// Calculates total discount
	// Subtracts discount from final price
	if (unitsPurchashed > 99) {
		discount = "You have purchased over 100 items. YOU GET A 50% DISCOUNT!!!";
		totalDiscount = (total * .5);
		finalTotal -= totalDiscount;
	}
	else if (unitsPurchashed > 49) {
		discount = "You have purchased between 50 and 99 items. You get a 40% discount! Yay!";
		totalDiscount = (total * .4);
		finalTotal -= totalDiscount;
	}
	else if (unitsPurchashed > 19) {
		discount = "You have purchased between 20 and 49 items. You get a 30% discount which is decent i guess...";
		totalDiscount = (total * .3);
		finalTotal -= totalDiscount;
	}
	else if (unitsPurchashed > 9) {
		discount = "You have purchased between 10 and 19 items. You get a 20% discount...meh...";
		totalDiscount = (total * .2);
		finalTotal -= totalDiscount;
	}
	else if (unitsPurchashed < 1) {
		cout << "You entered a value less than 1 run the program again" << endl;
	}

	// Reciept output
	cout << fixed << setprecision(2);
	cout << discount << endl;
	cout << "Total without Discount:" << right << setw(22) << "$" << total << endl;
	cout << "Total Discount:" << right << setw(30) << "$" << totalDiscount << endl;
	cout << "Total Cost of Purchase with discount:" << right << setw(8) << "$" << finalTotal << endl;

    return 0;
}

