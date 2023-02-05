//  Car.hpp
//
//  Name: Robi Gurung
//  Professor Violent Hajdini
//  Date: 09 June 2022
//  CSCI 235 Project - I

#ifndef Car_hpp
#define Car_hpp

#include <iostream>
#include <vector>
#include <string>
#include "Vehicle.hpp"

class Car: public Vehicle
{
    public:
        // Default constructor - name and manufacturer of this vehicle should be "" since no value was passed
        Car();
    
        // Parameterized constructor
        Car(std::string name, std::string manufacturer);
    
        // Function that adds a string to list_of_bumper_stickers_
        void getBumperStickers();
    
        // Function that prints out each sticker on its own line from list_of_bumper_stickers_ 
        void addBumperStickers(std::string);
        
        virtual ~Car();     // Car Destructor

    protected:

    private:
        std::vector<std::string> list_of_bumper_stickers_;
};

#endif /* Car_hpp */
