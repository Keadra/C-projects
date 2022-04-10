// File name: GridSolver.h
// Author: Chengye Hao
// userid: haoc2
// Email: chengye.hao@vanderbilt.edu
// Class: cs2201
// Assignment Number: PA10
// Honor Statement: I did not give or receive any help on this assignment from
// sources other than the instructors
// Description: This file contains declaration of functions in GridSolver class, which is used to find the
// longest increasing sequence in a Grid.
// Last Changed:2021/12/7
#ifndef PROJECT10_GRIDSOLVER_H
#define PROJECT10_GRIDSOLVER_H

#include <stack>
#include "Grid.h"


class GridSolver {
public:
    //constructor of GridSolver class
    GridSolver(const std::string& fileName);

    //function that solves myGrid for the longest increasing sequence
    void solve();

private:
    Grid myGrid;
    std::stack<int> mySequence;

    //displays myGrid
    void displayGrid () const;

    //get the longest increasing sequence in the Grid
    void getLongestSequence();

    //Pre: cur is a GridPoint where the search started, sequence is the GridPoints recorded before this
    //recursive call
    //Post: return a stack of GridPoints that contains the longest increasing sequence start from cur
    //a recursive backtracking function that finds the longest increasing sequence starts from a specific GridPoint
    std::stack<int> longestRun(GridPoint cur, std::stack<int> sequence);

    //Pre: sequence is a stack of GridPoint that stores the longest increasing sequence in the Grid
    //print the longest increasing sequence in the grid
    static void printResult (std::stack<int> sequence);
};



#endif //PROJECT10_GRIDSOLVER_H
