//  Name: Robi Gurung
//  Professor Violent Hajdini
//  Date: 14 July 2022
//  CSCI 235 Project - V

#include "LinkedList.hpp"
#include <iostream>
int main(int argc, char const *argv[])
{
    LinkedList<int> list;
    list.insert(0, 0);
    list.insert(1, 1);
    list.insert(2, 2);
    list.insert(3, 3);
    list.insert(4, 4);
    std::cout << list.getEntry(0) << "\n";
    std::cout << list.getEntry(1) << "\n";
    std::cout << list.getEntry(2) << "\n";
    std::cout << list.getEntry(3) << "\n";
    std::cout << list.getEntry(4) << "\n";

    list.invert();
    std::cout << list.getEntry(0) << "\n";
    std::cout << list.getEntry(1) << "\n";
    std::cout << list.getEntry(2) << "\n";
    std::cout << list.getEntry(3) << "\n";
    std::cout << list.getEntry(4) << "\n";

    return 0;
}
