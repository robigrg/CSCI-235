//  Truck.hpp
//
//  Name: Robi Gurung
//  Professor Violent Hajdini
//  Date: 09 June 2022
//  CSCI 235 Project - I

#ifndef Truck_hpp
#define Truck_hpp

#include "Vehicle.hpp"
#include <stdio.h>

class Truck: public Vehicle
{
    public:
        // Default constructor - name and manufacturer of this vehicle should be "" since no value was passed
        Truck();
    
        // Parameterized constructor
        Truck(std::string name, std::string manufacturer);
    
        // Function that if hasTrailer_ is false, change wheels amount from 16 to 26 and cargo amount from 80000 to 16000 and
        // set hasTrailer_ to true if hasTrailer_ is true, change wheels amount from 26 to 16 and cargo amount from 16000 to
        // 80000 and set hasTrailer_ to false
        void toggleTrailer();
    
        // Function that returns the current state of hasTrailer_
        bool getTrailer();
    
        virtual ~Truck();   // Truck Destructor

    protected:

    private:
        bool hasTrailer_;
};

#endif /* Truck_hpp */
