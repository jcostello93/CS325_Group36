#include "InputOutput.hpp"
#include "City.hpp"

using namespace std;

void displayTitle() {
	cout << "\nTRAVELLING SALESMAN PROBLEM\n";
	cout << "Project Group 36\n";
	cout << "Bao Chau, John Costello, Sarah Walter\n";
	cout << "=========================================\n\n";
}

void displayEndMsg() {
	cout << "\nThank you for using the program. Good Bye!\n\n";
}


void readCitiesFromFile(ifstream &inFile, vector<City*> *cities) {
	int a, b, c;

	while (inFile >> a >> b >> c) {
		City *p = new City(a, b, c);
		cities->push_back(p);
	}
}

//Clean up memory used from cities.
void deleteCities(vector<City*> cities) {
	for (int i = 0; i < (int)cities.size(); i++)
	{
		delete(cities[i]);
	}
	cities.clear();
}



bool openFiles(ifstream &inFile, ofstream &outFile, char *fileName)
{
	bool done = false, status = false;
	string inFileName = fileName;
	string outFileName = inFileName + ".tour";

	inFile.open(inFileName);
	if (inFile.fail()) {
		cout << "\nUnable to open the \"";
		cout << inFileName;
		cout << "\" file for data reading.\n";
		cout << "Please check your command line input and try again.\n";
		return false;
	}

	outFile.open(inFileName + ".tour");
	if (outFile.fail())
	{
		//Create new prompt message.
		cout << "\nUnable to create the \"";
		cout << inFileName;
		cout << ".tour\" file for data output.\n";
		cout << "Please check your command line input and try again.\n";
		return false;
	}
	
	return true;
}
