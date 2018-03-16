## TSP Makefile
## Sarah Walter, John Costello, Bao Chau

tspProject: main.cpp City.cpp City.hpp Route.cpp Route.hpp InputOutput.hpp InputOutput.cpp
	g++ -std=c++0x main.cpp City.cpp Route.cpp InputOutput.cpp -o tspProject
  
# clean
clean:
	rm -f *.o tspProject
