#include "City.hpp"

City::City(int a, int b, int c) {
	this->id = a; 
	this->x = b; 
	this->y = c; 
	this->color = "white"; 
}

void City::addNeighbors(City *p) {
	this->neighbors.push_back(p); 
}

void City::printCity() {
	cout << this->id << " ";
	cout << this->x << " ";
	cout << this->y << " ";
/*	cout << "Neighbors: "; 
	
	for (int i = 0; i < this->neighbors.size(); i++) {
		cout << this->neighbors[i]->id << " "; 
	}*/

	cout << endl; 
}

int City::getX() {
	return this->x; 
}

int City::getY() {
	return this->y;
}

int City::getId() {
	return this->id;
}

string City::getColor() {
	return this->color; 
}

void City::setColor(string c) {
	this->color = c;
}

vector<City*> City::getNeighbors() {
	return neighbors; 
}

void City::setEdgeIn(Edge* in) {
	edgeIn = in; 
}
void City::setEdgeOut(Edge* out) {
	edgeOut = out; 
}
