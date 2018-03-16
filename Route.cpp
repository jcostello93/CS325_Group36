#include "Route.hpp"
#include <climits>
#include <time.h>

Route::Route()
{
	headPtr = new City(-1, 0, 0);
	tailPtr = new City(-1, 0, 0);
	initialize();
}


Route::~Route() 
{
	delete(headPtr);
	delete(tailPtr);
}

void Route::initialize() 
{
	this->size = 0;
	this->totalLength = 0;
	headPtr->setNextCity(tailPtr);
	tailPtr->setPrevCity(headPtr);
}

int Route::getSize() { return this->size; }
int Route::getTotalLength() { return this->totalLength; }

void Route::removeCityFromList(City *city) 
{
	City *prevCity = city->getPrevCity();
	City *nextCity = city->getNextCity();

	prevCity->setNextCity(nextCity);
	nextCity->setPrevCity(prevCity);
}

void Route::addCity(City* newCity, int distance)
{
	City *lastCity;
	if (newCity) {
		lastCity = tailPtr->getPrevCity();

		lastCity->setNextCity(newCity);
		newCity->setPrevCity(lastCity);

		newCity->setNextCity(tailPtr);
		tailPtr->setPrevCity(newCity);

		this->totalLength += distance;
		this->size++;
	}
}

City* Route::createCityList(const  vector<City*> cities)
{
	City *headPtr = new City(-1, 0, 0);
	City *tailPtr = new City(-1, 0, 0);
	City *curCity;
	int numberOfCity = cities.size();

	curCity = headPtr;
	for (int i = 0; i < numberOfCity; i++) {
		curCity->setNextCity(cities[i]);
		cities[i]->setPrevCity(curCity);
		curCity = cities[i];
	}
	curCity->setNextCity(tailPtr);
	tailPtr->setPrevCity(curCity);

	return headPtr;
}

void Route::addCities(const vector<City*> cities, int startIndex)
{
	City *curCity, *nearestCity, *tempCity, *cityList;
	City *firstCityInList;
	int minDistance, tempDistance, numberOfCity;

	initialize();
	numberOfCity = cities.size();

	if (numberOfCity > 0) {
		//Convert vector into linked list.
		cityList = createCityList(cities);

		//Add the first City in the list
		firstCityInList = cities[startIndex]; 
		removeCityFromList(firstCityInList);
		this->addCity(firstCityInList, 0);

		curCity = firstCityInList;
		for (int i = 0; i < (numberOfCity - 1); i++) {
			tempCity = cityList->getNextCity();
			minDistance = INT_MAX;

			while (tempCity->getNextCity() != NULL) {
				tempDistance = curCity->calculateDistance(*tempCity);
				if (tempDistance <= minDistance) {
					minDistance = tempDistance;
					nearestCity = tempCity;
				}
				tempCity = tempCity->getNextCity();
			}

			removeCityFromList(nearestCity);
			this->addCity(nearestCity, minDistance);
			curCity = nearestCity;
		}

		tailPtr->setX(firstCityInList->getX());
		tailPtr->setY(firstCityInList->getY());
		this->totalLength += curCity->calculateDistance(*firstCityInList);

		delete(cityList->getNextCity());
		delete(cityList);
	}
}

void Route::saveResultToFile(ofstream &outFile) {
	City * city;
	//calculateTotalLength();

	outFile << this->getTotalLength() << endl;
	city = this->headPtr->getNextCity();

	while (city != this->tailPtr) {
		outFile << city->getId() << endl;
		city = city->getNextCity();
	}
}

bool Route::twoOptSwap(int i, int k)
{
	City *iPrevCity, *iCity, *kCity, *kNextCity;
	City *tempCity, *nextCity, *curCity;

	int oldXLength, oldYLength, newXLength, newYLength;
	int improveDistance;
	int count = 0;

	tempCity = this->headPtr->getNextCity();

	while (count <= k) {
		if (count == i) {
			iCity = tempCity;
			iPrevCity = tempCity->getPrevCity();
		}
		else if (count == k) {
			kCity = tempCity;
			kNextCity = tempCity->getNextCity();
		}
		tempCity = tempCity->getNextCity();
		count++;
	}

	oldXLength = iPrevCity->calculateDistance(*iCity);
	oldYLength = kCity->calculateDistance(*kNextCity);

	newXLength = iPrevCity->calculateDistance(*kCity);
	newYLength = iCity->calculateDistance(*kNextCity);

	improveDistance = (oldXLength + oldYLength) - (newXLength + newYLength);

	if (improveDistance > 0) {

		iPrevCity->setNextCity(NULL);
		iCity->setPrevCity(NULL);

		kCity->setNextCity(NULL);
		kNextCity->setPrevCity(NULL);

		curCity = iCity;
		nextCity = curCity->getNextCity();

		while (nextCity != NULL) {
			curCity->setPrevCity(nextCity);
			tempCity = nextCity->getNextCity();

			nextCity->setNextCity(curCity);
			curCity = nextCity;
			nextCity = tempCity;
		}

		iPrevCity->setNextCity(kCity);
		kCity->setPrevCity(iPrevCity);

		iCity->setNextCity(kNextCity);
		kNextCity->setPrevCity(iCity);

		this->totalLength -= improveDistance;
		return true;
	}
	return false;
}

void Route::twoOptAlgorithm(int count) {
	int size;
	bool done;

	size = this->size;
	if (count > size) { count = size; }

	if (size > 2) {		
		done = false;
		while (!done) {
			done = true;
			for (int i = 1; i < count - 1; i++) {
				for (int k = i + 1; k < size; k++) {
					if (this->twoOptSwap(i, k)) {
						done = false;
					}
				}				
			}
		}
	}
}

void Route::levelOneOptimization(vector<City*> cities)
{
	int minGraph, minDistance, maxCount;

	minGraph = 0;
	minDistance = INT_MAX;
	maxCount = cities.size();

	for (int i = 0; i < maxCount; i++) {
		this->addCities(cities, i);
		this->twoOptAlgorithm(1000);
		if (this->getTotalLength() < minDistance) {
			minDistance = this->getTotalLength();
			minGraph = i;
		}
	}
	 
	this->addCities(cities, minGraph);
	this->twoOptAlgorithm(1000);
}

void Route::levelTwoOptimization(vector<City*> cities, int count)
{
	int minGraph, minDistance, maxCount;

	minGraph = 0;
	minDistance = INT_MAX;
	maxCount = cities.size();
	for (int i = 0; i < maxCount; i += count) {
		this->addCities(cities, i);
		this->twoOptAlgorithm(1000);
		if (this->getTotalLength() < minDistance) {
			minDistance = this->getTotalLength();
			minGraph = i;
		}
	}

	this->addCities(cities, minGraph);
	this->twoOptAlgorithm(1000);
}

void Route::levelThreeOptimization(vector<City*> cities,  int count)
{
	int minGraph, minDistance, maxCount;
	int increment;

	minGraph = 0;
	minDistance = INT_MAX;
	maxCount = (cities.size() > 2000) ? 2000 : cities.size();
	increment = (cities.size() <= 2000) ? 2 : 20;

	for (int i = 0; i < maxCount; i += increment) {
		this->addCities(cities, i);
		if (this->getTotalLength() < minDistance) {
			minDistance = this->getTotalLength();
			minGraph = i;
		}
	}

	this->addCities(cities, minGraph);
	this->twoOptAlgorithm(count);
}