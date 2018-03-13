#pragma once
#include "City.hpp"
#ifndef EDGE_HPP
#define EDGE_HPP

class Edge
{
private: 
	int x1;
	int x2;
	int y1;
	int y2; 
	City* beg; 
	City* end; 


public:
	Edge(City*, City*, int, int, int, int);
	~Edge();
	City* getBegEdge(); 
	City* getEndEdge(); 
};

#endif
