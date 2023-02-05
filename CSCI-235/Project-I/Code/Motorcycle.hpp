//  Motorcycle.hpp
//
//  Name: Robi Gurung
//  Professor Violent Hajdini
//  Date: 09 June 2022
//  CSCI 235 Project - I

#ifndef Motorcycle_hpp
#define Motorcycle_hpp

#include "Vehicle.hpp"
#include <stdio.h>

class Motorcycle: public Vehicle
{
    public:
        // Default constructor - name and manufacturer of this vehicle should be "" since no value was passed
        Motorcycle();
        
        // Parameterized constructor
        Motorcycle(std::string name, std::string manufacturer);
    
        // Function that if sideMotorcycle_ is false, change wheels amount from 2 to 4 and passenger amount from 2 to 3 and set
        // 2 to 3 and set sideMotorcycle_ to true if sideMotorcycle_ is true, change wheels amount from 4 to 2 and passenger
        // amount from 3 to 2 and set sideMotorcycle_ to false
        void toggleSideMotorcycle();
    
        // Function that returns the current state of sideMotorcycle_
        bool getSideMotorcycle();
    
        virtual ~Motorcycle();      // Motrcycle Destructor 

    protected:

    private:
        bool sideMotorcycle_;
};


#endif /* Motorcycle_hpp */
