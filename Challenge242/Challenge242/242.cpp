/* Writer: Jeffrey Mostyn
   Date: 1/26/2016
   Program Name: 242.cpp

   This program is written as a solution to the r/DailyProgrammer Challenge #242: https://www.reddit.com/r/dailyprogrammer/comments/3twuwf/20151123_challenge_242_easy_funny_plant/
*/
#include <iostream>
#include <vector>

using namespace std;

int simWeek(int& weeks, vector<int>& plants);

int main(void) {
    // Variable declaration
	int initialFruits = 0;
	int numberOfFruits = 0;
	int population = 0;
	int weeks = 1;

	// Takes input for population and initial number of fruits
	cout << "POPULATION: ";
	cin >> population;
	cout << "FRUITS: ";
	cin >> initialFruits;
	cout << endl;

	// Creation of vector to represent plants
	vector<int> plantVector(initialFruits);

	numberOfFruits = initialFruits;

	// Initializes the vector by "planting" each of the fruits you are given
	for (int i = 0; i < numberOfFruits; i++)
		plantVector[i] = 0;

	// Simulates passage of time until the number of fruits produced in a week is equal to or greater than size of population
	do {
		numberOfFruits = simWeek(weeks, plantVector);
	} while (numberOfFruits < population);

	cout << "It takes " << weeks << " week(s) to feed " << population << " people when beginning with " << initialFruits << " fruits." 
		<< endl;

	return 0;
}

// This function simulates ahead a week in time to see how many fruits each plant produces, and makes additional plants with those fruits
// It also increments the 'weeks' variable by one each time it is called
int simWeek(int& weeks, vector<int>& plants) {
	
	// Local variables
	int fruits = 0; // Holds total number of fruits produced this week
	
	// Adds one to value of each plant, symbolizing number of fruits each produced this week, and calculates total number of fruits produced
	for (unsigned int i = 0; i < plants.size(); i++) {
		plants[i]++;
		fruits += plants[i];
	}

	// "Plants" a new plant for each fruit grown this week
	for (int i = 0; i < fruits; i++)
		plants.push_back(0);

	// Incrementing weeks variable to represent one week passing
	weeks++;

	return fruits;
}