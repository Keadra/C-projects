// File name: project10.cpp
// Author: Chengye Hao
// userid: haoc2
// Email: chengye.hao@vanderbilt.edu
// Class: cs2201
// Assignment Number: PA10
// Honor Statement: I did not give or receive any help on this assignment from
// sources other than the instructors
// Description: This file contains the main function that solves a given Grid of integers with a GridSolver
// Last Changed:2021/12/7
#include "GridSolver.h"


// the main function that create a GridSolver and solve the grid in test.txt
int main() {
    //initialize a GridSolver
    GridSolver test(TEST_FILE);
    //solve the grid and print outcome
    test.solve();
    return 0;
}
