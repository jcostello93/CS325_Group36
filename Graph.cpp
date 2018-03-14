#include "Graph.hpp"
#include "City.hpp"
#include "Route.hpp"
#include <vector>

void createGraph(vector<City*> cities) {
	for (int i = 0; i < cities.size(); i++) {
		for (int j = i + 1; j < cities.size(); j++) {
			cities[i]->addEdge(cities[j]);
			cities[j]->addEdge(cities[i]);
		}
	}
}

/*    Original createRoute */
//Route* createRoute(vector<City*> cities) {
//	Route *route = new Route(cities);
//	int total = route->calculateDistance();
//
//	route->printRoute();
//	cout << "Total length: " << total << endl;
//   return route;
//}

Route* createRoute(vector<City*> cities)
{
	Route *route = new Route();

	City* city = NULL;
	if (cities.size() > 0) {
		city = cities[0];
	}

	while (city) {
		route->addCity(city);
		city->setVisited();
		city = city->getNearestUnvisitedNeighbor();
	}
	//for (int i = 0; i < cities.size(); i++) {
	//	route->addCity(cities[i]);
	//}
	return route;
}

Route* optimizeRoute(Route* route, int i, int k) {
	Route *newRoute = new Route();
	int index;
	// take route[0] to route[i - 1] and add them in order to new_route
	for (index = 0; index <= i; index++) {
		newRoute->addCity(route->getCity(index));
	}

	// take route[i] to route[k] and add them in reverse order to new_route
	for (index = k; index > i; index--) {
		newRoute->addCity(route->getCity(index));
	}

	// take route[k + 1] to end and add them in order to new_route
	for (index = k + 1; index < route->getSize(); index++) {
		newRoute->addCity(route->getCity(index));
	}
	return newRoute;
}

void twoOptAlgorithm(Route* route) {
	if (route) {
		Route *newRoute, *bestRoute;
		int size, minDistance, newDistance, count;
		bool optimized, done;

		size = route->getSize();
		minDistance = route->getTotalLength();
		bestRoute = route;
		done = false;
		count = 0;
		while (!done) {
			optimized = false;
			for (int i = 0; i < size - 1; i++) {
				for (int k = i + 1; k < size; k++) {
					newRoute = optimizeRoute(bestRoute, i, k);
					newDistance = newRoute->getTotalLength();
					if (newDistance < minDistance) {
						minDistance = newDistance;
						free(bestRoute);
						bestRoute = newRoute;
						optimized = true;
					}
				}
			}			
			done = !optimized; 
			count++;
			cout << "count: " << count << ": " << bestRoute->getTotalLength() << endl;
		}

		cout << "The optimized Route is: " << endl;
		bestRoute->newPrintRoute();
	}
}




