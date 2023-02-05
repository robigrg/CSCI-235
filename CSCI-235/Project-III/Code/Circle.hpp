//  Circle.hpp
//
//  Name: Robi Gurung
//  Professor Violent Hajdini
//  Date: 28 June 2022
//  CSCI 235 Project - III

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.hpp"
#include <stdio.h>
#include <math.h>

class Circle: public Shape
{
    public:
        //Parameterized contructor, takes the diameter as either width or height.
        Circle(const int& diameter);
        double getSurfaceArea();
        double get3DVolume(const double& depth);
        virtual ~Circle();

    protected:

    private:
};

#endif /* Circle_hpp */
