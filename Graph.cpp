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

void createRoute(vector<City*> cities) {
	Route *route = new Route(cities);
	int total = route->calculateDistance();

	route->printRoute();
	cout << "Total length: " << total << endl;
}
