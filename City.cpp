#include "City.hpp"
#include <math.h>

using namespace std;

City::City(int a, int b, int c)
{
	this->id = a;
	this->x = b;
	this->y = c;
	this->nextCity = NULL;
	this->prevCity = NULL;
}

City::~City() { }

int City::getId() {	return this->id; }
int City::getX() { return this->x; }
int City::getY() { return this->y; }
City* City::getNextCity() { return this->nextCity; }
City* City::getPrevCity() { return this->prevCity; }

void City::setX(int x) { this->x = x; }
void City::setY(int y) {	this->y = y; }
void City::setNextCity(City* city) { this->nextCity = city; }
void City::setPrevCity(City* city) { this->prevCity = city; }

int City::calculateDistance(const City &city) 
{
	int xDiff = this->x - city.x;
	int yDiff = this->y - city.y;
	return (int)nearbyint(sqrt((xDiff * xDiff) + (yDiff * yDiff)));
}