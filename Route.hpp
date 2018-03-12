#pragma once
#ifndef ROUTE_HPP
#define ROUTE_HPP
#include "City.hpp"
#include <queue>
using std::queue;

class Route
{
private: 
	vector<City*> cities; 

public:
	Route(vector<City*>);
	int calculateDistance(); 
	vector<City*> getCities(); 
};
#endif

