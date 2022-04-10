// File name: Grid.cpp
// Author: Chengye Hao
// userid: haoc2
// Email: chengye.hao@vanderbilt.edu
// Class: cs2201
// Assignment Number: PA10
// Honor Statement: I did not give or receive any help on this assignment from
// sources other than the instructors
// Description: This file contains definitions to functions of Grid class, which is used to store and access
// 25 integers in a grid. The design of Grid class is based on Maze class in CS2201 PA07
// Last Changed:2021/12/7
#include "Grid.h"

//Pre: constant reference to a string that is the name of a valid input file
//post: throw an invalid argument exception when the file does not exist
//constructor of Grid class
Grid::Grid(const std::string& fileName): gridInt(),
                                         visited(){
    std::ifstream file;
    file.open(fileName.c_str());
    if (file.fail()) {
            throw std::invalid_argument("file does not exist.");
    }
    for (size_t row = 0; row < GRID_SIZE; ++row){
        for (size_t col = 0; col < GRID_SIZE ; ++col) {
            int input;
            file >> input;
            gridInt[col][row] = input;
            visited[col][row] = false;
        }
    }
    file.close();
}

//Pre: x and y are integers that represents a location on the Grid
//marks a specific location as visited
void Grid::markVisited(int x, int y) {
    checkRange(x, y);
    visited[x][y] = true;
}

//Pre: location is a GridPoint that represents a location on the Grid
//marks a specific location as visited
void Grid::markVisited(GridPoint location) {
    markVisited(location.x, location.y);
}

//Pre: x and y are integers that represents a location on the Grid
//Post: return whether the location represented by x and y has been visited
//check whether a specific location has been visited
bool Grid::isVisited(int x, int y) {
    checkRange(x, y);
    return visited[x][y];
}

//Pre: location is a GridPoint that represents a location on the Grid
//Post: return whether the location represented by location has been visited
//check whether a specific location has been visited
bool Grid::isVisited(GridPoint location) {
    return isVisited(location.x, location.y);
}

//Pre: x and y are integers that represents a location on the Grid
//Post: return the integer stores in the location
//get the integer stores in the location
int Grid::getInt(int x, int y) const {
    checkRange(x, y);
    return gridInt[x][y];
}

//Pre: location is a GridPoint that represents a location on the Grid
//Post: return the integer stores in the location
//get the integer stores in the location
int Grid::getInt(GridPoint location) const {
    return getInt(location.x, location.y);
}

//Pre: location is a GridPoint that represents a Grid location
//Post: return whether the location is on the Grid
//check whether the location is inside the Grid
bool Grid::inRange(GridPoint location) {
    return (location.x>=0&&location.x< GRID_SIZE&&location.y>=0&&location.y < GRID_SIZE);
}

//Pre: x and y are integers that represents a Grid location
//throw an exception if location represented by x and y is not on the Grid
void Grid::checkRange(int x, int y) const {
    if (x < 0 || y < 0 || x >= GRID_SIZE|| y >= GRID_SIZE) {
        throw std::range_error("Index is out of range");
    }
}