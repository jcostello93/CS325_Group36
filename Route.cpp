#include "Route.hpp"
#include <math.h>
#include <limits>

Route::Route(vector<City*> c)
{
	this->cities = c; 
}

int Route::calculateDistance() {

	int total = 0; 
	
	City *current = this->cities[0];				//start at first city 
	queue<City*> Q; 
	Q.push(current); 

	while (Q.size() > 0) {
		current = Q.front();
		Q.pop();

		current->setColor("black");					//black means visited 
		route.push_back(current);					//keep track of route

		int d1, d2, sq1, sq2, sum, sqr, idx = 0; 
		int min = std::numeric_limits<int>::max();

		int x1, x2, y1, y2; 
		x1 = current->getX(); 
		y1 = current->getY(); 

		for (int i = 0; i < current->getNeighbors().size(); i++) {
			if (current->getNeighbors()[i]->getColor() == "white") {
				x2 = current->getNeighbors()[i]->getX();
				y2 = current->getNeighbors()[i]->getY();

				d1 = x1 - x2;							//calculate distance
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
			Edge* e = new Edge(current, current->getNeighbors()[idx], current->getX(), current->getNeighbors()[idx]->getX(), current->getY(), current->getNeighbors()[idx]->getY()); 
			current->setEdgeOut(e);
			current->getNeighbors()[idx]->setEdgeIn(e); 
			edges.push_back(e); 
		}

	}

	int lastStretch = goBackHome(current);					//turn path into cycle
	total = total + lastStretch; 
	
	return total; 
}

vector<City*> Route::getCities() {
	return this->cities; 
}

int Route::goBackHome(City* current) {
	int x1 = current->getX(); 
	int y1 = current->getY(); 
	int x2 = cities[0]->getX(); 
	int y2 = cities[0]->getY(); 

	int d1, d2, sq1, sq2, sum, sqr = 0;


	d1 = x1 - x2;
	d2 = y1 - y2;
	sq1 = d1 * d1;
	sq2 = d2 * d2;
	sum = sq1 + sq2;
	sqr = sqrt(sum);

	route.push_back(cities[0]); 

	Edge* e = new Edge(current, cities[0], current->getX(), cities[0]->getX(), current->getY(), cities[0]->getY());
	current->setEdgeOut(e);
	cities[0]->setEdgeIn(e);
	edges.push_back(e);
	cout << "From " << current->getId() << " to " << cities[0]->getId() << endl; 

	return sqr; 
}

void Route::printRoute() {
	for (int i = 0; i < route.size(); i++) {
		cout << i << ": " << route[i]->getId() << endl; 
	}

	cout << "Edges: " << endl; 

	for (int i = 0; i < edges.size(); i++) {
		cout << "Edge " << i << "    Beginning City: " << edges[i]->getBegEdge()->getId() << "   "; 
		cout << "End City: " << edges[i]->getEndEdge()->getId() << endl; 
	}

}

void Route::checkEdges() {

	for (int i = 0; i < edges.size(); i++) {
		Edge *e1 = edges[i];
		for (int j = i + 1; j < edges.size(); j++) {
			Edge *e2 = edges[j]; 

			int a = checkIntersect(e1, e2); 

			if (a == 1) {
				cout << "Swap!" << endl;
				system("pause"); 
			} 
			else {
				cout << "No swap!" << endl; 
			}
		}
	}
}

int Route::checkIntersect(Edge* e1, Edge* e2) {
	int e1_x1 = e1->getBegEdge()->getX();
	int e1_y1 = e1->getBegEdge()->getY();
	int e1_x2 = e1->getEndEdge()->getX();
	int e1_y2 = e1->getEndEdge()->getY();
	int e2_x1 = e2->getBegEdge()->getX();
	int e2_y1 = e2->getBegEdge()->getY();
	int e2_x2 = e2->getEndEdge()->getX();
	int e2_y2 = e2->getEndEdge()->getY();

	int o1 = orientation(e1_x1, e1_y1, e1_x2, e1_y2, e2_x1, e2_y1); 
	int o2 = orientation(e1_x1, e1_y1, e1_x2, e1_y2, e2_x2, e2_y2);
	int o3 = orientation(e2_x1, e2_y1, e2_x2, e2_y2, e1_x1, e1_y1); 
	int o4 = orientation(e2_x1, e2_y1, e2_x2, e2_y2, e1_x2, e1_y2);

	cout << "e1_x1: " << e1_x1 << "  e1_y1: " << e1_y1 << endl;
	cout << "e1_x2: " << e1_x2 << "  e1_y2: " << e1_y2 << endl;
	cout << "e2_x1: " << e2_x1 << "  e2_y1: " << e2_y1 << endl;
	cout << "e2_x2: " << e2_x2 << "  e2_y2: " << e2_y2 << endl;

	if ((e1_x2 != e2_x1 && e1_y2 != e2_y1) && (e1_x1 != e2_x2 && e1_y1 != e2_y2)) {
		if (o1 != o2 && o3 != o4) {
			return 1;
		}
	}

	return 0; 


}

int Route::orientation(int p_x, int p_y, int q_x, int q_y, int r_x, int r_y) {

	int val = (q_y - p_y) * (r_x - q_x) - (q_x - p_x) * (r_y - q_y);

	if (val > 0) {
		return 1;
	}
	else {
		return 0; 
	}
}
