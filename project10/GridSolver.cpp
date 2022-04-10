// File name: GridSolver.cpp
// Author: Chengye Hao
// userid: haoc2
// Email: chengye.hao@vanderbilt.edu
// Class: cs2201
// Assignment Number: PA10
// Honor Statement: I did not give or receive any help on this assignment from
// sources other than the instructors
// Description: This file contains definition of functions in GridSolver class, which is used to find the
// longest increasing sequence in a Grid.
// Last Changed:2021/12/7

#include "GridSolver.h"

//constructor of GridSolver class
GridSolver::GridSolver(const std::string& fileName): myGrid(fileName),
                                                     mySequence(){
}

//function that solves myGrid for the longest increasing sequence
void GridSolver::solve() {
    displayGrid();
    getLongestSequence();
    printResult(mySequence);
}

//displays myGrid
void GridSolver::displayGrid() const {
    std::cout << "Given this grid:" << std::endl;

    for (int row = 0; row < GRID_SIZE; ++row) {
        for (int col = 0; col < GRID_SIZE; ++col) {
            std::cout << myGrid.getInt(col, row) <<" ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

//get the longest increasing sequence in the Grid
void GridSolver::getLongestSequence() {
    for (size_t row = 0; row < GRID_SIZE; ++row) {
        for (size_t col = 0; col < GRID_SIZE; ++col) {
            GridPoint cur((int)col, (int)row);
            std::stack<int> tmp;

            if (!myGrid.isVisited(cur)) {
                tmp = longestRun(cur, tmp);
                //since the minimum longest run is 1, it prevents empty mySequence
                if (tmp.size() > mySequence.size()) {
                    mySequence = tmp;
                } else if ((tmp.size() == mySequence.size())&& (tmp.top() < mySequence.top())) {
                    mySequence = tmp;
                }
            }
        }
    }
}

//Pre: cur is a GridPoint where the search started, sequence is the GridPoints recorded before this
//recursive call
//Post: return a stack of GridPoints that contains the longest increasing sequence start from cur
//a recursive backtracking function that finds the longest increasing sequence starts from a specific GridPoint
std::stack<int> GridSolver::longestRun(GridPoint cur, std::stack<int> sequence ) {

    GridPoint tmp(cur.x, cur.y);
    sequence.push(myGrid.getInt(cur));
    std::stack<int> curSequence(sequence);

    myGrid.markVisited(cur);

    for (int row = -1; row < 2; ++row) {
        tmp.x = cur.x + row;
        for (int col = -1; col < 2; ++col) {
            tmp.y = cur.y + col;
            if((myGrid.inRange(tmp)) && (tmp != cur)){
                if(myGrid.getInt(tmp)<myGrid.getInt(cur)) {
                    std::stack<int> tmpLongest (longestRun(tmp, sequence));
                    if (tmpLongest.size() > curSequence.size()) {
                        curSequence = tmpLongest;
                    }
                    else if(tmpLongest.size()==curSequence.size()){
                        if(curSequence.top() > tmpLongest.top()){
                            curSequence = tmpLongest;
                    }
                  }
                }
            }
        }
    }
    return curSequence;
}


//Pre: sequence is a stack of GridPoint that stores the longest increasing sequence in the Grid
//print the longest increasing sequence in the grid
void GridSolver::printResult(std::stack<int> sequence) {

    if(sequence.empty()){
        return;
    }
    std::cout <<"The longest run of increasing integers found was: "<< sequence.top();
    sequence.pop();

    while (!sequence.empty()){
        std::cout <<", " <<sequence.top();
        sequence.pop();
    }

    std::cout << std::endl;
}
