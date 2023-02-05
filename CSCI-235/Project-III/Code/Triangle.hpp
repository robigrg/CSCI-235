//  Triangle.hpp
//
//  Name: Robi Gurung
//  Professor Violent Hajdini
//  Date: 28 June 2022
//  CSCI 235 Project - III

#ifndef Triangle_hpp
#define Triangle_hpp

#include <stdio.h>

#include "Shape.hpp"

class Triangle: public Shape
{
    public:
        /* Parameterized constructor; takes in side length as a parameter, iterates
        through the 2D array to draw the right triangle using ASCII chars */
        Triangle(const int& side);
        double getSurfaceArea();
        double get3DVolume(const double& depth);
        virtual ~Triangle();

    protected:

    private:
};

#endif /* Triangle_hpp */
