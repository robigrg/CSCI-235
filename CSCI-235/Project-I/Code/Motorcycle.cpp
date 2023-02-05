//  Motorcycle.cpp
//
//  Name: Robi Gurung
//  Professor Violent Hajdini
//  Date: 09 June 2022
//  CSCI 235 Project - I

#include "Motorcycle.hpp"

Motorcycle::Motorcycle():Vehicle("", "", 2, 1, 2, 0)
{
    // Motorcycle Constructor
    // The Motorcycle class represents an Vehicle object with the following specifications:
    // It has 2 wheels, can hold 2 passengers, can hold 1 gallons of gas, & can carry 0 pounds
    
    sideMotorcycle_ = false;   // setting the boolean variable sideMotorcycle_ to be false
}

Motorcycle::Motorcycle(std::string name, std::string manufacturer):Vehicle(name, manufacturer, 2, 1, 2, 0)
{
    // Parameterized Motorcycle Constructor
    sideMotorcycle_ = false;
}

void Motorcycle::toggleSideMotorcycle()
{
    // Function that checks if sideMotorcycle_ variable is true or false and implements its respective statements
    if(sideMotorcycle_){
        setWheels(2);
        setPassengers(2);
        sideMotorcycle_ = false;
    }else{
        setWheels(4);
        setPassengers(3);
        sideMotorcycle_ = true;
    }
}

bool Motorcycle::getSideMotorcycle()
{
    return sideMotorcycle_;   // getter function that returns the boolean variable of sideMotorcyle_
}

Motorcycle::~Motorcycle()
{
    // Motorcycle Destructor
}
