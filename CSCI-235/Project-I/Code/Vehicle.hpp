//  Vehicle.hpp
//
//  Name: Robi Gurung
//  Professor Violent Hajdini
//  Date: 09 June 2022
//  CSCI 235 Project - I

#ifndef Vehicle_hpp
#define Vehicle_hpp

#include <stdio.h>
#include <string>

class Vehicle
{
    public:
        // This default constructor should set all member variables to either "" or 0 depending on their type
        Vehicle();
        
        // Parameterized Constructor  - Sets all member variables to what was passed in the parameters
        Vehicle(std::string name, std::string manufacturer, int wheels, int gas, int passengers, int cargo);
    
        std::string getName() const;                //  Should return the name_ variable
        std::string getManufacturer() const;        //  Should return the manufacturer_ variable
        int getWheels() const;                      //  Should return the wheels_ variable
        int getGas() const;                         //  Should return the gas_ variable
        int getPassengers() const;                  //  Should return the passengers_ variable
        int getCargo() const;                       //  Should return the cargo_ variable
    
        void setName(std::string);                  //  Should set the name_ variable
        void setManufacturer(std::string);          //  Should set the manufacturer_ variable
        void setWheels(int);                        //  Should set the wheels_ variable
        void setGas(int);                           //  Should set the gas_ variable
        void setPassengers(int);                    //  Should set the passengers_ variable
        void setCargo(int);                         //  Should set the cargo_ variable
    
        virtual ~Vehicle();                         //  Vehicle Destructor

    protected:

    private:
        std::string name_;
        std::string manufacturer_;
        int wheels_;
        int gas_;
        int passengers_;
        int cargo_;
};

#endif /* Vehicle_hpp */
