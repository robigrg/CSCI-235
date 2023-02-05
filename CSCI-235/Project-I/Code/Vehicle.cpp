//  Vehicle.cpp
//
//  Name: Robi Gurung
//  Professor Violent Hajdini
//  Date: 09 June 2022
//  CSCI 235 Project - I

#include "Vehicle.hpp"
#include <string>

Vehicle::Vehicle(){
    // Vehicle Constructor
    // Setting all the variables to their default value -
    name_ = "";
    manufacturer_ = "";
    wheels_ = 0;
    gas_ = 0;
    passengers_ = 0;
    cargo_ = 0;
}

Vehicle::Vehicle(std::string name, std::string manufacturer, int wheels, int gas, int passengers, int cargo)
{
    // Parameterized Constructor
    name_ = name;
    manufacturer_ = manufacturer;
    wheels_ = wheels;
    gas_ = gas;
    passengers_ = passengers;
    cargo_ = cargo;
}

std::string Vehicle::getName() const
{
    return name_;   // Getter function that returns the name of the vehicle
}

std::string Vehicle::getManufacturer() const
{
    return manufacturer_;   // Getter function that returns the manufacturer of the vehicle
}

int Vehicle::getWheels() const
{
    return wheels_;   // Getter function that returns the number of wheels of a vehicle
}

int Vehicle::getGas() const
{
    return gas_;   // Getter function that returns the amount of gas that a vehicle intakes
}

int Vehicle::getPassengers() const
{
    return passengers_;   // Getter function that returns the number of passenger the vehicle carries
}

int Vehicle::getCargo() const
{
    return cargo_;   // Getter function that returns the amount of load that the vehicle can carry
}

void Vehicle::setName(std::string name)
{
    name_ = name;   // Setter function that sets the name of the vehicle to the variable name_
}

void Vehicle::setManufacturer(std::string manufacturer)
{
    manufacturer_ = manufacturer;   // Setter function that sets the name of the manufacturer to the variable manufacturer_
}

void Vehicle::setWheels(int wheels)
{
    wheels_ = wheels;   // Setter function that sets the number of wheels to the variable wheels_
}

void Vehicle::setGas(int gas)
{
    gas_ = gas;   // Setter function that sets the gas amount to the variable gas_
}

void Vehicle::setPassengers(int passengers)
{
    passengers_ = passengers;   // Setter function that sets the number of passenger to the variable passengers_
}

void Vehicle::setCargo(int cargo)
{
    cargo_ = cargo;   // Setter function that sets the amount of load that the vehicle can carry to the variable cargo_
}

Vehicle::~Vehicle()
{
    // Vehicle Destructor
}
