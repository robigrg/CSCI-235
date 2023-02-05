//  Shape.cpp
//  Name: Robi Gurung
//  Professor Violent Hajdini
//  Date: 28 June 2022
//  CSCI 235 Project - III

#include "Shape.hpp"
#include "iostream"

Shape::Shape(const int& width, const int& height)
{
    this->width = width;
    this->height = height;
    this->chars = nullptr;
}


//Getters
int Shape::getEdges(){
    return edges;
};

int Shape::getWidth(){
    return width;
};

int Shape::getHeight(){
    return height;
};

char **Shape::getDisplayChars(){
    return chars;
};


//Setters
void Shape::setEdges(const int& edges){
    this->edges = edges;
};

void Shape::setWidth(const int& new_width){
    this->width = new_width;
};

void Shape::setHeight(const int& new_height){
    this->height = new_height;
};

void Shape::setDisplayChars(char **display){
    this->chars = display;
};


//Mutators
void Shape::rotateRight(){
    int shapeSize;
    //Checking if the width is greater than height or not.
    //If it is then assigning width to the variable shapeSize else height.
    if(getWidth()>getHeight()){
        shapeSize = getWidth();
    }else{
        shapeSize = getHeight();
    }
    
    char** temp = new char*[shapeSize];
    for(int i=0; i<shapeSize; i++){
        temp[i] = new char[shapeSize];
        for(int j=0; j<shapeSize; j++){
            temp[i][j] = ' ';
        }
    }
    
    int Rright;
    for(int i=0; i<shapeSize; i++){
        Rright = shapeSize-1;
        for(int j=0; j<shapeSize; j++){
            temp[i][j] = chars[Rright][i];
            Rright--;
        }
    }
    
    for(int i=0; i<shapeSize; i++){
        for(int j=0; j<shapeSize; j++){
            chars[i][j] = temp[i][j];
        }
    }
    //setting up for the next model
    int tempSize = width;
    width = height;
    height = tempSize;
};

void Shape::rotateLeft(){
    int shapeSize;
    //Checking if the width is greater than height or not.
    //If it is then assigning width to the variable shapeSize else height.
    if(getWidth()>getHeight()){
        shapeSize = getWidth();
    }else{
        shapeSize = getHeight();
    }
    
    char** temp = new char*[shapeSize];
    for(int i=0; i<shapeSize; i++){
        temp[i] = new char[shapeSize];
        for(int j=0; j<shapeSize; j++){
            temp[i][j] = ' ';
        }
    }
    
    int Rleft;
    Rleft = shapeSize-1;
    for(int i=0; i<shapeSize; i++){
        for(int j=0; j<shapeSize; j++){
            temp[i][j] = chars[j][Rleft];
        }
        Rleft--;
    }
    
    for(int i=0; i<shapeSize; i++){
        for(int j=0; j<shapeSize; j++){
            chars[i][j] = temp[i][j];
        }
    }
    //setting up for the next model
    int tempSize = width;
    width = height;
    height = tempSize;
};

void Shape::display(){
    int shapeSize;
    //Checking if the width is greater than height or not.
    //If it is then assigning width to the variable shapeSize else height.
    if(getWidth()>getHeight()){
        shapeSize = getWidth();
    }else{
        shapeSize = getHeight();
    }
    //2D array to print the characters with a space
    for(int i=0; i<shapeSize; i++){
        for(int j=0; j<shapeSize; j++){
            std::cout<<chars[i][j]<<" ";
        }
        std::cout<<"\n";
    }
};


Shape::~Shape()
{
    //destructor - preventing memory leak
    if (chars!=nullptr) {
        for (int i=0; i<height; i++)
            delete[] chars[i];
        delete[] chars;
        }
}

