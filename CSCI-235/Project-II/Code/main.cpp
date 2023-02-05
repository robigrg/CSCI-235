//  main.cpp

//  Name: Robi Gurung
//  Professor Violent Hajdini
//  Date: 20 June 2022
//  CSCI 235 Project - II

#include "DoublyLinkedList.hpp"
#include <iostream>
using namespace std;

int main() {
    DoublyLinkedList<int>* list1 = new DoublyLinkedList<int>();
    list1->insert(50, 1);
    list1->insert(45, 2);
    list1->insert(40, 3);
    DoublyLinkedList<int>* list2 = new DoublyLinkedList<int>();
    list2->insert(100, 1);
    list2->insert(90, 2);
    list2->insert(80, 3);
    list1->display();
    list2->display();
    //list1->interleave(list2);
    list1->display();
    
    return 0;
}



