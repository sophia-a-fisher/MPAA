.DEFAULT_GOAL := all
SHELL         := bash

# compile run harness
run_mov: run_movie.cpp
	$(CXX) $(CXXFLAGS) run_movie.cpp -o run_movie

run: run_mov ./MPAA_Data/2012.in.txt
	./run_movie < ./MPAA_Data/2012.in.txt 


