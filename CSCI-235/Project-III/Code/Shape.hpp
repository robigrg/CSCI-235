//  Shape.hpp
//
//  Name: Robi Gurung
//  Professor Violent Hajdini
//  Date: 28 June 2022
//  CSCI 235 Project - III

#ifndef Shape_hpp
#define Shape_hpp

#include <stdio.h>

class Shape{
    public:
        //Parameterized Constructor; there is no default constructor
        Shape(const int& width, const int& height);
        
        //Getters
        int getEdges();
        int getWidth();
        int getHeight();
        char **getDisplayChars();
        
        //Setters
        void setEdges(const int& edges);
        void setWidth(const int& new_width);
        void setHeight(const int& new_height);
        void setDisplayChars(char **display);
        
        //Mutators
        void rotateRight(); //rotate by 90 degrees
        void rotateLeft(); //rotate by 90 degrees
        
        //Pure Virtual Method
        //uses the canonical formulae for surface area given each respective shape
        virtual double getSurfaceArea() = 0;
        //yields the volume of the caller shape if it was projected into 3 dimensions using the depth
        //parameter as the z-axis value.
        virtual double get3DVolume(const double& depth) = 0;
        
        // Display -  //iterate through 2D array and print chars
        void display();
        virtual ~Shape();
    protected:

    private:
        int width, height, edges;
        char** chars;
};

#endif /* Shape_hpp */
