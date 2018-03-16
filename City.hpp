#pragma once
#ifndef CITY_HPP
#define CITY_HPP

#include <iostream> 
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class City
{
private: 
	int id;
	int x;
	int y;
	City *nextCity;
	City *prevCity;

public:
	City(int, int, int);
	~City();
	int getId();
	int getX();
	int getY();
	City* getNextCity();
	City* getPrevCity();

	void setX(int x);
	void setY(int Y);
	void setNextCity(City* city);
	void setPrevCity(City* city);

	int calculateDistance(const City &city);
};

#endif

