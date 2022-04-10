// File name: GridPoint.h
// Author: Chengye Hao
// userid: haoc2
// Email: chengye.hao@vanderbilt.edu
// Class: cs2201
// Assignment Number: PA10
// Honor Statement: I did not give or receive any help on this assignment from
// sources other than the instructors
// Description: This file contains declaration of functions in GridPoint class, that represents
// a single point on a Grid
// The design of GridPoint class is based on Point class in CS2201 PA07
// Last Changed:2021/12/7

#ifndef PROJECT10_GRIDPOINT_H
#define PROJECT10_GRIDPOINT_H


class GridPoint {
public:
    int x;
    int y;

    //Default constructor
    GridPoint();

    //Pre: x and y are integers represent location of the GridPoint
    //Constructor
    GridPoint(int x, int y);

    //Pre: rhs is a constant reference to a GridPoint object
    //Post return whether rhs and this GridPont is the same GridPoint
    //==operator of GridPoint class
    bool operator == (const GridPoint& rhs) const;

    //Pre: rhs is a constant reference to a GridPoint object
    //Post return whether rhs and this GridPont is not the same GridPoint
    // != operator of GridPoint class
    bool operator != (const GridPoint& rhs) const;
};


#endif //PROJECT10_GRIDPOINT_H
