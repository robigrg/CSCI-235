//  main.cpp
//
//  Name: Robi Gurung
//  Professor Violent Hajdini
//  Date: 28 June 2022
//  CSCI 235 Project - III

#include <iostream>
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    Circle cir(8);
    cir.display();
    cir.rotateLeft();
    cir.display();
    cir.rotateLeft();
    cir.display();
        
    
    Rectangle rec(10,10);
    rec.display();
    rec.rotateLeft();
    rec.display();
    
    
    Rectangle rect(6, 12);
    rect.display();
    rect.rotateRight();
    rect.display();
    rect.rotateRight();
    rect.display();
    rect.rotateRight();
    rect.display();
    Rectangle rex(6,6);
    rex.display();
    rex.rotateRight();
    rex.display();
    rex.rotateRight();
    rex.display();
    rex.rotateRight();
    rex.display();
   

    
    Triangle tri(7);
    tri.display();
    tri.rotateLeft();
    tri.display();
    
    std::cout<<"Surface area of a circle with a diameter of 8: "<<cir.getSurfaceArea()<<std::endl;
    std::cout<<"Surface area of a Triangle with a side length of 7: "<<tri.getSurfaceArea()<<std::endl;
    std::cout<<"Surface area of a Rectangle that is 6 by 12: "<<rect.getSurfaceArea()<<std::endl;

    std::cout << "Hello, World!\n";
    
    return 0;
}
