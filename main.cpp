#include "InputOutput.hpp"
#include "City.hpp"
#include "Route.hpp"
#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <string> 
#include <fstream>
#include <cstdlib>
#include <time.h>

using std::cout; 
using std::endl; 
using std::ifstream; 
using std::getline; 


int main() {
	
	ifstream inFile;
	ofstream outFile;
	vector<City*> cities; 

	//Display program's title
	displayTitle();

	//Open input and output files (Will ask user for input file name)
	if (openFiles(inFile, outFile)) {
		clock_t t1, t2;
		int f;
		t1 = clock();
		printf("Calculating...\n");

		//Read cities from input file.
		readCitiesFromFile(inFile, &cities);

		//Display cities on screen (This is for debugging only).
		//printCities(cities);	// <---- Comment out (or delete) when submit.

		
		t2 = clock() - t1;
		cout << "Data imported. Time = " << ((float)t2) / CLOCKS_PER_SEC << endl;


		//Create Graph. 			
		createGraph(cities);
		t2 = clock() - t1;
		cout << "Graph created. Time = " << ((float)t2) / CLOCKS_PER_SEC << endl;

		//Get initial hamiltonian cycle.
		Route *route = createRoute(cities);
		//route->newPrintRoute();

		t2 = clock() - t1;
		cout << "\n\nInitial Route: " << route->getTotalLength() << endl;
		cout << "Route created. Time = " << ((float)t2) / CLOCKS_PER_SEC << endl;
		

		cout << "\n\nOptimizing........." << endl;
		//Optimization algorithm.
		twoOptAlgorithm(route);                    // <---- call function here when it's implemented.

		t2 = clock() - t1;
		cout << "Completed. Time = " << ((float)t2) / CLOCKS_PER_SEC << endl;

		//Check result (This is for debugging only).
		//                      <---- call function here when it's implemented.

		//Save result to output file.
		//                      <---- call function here when it's implemented.

		//Clean up.
		deleteCities(cities);	
		inFile.close();
		outFile.close();
	}
		
	cout << "\nThank you for using the program. Good Bye!\n\n";	

	system("pause");
	return 0; 
}
