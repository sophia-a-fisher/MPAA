.DEFAULT_GOAL := all
SHELL         := bash

# compile run harness
run_Grades: run_movie.cpp
	$(CXX) $(CXXFLAGS) run_movie.cpp -o run_movie

run: run_movie ./MPAA Items/2000.txt
	./run_movie < ./MPAA Items/2000.txt 
