#include "InputOutput.hpp"
#include "City.hpp"
#include "Route.hpp"
#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <string> 
#include <fstream>
#include <cstdlib>

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

		//Read cities from input file.
		readCitiesFromFile(inFile, &cities);

		//Display cities on screen (This is for debugging only).
		printCities(cities);	// <---- Comment out (or delete) when submit.

		//Create Graph. 			
		createGraph(cities);

		//Get initial hamiltonian cycle.
		createRoute(cities);

		//Optimization algorithm.
		//                      <---- call function here when it's implemented.

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
