//  Circle.cpp
//
//  Name: Robi Gurung
//  Professor Violent Hajdini
//  Date: 28 June 2022
//  CSCI 235 Project - III

#include "Circle.hpp"

Circle::Circle(const int& diameter): Shape(diameter, diameter)
{
    //set edges to 0 determining shape Circle
    setEdges(0);
    //Populate 2D array with empty chars
    char **arr = new char *[getHeight()];
    for (int row = 0; row < getHeight(); row++){
        arr[row] = new char[getWidth()];
        for (int col = 0; col < getWidth(); col++){
            arr[row][col] = ' ';
        }
    }
    //Populate the proper positions with *'s
    int x_radius = diameter / 2;
    int y_radius = (diameter / 2) - 1;
    float dist = 0;
    char ascii_counter = 48;
    for (int col = 0; col <= getWidth() + 1; col++){
        for (int row = 0; row <= getHeight() + 5; row++){
            dist = sqrt((row - y_radius) * (row - y_radius) + (col - x_radius) * (col - x_radius));
            //dist in range: (radius - 0.5) to (radius + 0.5)
            if (dist > y_radius - 0.5 && dist < y_radius + 0.5){
                    arr[row][col] = ascii_counter;
                //fix ascii_counter to wrap around after
                ascii_counter++;
                if (ascii_counter > 126){ //updating the ascii counter
                    ascii_counter = 48;
                }
            }
        }
    }
    //set the new display
    setDisplayChars(arr);
}

// function to calculate the area of a circle
double Circle::getSurfaceArea(){
    double radius1 = getWidth()/2.0;
    double radius2 = getHeight()/2.0;
    //Area of a Circle = π * r * r
    //double Area =  (22.0/7.0) * radius1 * radius2;
    double Area =  M_PI * radius1 * radius2;
    return Area;
};

// function to calculate the volume of a circle
double Circle::get3DVolume(const double& depth){
    double radius1 = getWidth()/2.0;
    double radius2 = getHeight()/2.0;
    double radius3 = depth/2.0;
    //Volume of a Circle = 4/3 * π * r * r * r
    //double Volume = (4.0/3.0) * (22.0/7.0) * radius1 * radius2 * radius3;
    double Volume = (4.0/3.0) * M_PI * radius1 * radius2 * radius3;
    return Volume;
};

Circle::~Circle()
{
    //destructor
}

