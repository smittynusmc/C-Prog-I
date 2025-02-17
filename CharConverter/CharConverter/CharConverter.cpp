// CharConverter.cpp : 
// Converter Class prompt the user to input a string. 
// Then it calls the properWords function and displays the resulting string. 
// Finally, it will call the uppercase function and display the resulting string. 
// The program will loop to allow additional strings to be converted and displayed until the user chooses to quit.


#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

/*******************
CharConverter is class that converts strings to all uppercase and
also all words to Proper Words (i.e. first letter in each word is uppercase)
********************/
class CharConverter {

public:
	string phrase_to_convert; // phrase to be converted
	vector<string> phrase_as_properWords; // data structure to save converted proper words
	vector<string> phrase_as_uppercase; // data structure to save converted upper case words

	CharConverter(); // Default constructor
	CharConverter(string &); // Paramaterized constructor initializing phrase to convert with the input string
	void properWords(string); // converts first letter in a word to upper case
	void uppercase(string); // converts all letters in a word that are lower case to uppercase
	void printVector(const vector<string> &, const string); // Prints the words in the vector with spaces in between
};

// Main Function
int main()
{
	string strToBeConverted; // string input by user
	char choice; // choice to end or continue program input by user
	bool isdone = false; // flag to end program if true and continue if false
	// Program main loop
	cout << "Welcome to the Character Converter Program. Please enter a word or sentence." << endl;
	cout << "Please note numbers are allowed but will not be converted" << endl;
	while (!isdone) { // While user is using program loop until user is done
		
		getline(cin, strToBeConverted); // get the entire line if user inputs more than one word
		CharConverter converter = CharConverter(strToBeConverted); // init character converter class
		istringstream iss(converter.phrase_to_convert); // init a string stream to loop through each word
		if (strToBeConverted == "") {
			cout << "You did not enter anything. Please enter a word or sentence." << endl;
		}
		else {
			while (iss) {
				string word; // temp string
				iss >> word; // assign next word to variable word
				if (!(word == "")) { // for some reason the last word in string stream always empty string
					converter.uppercase(word); // convert all letters in word to upper case
					converter.properWords(word); // convert word to proper word
				}
			}
			cout << "\nPhrase converted to Proper Words" << endl;
			converter.printVector(converter.phrase_as_properWords, strToBeConverted); // print all the words
			cout << "\nPhrase converted to all Uppercase" << endl;
			converter.printVector(converter.phrase_as_uppercase, strToBeConverted); // prints all the words

			
			// ask the user if they want to run the program again
			cout << "\nWould you like to enter another sentence to be convertered? Enter Y to continue or N to quit" << endl;
			cin >> choice; // choice input by user
			cin.ignore(); // ignore new line character
			if (choice == 'y' || choice == 'Y') { // end program
				cout << "Awesome!!!Please enter another word or sentence!!!" << endl;
			}
			else if (choice == 'n' || choice == 'N') {
				cout << "Thank you for choosing the Character Converter for your character converting needs. Have a nice day!" << endl;
				isdone = true; // change the flag to end the main loop
			}
			else { // The user for some reason didn't follow instructions. Program will exit if user doesnt follow directions!
				cout << "You didn't enter either Y or y or N or n. The program will now exit." << endl;
				cout << "Thank you for choosing the Character Converter for your character converting needs. Have a nice day!" << endl;
				isdone = true;
			}
		}
		
	}
	return 0;
}

/*******************
CharConverter::CharConverter()
Defualt constructor for class
********************/
CharConverter::CharConverter()
{
	phrase_to_convert = "";
}

/*******************
CharConverter::CharConverter()
Parameterized constructor for class to initialize phrase to convert
********************/
CharConverter::CharConverter(string &toConvert)
{
	phrase_to_convert = toConvert;
}


/*******************
CharConverter::properWords(string toConvert)
Converts the string parameter to a proper word
A proper word has the first letter in the word capitalized
********************/
void CharConverter::properWords(string toConvert)
{
	if (!isupper(toConvert[0])) { // if char is lower case make it upper case otherwise ignore the char
		toConvert[0] = toupper(toConvert[0]); // make the first character in the string uppercase
	}
	phrase_as_properWords.push_back(toConvert); // save the changed word to the vector
}

/*******************
void CharConverter::uppercase(string toConvert)
Converts the string parameter to an all uppercase word
********************/
void CharConverter::uppercase(string toConvert)
{
	for (int i = 0; i < toConvert.size(); i++) { // Loops through each character in the word
		if (!isupper(toConvert[i])) { // if char is lower case make it upper case otherwise ignore the char
			char converted = toupper(toConvert[i]); // convert char i to uppercase and save it in a temp variable
			toConvert[i] = converted; // put new char back into the word
		}
	}
	phrase_as_uppercase.push_back(toConvert); // save the changed word to the vector
}

/*******************
void CharConverter::printVector(const vector <string> &vectorToPrint, const string original)
Prints the word in the vector on the same line seperated by spaces
********************/
void CharConverter::printVector(const vector <string> &vectorToPrint, const string original)
{
	cout << "\nThe phrase \"" << original << "\" was converted to --> "; // show the original string for comparison
	for (int i = 0; i < vectorToPrint.size(); i++) {  // loop through the vector
		cout << vectorToPrint[i] << " "; // print the word and a space
	}
	cout << "" << endl;
}


