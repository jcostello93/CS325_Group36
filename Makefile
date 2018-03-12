## TSP Makefile
## Sarah Walter, John Costello, Bao Chau

tspProject: main.cpp City.cpp City.hpp Route.cpp Route.hpp
	g++ -std=c++0x main.cpp City.cpp Route.cpp -o tspProject
  
# clean
clean:
	rm -f *.o tspProject
