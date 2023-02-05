//  Truck.cpp
//
//  Name: Robi Gurung
//  Professor Violent Hajdini
//  Date: 09 June 2022
//  CSCI 235 Project - I

#include "Truck.hpp"

Truck::Truck():Vehicle("", "", 16, 125, 3, 80000)
{
    // Truck Construcor
    // The Truck class represents an Vehicle object with the following specifications:
    // It has 16 wheels, can hold 3 passengers, can hold 125 gallons of gas, & can carry 80000 pounds
    
    hasTrailer_ = false;   // setting the boolean variable hasTrailer_ to be false
}

Truck::Truck(std::string name, std::string manufacturer):Vehicle(name, manufacturer, 16, 125, 3, 80000)
{
    // Parameterized Constructor
    hasTrailer_ = false;
}

void Truck::toggleTrailer()
{
    // Function that checks if the hasTrailer_ variable is true or false and implements its respective statements
    if(hasTrailer_){
        setWheels(16);
        setCargo(80000);
        hasTrailer_ = false;
    }else{
        setWheels(26);
        setCargo(16000);
        hasTrailer_ = true;
    }
}

bool Truck::getTrailer()
{
    return hasTrailer_;   // getter function that returns the boolean value of the variable hasTrailer_
}

Truck::~Truck()
{
    // Truck Destructor
}
