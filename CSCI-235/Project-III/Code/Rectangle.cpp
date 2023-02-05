//  Rectangle.cpp
//
//  Name: Robi Gurung
//  Professor Violent Hajdini
//  Date: 28 June 2022
//  CSCI 235 Project - III

#include "Rectangle.hpp"

Rectangle::Rectangle(const int& width, const int& height):Shape(width, height)
{
    //set edges to 4 determining shape Rectangle
    setEdges(4);
    int ascii_counter = 48;
    int rectSize;
    //Checking if the width is greater than height or not.
    //If it is then assigning width to the variable rectSize else height.
    if(getWidth()>getHeight()){
        rectSize = getWidth();
    }else{
        rectSize = getHeight();
    }
    //creating a 2D array with empty chars to create a rectangle
    char **chars = new char *[rectSize];
    for(int i=0; i<rectSize; i++){
        chars[i] = new char[rectSize];
        for(int j=0; j<rectSize; j++){
            if(i==0 || i==width-1 || j==0 || j==height-1){
                if(i<width && j<height){
                    chars[i][j] = char(ascii_counter);
                }else{
                    chars[i][j] = ' ';
                }
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


// function to calculate the area of a rectangle
double Rectangle::getSurfaceArea(){
    double length = getHeight();
    double width = getWidth();
    //Area of Rectangle = length * width
    double Area = length * width;
    return Area;
};

// function to calculate the volume of a rectangle
double Rectangle::get3DVolume(const double& depth){
    double height = depth;
    double length = getHeight();
    double width = getWidth();
    //Area of Rectangle = length * width
    double Area = length * width;
    //Volume of Rectangle = Area * height
    double Volume = Area * height;
    return Volume;
};

Rectangle::~Rectangle()
{
    //destructor
}
