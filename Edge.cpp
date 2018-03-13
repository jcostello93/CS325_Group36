#include "Edge.hpp"



Edge::Edge(City* c1, City* c2, int x1In, int x2In, int y1In, int y2In)
{
	beg = c1; 
	end = c2; 
	x1 = x1In; 
	x2 = x2In; 
	y1 = y1In; 
	y2 = y2In; 
}


Edge::~Edge()
{
}


City* Edge::getBegEdge() {
	return beg;
}

City* Edge::getEndEdge() {
	return end; 
}
