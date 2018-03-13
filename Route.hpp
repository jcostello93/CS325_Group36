#pragma once
#ifndef ROUTE_HPP
#define ROUTE_HPP
#include "City.hpp"
#include "Edge.hpp"
#include <queue>
using std::queue;

class Route
{
private: 
	vector<City*> cities; 
	vector<City*> route;
	vector<Edge*> edges; 

public:
	Route(vector<City*>);
	int calculateDistance(); 
	vector<City*> getCities(); 
	int goBackHome(City*);
	void printRoute(); 
	void checkEdges();
	int checkIntersect(Edge*, Edge*);
	int orientation(int, int, int, int, int, int);
};
#endif

