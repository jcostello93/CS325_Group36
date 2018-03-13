## TSP Makefile
## Sarah Walter, John Costello, Bao Chau

tspProject: main.cpp City.cpp City.hpp Route.cpp Route.hpp Graph.cpp Graph.hpp Edge.cpp Edge.hpp InputOutput.cpp InputOutput.hpp
	g++ -std=c++0x main.cpp City.cpp Route.cpp Graph.cpp Edge.cpp InputOutput.cpp -o tspProject
  
# clean
clean:
	rm -f *.o tspProject
