#pragma once
#ifndef ROUTE_HPP
#define ROUTE_HPP

#include "City.hpp"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

class Route
{
private:
	City *headPtr;
	City *tailPtr;
	int size;
	int totalLength;
	void initialize();
	void removeCityFromList(City *city);
	void addCity(City* nextCity, int distance);
	City* createCityList(const vector<City*> cities);
	bool twoOptSwap(int, int);

public:
	Route();
	~Route();

	int getSize();
	int getTotalLength();
	void addCities(vector<City*> cities, int startIndex);
	void saveResultToFile(ofstream &outFile);
	void twoOptAlgorithm(int count);
	void levelOneOptimization(vector<City*> cities);
	void levelTwoOptimization(vector<City*> cities, int count);
	void levelThreeOptimization(vector<City*> cities,  int count);
};
#endif