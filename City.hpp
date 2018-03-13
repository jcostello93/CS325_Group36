#pragma once

#include <iostream> 
#include <vector>
#include <string>
#ifndef CITY_HPP
#define CITY_HPP
using std::vector;
using std::string;
using std::cout;
using std::endl;

class Edge;

class City {
private: 
	vector<City*> neighbors;			//includes every other city
	vector<City*> edges;				//includes only the edges in the route
	Edge* edgeIn;
	Edge* edgeOut; 
	string color; 
	int id; 
	int x; 
	int y; 

public: 
	City(int, int, int); 
	void addNeighbors(City*); 
	void printCity(); 
	int getX(); 
	int getY(); 
	int getId(); 
	string getColor(); 
	void setColor(string); 
	vector<City*> getNeighbors(); 
	void setEdgeIn(Edge*); 
	void setEdgeOut(Edge*); 
};

#endif
