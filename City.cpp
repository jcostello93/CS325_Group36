#include "City.hpp"
#include <math.h>
#include <climits>

using namespace std;

City::City(int a, int b, int c) {
	this->id = a; 
	this->x = b; 
	this->y = c; 
	this->color = "white"; 
	this->visited = false;
}

void City::addEdge(City *p) {
	this->neighbors.push_back(p); 
}

void City::printCity() {
	cout << this->id << " ";
	cout << this->x << " ";
	cout << this->y << " ";
	cout << "Neighbors: "; 
	
	for (int i = 0; i < this->neighbors.size(); i++) {
		cout << this->neighbors[i]->id << " "; 
	}

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

bool City::isVisited() {
	return this->visited;
}

void City::setVisited() {
	this->visited = true;
}

vector<City*> City::getNeighbors() {
	return neighbors; 
}

int City::calculateDistance(const City &city) {
	int xDiff = this->x - city.x;
	int yDiff = this->y - city.y;

	return (int)nearbyint(sqrt((xDiff * xDiff) + (yDiff * yDiff)));
}

City* City::getNearestUnvisitedNeighbor() {
	City *nearestCity = NULL;
	int distance;
	int minDistance = INT_MAX;

	for (int i = 0; i < this->neighbors.size(); i++) {
		if (!this->neighbors[i]->isVisited()) {
			distance = this->calculateDistance(*this->neighbors[i]);
			if (distance <= minDistance) {
				nearestCity = this->neighbors[i];
				minDistance = distance;
			}
		}
	}
	return nearestCity;
}