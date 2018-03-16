/*********************************************************************
** Program name:  TRAVELLING SALESMAN PROBLEM
** Project Group 36
** Author:  Bao Chau, John Costello, Sarah Walter
** Date:  03/16/2108
** Description: Implement the K-Opt Algorithm to solve the 
**		  	 Travelling Salesman Problem.
*********************************************************************/

#include "InputOutput.hpp"
#include "City.hpp"
#include "Route.hpp"
#include <climits>
#include <time.h>

int main(int argc, char *argv[]) {
	ifstream inFile;
	ofstream outFile;
	vector<City*> cities;
	clock_t startTime;
	double elapsedTime;
	Route *route;
	int numberOfCity;

	//Display program's title
	displayTitle();

	if (argc < 2) {
		cout << "please provide the input file name." << endl;
	}
	else if (openFiles(inFile, outFile, argv[1])) {	//"test-input-4.txt"  //argv[1]
		startTime = clock();
		cout << "Timer started." << endl;

		//Read cities from input file.
		readCitiesFromFile(inFile, &cities);
		numberOfCity = cities.size();

		elapsedTime = (float)(clock() - startTime) / CLOCKS_PER_SEC;
		cout << "Data imported." << endl;

		//Running optimization algorithm.
		cout << "\n\nOptimizing........." << endl;
		route = new Route();
		if (numberOfCity <= 250) {
			route->levelOneOptimization(cities);
		}
		else if (numberOfCity <= 500) {
			route->levelTwoOptimization(cities, 10);
		}
		else if (numberOfCity <= 1000) {
			route->levelTwoOptimization(cities, 100);
		}
		else if (numberOfCity <= 2000) {
			route->levelThreeOptimization(cities, cities.size());
		}
		else {
			//route->levelThreeOptimization(cities, cities.size());
			route->levelThreeOptimization(cities, 175);
		}

		cout << "The optimized Route is: " << route->getTotalLength() << endl;
		cout << "\nOptimization completed." << endl;			

		//Save result to output file.
		route->saveResultToFile(outFile);		// < ----call function here when it's implemented.
		cout << "Saved results to output file."<< endl;

		//Clean up.
		deleteCities(cities);
		delete(route);
		inFile.close();
		outFile.close();
		cout << "Cleaned up." << endl;

		elapsedTime = (float)(clock() - startTime) / CLOCKS_PER_SEC;
		cout << "\nTotal time elapsed = " << elapsedTime << " seconds." << endl;
	}
		
	cout << "\nThank you for using the program. Good Bye!\n\n\n";
	return 0;
}