#include "InputOutput.hpp"

using namespace std;

string trimString(const string inputStr);

void readCitiesFromFile(ifstream &inFile, vector<City*> *cities) {
	int a, b, c;

	while (inFile >> a >> b >> c)  {
		City *p = new City(a, b, c);
		cities->push_back(p); 
	}
}

//Print the list of cities.
//This function should be used while debugging only.
void printCities(vector<City*> cities) {

	cout << "List of cities read from input file: \n";
	for (int i = 0; i < (int)cities.size(); i++)
	{		
		cout << i << ": " << cities[i]->getId() << endl;
	}
	cout << endl;
}

//Clean up memory used from cities.
void deleteCities(vector<City*> cities) {
	for (int i = 0; i < (int)cities.size(); i++)
	{
		delete(cities[i]);
	}
	cities.clear();
}

void displayTitle() {
	cout << "\nTRAVELLING SALESMAN PROBLEM\n";
	cout << "Project Group 36\n";
	cout << "Bao Chau, John Costello, Sarah Walter\n";
	cout << "=========================================\n\n";	
}

bool openFiles(ifstream &inFile, ofstream &outFile)
{
	bool done = false, status = false;
	string fileName;
	
	cout << "\nPlease enter the input file name (Enter 'Q' to quit): ";

	while (!done) {
		inFile.close();
		outFile.close();

		//Read the file name from user.		
		getline(cin, fileName);

		//Trim the leading and trainling blank spaces of the string.
		fileName = trimString(fileName);

		if (fileName.compare("q") == 0 || fileName.compare("Q") == 0) {			
			done = true;
		}
		else if (fileName.length() == 0) {
			cout << "\nPlease enter the input file name (Enter 'Q' to quit): ";
		}
		else {
			//Try to open file. If failed, ask if user to enter another file name.
			inFile.open(fileName);			
			if (inFile.fail())
			{
				//Create new prompt message.
				cout << "\nUnable to open the \"";
				cout << fileName;
				cout << "\" file for data reading.\n";
				cout << "Please re-enter another input file name (Enter 'Q' to quit): ";
			}
			else {
				outFile.open(fileName + ".tour");
				if (outFile.fail())
				{
					//Create new prompt message.
					cout << "\nUnable to create the \"";
					cout << fileName;
					cout << ".tour\" file for data output.\n";
					cout << "Please re-enter another input file name (Enter 'Q' to quit): ";
				}
				else {
					done = true;
					status = true;
				}
			}
		}
	}
	return status;
}

//Remove leading and trailing of a string.
string trimString(string inputStr)
{
	int startPos, endPos, count, i;
	bool found;
	int length = (int)inputStr.length();

	//Find the position of the non-space character starting 
	//from the beginning of the string.
	startPos = 0;
	found = false;
	for (i = 0; (!found && (i < length)); i++)
	{
		if (!isspace(inputStr[i]))
		{
			startPos = i;
			found = true;
		}
	}

	//Find the position of the non-space character starting 
	//from the end of the string.
	endPos = -1;
	found = false;
	for (i = (length - 1); (!found && (i >= 0)); i--)
	{
		if (!isspace(inputStr[i]))
		{
			endPos = i;
			found = true;
		}
	}

	//Compute the number of characters to be return.
	count = (endPos - startPos) + 1;

	//the the substring starting from startPos with "count" characters.
	return inputStr.substr(startPos, count);
}