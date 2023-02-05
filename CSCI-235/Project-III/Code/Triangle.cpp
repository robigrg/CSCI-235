//  Triangle.cpp
//
//  Name: Robi Gurung
//  Professor Violent Hajdini
//  Date: 28 June 2022
//  CSCI 235 Project - III

#include "Triangle.hpp"

Triangle::Triangle(const int& side):Shape(side, side)
{
    //set edges to 3 determining shape Triangle
    setEdges(3);
    int ascii_counter = 48;
    //creating a 2D array with empty chars to create a triangle
    char **chars = new char* [getHeight()];
    for(int i=0; i<getWidth(); i++){ 
        chars[i] = new char[getWidth()];
        for(int j=0; j<getHeight(); j++){
            if(i==getWidth()-1 || j==0 || (i==j)){
                chars[i][j] = char(ascii_counter);
                if(ascii_counter>126){ //updating the ascii counter
                    ascii_counter = 48;
                }else{
                    ascii_counter++;
                }
            }else{
                chars[i][j] = ' ';
            }
        }
    }
    //set the new display
    setDisplayChars(chars);
}

// function to calculate the area of a triangle
double Triangle::getSurfaceArea(){
    double altitude = getHeight();
    double base = getWidth();
    //Area of Triangle = 1/2 * base * altitude
    double Area = 1.0/2.0 * base * altitude;
    return Area;
};

// function to calculate the volume of a triangle
double Triangle::get3DVolume(const double& depth){
    double height = depth;
    double altitude = getHeight();
    double base = getWidth();
    //Volume of Triangle = 1/2 * base * height * altitude
    double Volume = 1.0/2.0 * base * height * altitude;
    return Volume;
};

Triangle::~Triangle()
{
    //destructor
}

