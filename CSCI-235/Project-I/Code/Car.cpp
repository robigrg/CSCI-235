//  Car.cpp
//
//  Name: Robi Gurung
//  Professor Violent Hajdini
//  Date: 09 June 2022
//  CSCI 235 Project - I

#include "Car.hpp"

Car::Car():Vehicle("", "", 4, 12, 5, 850)
{
    // Car Constructor
    // The Car class represents an Vehicle object with the following specifications:
    // It has 4 wheels, can hold 5 passengers, can hold 12 gallons of gas & can carry 850 pounds
}

Car::Car(std::string name, std::string manufacturer):Vehicle(name, manufacturer, 4, 12, 5, 850)
{
    // Parameterized Constructor  
}

void Car::addBumperStickers(std::string sticker)
{
    // Function that inserts the sticker into the list_of_bumper_stickers_ vector
    list_of_bumper_stickers_.push_back(sticker);
}

void Car::getBumperStickers()
{
    // Function that performs for loop to print all the list of bumper stickers
    for(int i=0; i<list_of_bumper_stickers_.size(); i++){
        std::cout<<list_of_bumper_stickers_.at(i)<<"\n";
    }
}

Car::~Car()
{
    // Car Destructor
}
