#include "Motorcycle.hpp"
#include "Truck.hpp"
#include "Vehicle.hpp"
#include "Car.hpp"

#include <iostream>
#include <string>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Maa!\n";
    std::cout<< "---Hajur ko Future Car ko information----"<<std::endl;
    std::string input = "";
    Vehicle Maa;
    std::cout<<"Enter your favorite Car name:\n";
    std::cin>>input;
    Maa.setName(input);
    std::cout<<"Your Favorite car name is: "<<Maa.getName()<<std::endl;
    
    Motorcycle Dhoom;
    Dhoom.toggleSideMotorcycle();
    std::cout<<Dhoom.getSideMotorcycle();
    Dhoom.toggleSideMotorcycle();
    Dhoom.toggleSideMotorcycle();
    std::cout<<Dhoom.getSideMotorcycle();
    Dhoom.toggleSideMotorcycle();
    std::cout<<Dhoom.getSideMotorcycle();
    Dhoom.toggleSideMotorcycle();
    std::cout<<Dhoom.getSideMotorcycle();
    Dhoom.toggleSideMotorcycle();
    std::cout<<Dhoom.getSideMotorcycle();
    Dhoom.toggleSideMotorcycle();
    std::cout<<Dhoom.getSideMotorcycle()<<std::endl;
    Dhoom.toggleSideMotorcycle();
    std::cout<<Dhoom.getSideMotorcycle()<<std::endl;

    
    Car man;
    man.addBumperStickers("New York");
    man.addBumperStickers("Kathmandu");
    man.getBumperStickers();
    
    std::cout<<Maa.getWheels()<<std::endl;
    
    Truck t;
    std::cout<<t.getWheels()<<"\n";
    t.toggleTrailer();
    std::cout<<t.getWheels()<<"\n";

    return 0;
}

