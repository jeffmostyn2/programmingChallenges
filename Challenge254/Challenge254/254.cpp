/* Writer: Jeffrey Mostyn
Date: 2/15/2016
Program Name: 252.cpp

This program is written as a solution to the r/DailyProgrammer Challenge #254: https://www.reddit.com/r/dailyprogrammer/comments/45w6ad/20160216_challenge_254_easy_atbash_cipher/
*/

#include <iostream>
#include <string>

using namespace std;

string convert(string input);

int main(void) {
	// Variables
	string input, cipher;
	
	// Prints directions and takes a string (or a line) as input
	cout << "Enter a string that will have the Atbash cipher applied to it." << endl;
	getline(cin, input);

	// Calls the convert function
	cipher = convert(input);

	// Prints ciphered string or line
	cout << cipher << endl;

	return 0;
}

// This function takes a string and applies an atbash cipher to it
string convert(string input) {
	// Loop through string, to look at each letter and convert it to 'ciphered' letter, then make new string of those letters
	for (unsigned int i = 0; i < input.size(); i++) {
		if (input[i] >= 'A' && input[i] <= 'Z')
			input[i] = 'Z' - (input[i] - 'A');
		else if (input[i] >= 'a' && input[i] <= 'z')
			input[i] = 'z' - (input[i] - 'a');
		else
			input[i] = input[i];
	}
	return input;
}