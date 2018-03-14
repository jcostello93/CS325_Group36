#pragma once
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include "City.hpp"
#include "Route.hpp"

void createGraph(vector<City*> cities);
Route* createRoute(vector<City*> cities);
void twoOptAlgorithm(Route*);

#endif