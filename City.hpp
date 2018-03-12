#pragma once
#ifndef CITY_HPP
#define CITY_HPP
#include <iostream> 
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::cout;
using std::endl;


class City {
private: 
	vector<City*> neighbors; 
	string color; 
	int id; 
	int x; 
	int y; 

public: 
	City(int, int, int); 
	void addEdge(City*); 
	void printCity(); 
	int getX(); 
	int getY(); 
	string getColor(); 
	void setColor(string); 
	vector<City*> getNeighbors(); 
};

#endif