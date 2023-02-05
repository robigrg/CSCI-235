//  Rectangle.hpp
//
//  Name: Robi Gurung
//  Professor Violent Hajdini
//  Date: 28 June 2022
//  CSCI 235 Project - III

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <stdio.h>

#include "Shape.hpp"

class Rectangle: public Shape
{
    public:
        /* Parameterized constructor; takes in width and height, iterates through the 2D
        array to populate it with the necessary characters given the parameter dimensions */
        Rectangle(const int& width, const int& height);
        double getSurfaceArea();
        double get3DVolume(const double& depth);
        virtual ~Rectangle();

    protected:

    private:
};

#endif /* Rectangle_hpp */
