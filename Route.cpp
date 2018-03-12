#include "Route.hpp"
#include <math.h>
#include <limits>




Route::Route(vector<City*> c)
{
	this->cities = c; 
}

int Route::calculateDistance() {

	int distance = 0; 
	int total = 0; 
	
	City *current = this->cities[0]; 
	vector<City*> route; 
	route.push_back(current); 
	queue<City*> Q; 
	Q.push(current); 

	while (Q.size() > 0) {

		current = Q.front();
		Q.pop();
		current->setColor("black");
		int d1, d2, sq1, sq2, sum, sqr, idx = 0; 
		int min = std::numeric_limits<int>::max();
		
		cout << "Visited node: "; 
		cout << current->getId() << endl; 

		int x1, x2, y1, y2; 
		x1 = current->getX(); 
		y1 = current->getY(); 

		for (int i = 0; i < current->getNeighbors().size(); i++) {
			if (current->getNeighbors()[i]->getColor() == "white") {
				x2 = current->getNeighbors()[i]->getX();
				y2 = current->getNeighbors()[i]->getY();

				d1 = x1 - x2;
				d2 = y1 - y2;
				sq1 = d1 * d1;
				sq2 = d2 * d2;
				sum = sq1 + sq2;
				sqr = sqrt(sum);

				if (i == 0) {
					min = sqr;
					idx = i;
				}
				else if (sqr < min) {
					min = sqr;
					idx = i;
				}

			}

		}

		if (min != std::numeric_limits<int>::max()) {
			total = total + min;
		}

		if (current->getNeighbors()[idx]->getColor() == "white") {
			Q.push(current->getNeighbors()[idx]);
		}

	}
	
	return total; 
}

vector<City*> Route::getCities() {
	return this->cities; 
}
