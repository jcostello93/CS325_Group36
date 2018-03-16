#pragma once
#pragma once
#ifndef INPUT_OUTPUT_HPP
#define INPUT_OUTPUT_HPP

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include "City.hpp"

using namespace std;

void displayTitle();
void displayEndMsg();
bool openFiles(ifstream &inFile, ofstream &outFile, char *fileName);
void readCitiesFromFile(ifstream &inFile, vector<City*> *cities);
void deleteCities(vector<City*> cities);


#endif
