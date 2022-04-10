// File name: Grid.h
// Author: Chengye Hao
// userid: haoc2
// Email: chengye.hao@vanderbilt.edu
// Class: cs2201
// Assignment Number: PA10
// Honor Statement: I did not give or receive any help on this assignment from
// sources other than the instructors
// Description: This file contains declaration of functions of Grid class, which is used to store and access
// 25 integers in a grid. The design of Grid class is based on Maze class in CS2201 PA07
// Last Changed:2021/12/7

#ifndef PROJECT10_GRID_H
#define PROJECT10_GRID_H


#include <string>
#include <fstream>
#include <iostream>
#include "GridPoint.h"

const std::string TEST_FILE = "test.txt";
const int GRID_SIZE = 5;

class Grid {
public:

    //Pre: constant reference to a string that is the name of a valid input file
    //post: throw an invalid argument exception when the file does not exist
    //constructor of Grid class
    Grid(const std::string& fileName);

    //Pre: x and y are integers that represents a location on the Grid
    //marks a specific location as visited
    void markVisited(int x, int y);

    //Pre: location is a GridPoint that represents a location on the Grid
    //marks a specific location as visited
    void markVisited(GridPoint location);

    //Pre: x and y are integers that represents a location on the Grid
    //Post: return whether the location represented by x and y has been visited
    //check whether a specific location has been visited
    bool isVisited(int x, int y);

    //Pre: location is a GridPoint that represents a location on the Grid
    //Post: return whether the location represented by location has been visited
    //check whether a specific location has been visited
    bool isVisited(GridPoint location);

    //Pre: x and y are integers that represents a location on the Grid
    //Post: return the integer stores in the location
    //get the integer stores in the location
    int getInt(int x, int y) const;

    //Pre: location is a GridPoint that represents a location on the Grid
    //Post: return the integer stores in the location
    //get the integer stores in the location
    int getInt(GridPoint location) const;


    //Pre: location is a GridPoint that represents a Grid location
    //Post: return whether the location is on the Grid
    //check whether the location is inside the Grid
    bool inRange(GridPoint location);

private:
    int gridInt[GRID_SIZE][GRID_SIZE];
    bool visited[GRID_SIZE][GRID_SIZE];

    //Pre: x and y are integers that represents a Grid location
    //throw an exception if location represented by x and y is not on the Grid
    void checkRange(int x, int y) const;
};



#endif //PROJECT10_GRID_H
