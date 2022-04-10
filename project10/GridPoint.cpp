// File name: GridPoint.cpp
// Author: Chengye Hao
// userid: haoc2
// Email: chengye.hao@vanderbilt.edu
// Class: cs2201
// Assignment Number: PA10
// Honor Statement: I did not give or receive any help on this assignment from
// sources other than the instructors
// Description: This file contains definition to functions in GridPoint class
// The design of GridPoint class is based on Point class in CS2201 PA07
// Last Changed:2021/12/7


#include "GridPoint.h"

//Default constructor
GridPoint::GridPoint():x(0),
                       y(0){

}

//Pre: x and y are integers represent location of the GridPoint
//constructor of GridPoint class
GridPoint::GridPoint(int x, int y): x(x),
                                    y(y){

}

//Pre: rhs is a constant reference to a GridPoint object
//Post return whether rhs and this GridPont is the same GridPoint
//==operator of GridPoint class
bool GridPoint::operator==(const GridPoint &rhs) const {
    return (this->x==rhs.x && this->y==rhs.y);
}

//Pre: rhs is a constant reference to a GridPoint object
//Post return whether rhs and this GridPont is not the same GridPoint
// != operator of GridPoint class
bool GridPoint::operator!=(const GridPoint &rhs) const {
    return !(*this==rhs);
}