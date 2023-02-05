//  DoubleNode.hpp

//  Name: Robi Gurung
//  Professor Violent Hajdini
//  Date: 20 June 2022
//  CSCI 235 Project - II

#ifndef DOUBLENODE_HPP
#define DOUBLENODE_HPP

#include <stdio.h>
#include <iostream>

template <class ItemType>
class DoubleNode{
public:
    DoubleNode();  // default constructor
    DoubleNode(ItemType value);  // parameterized constructor
    ItemType getItem() const;  // returns item
    bool setNext(DoubleNode* ptr);  // sets next pointer
    bool setPrev(DoubleNode* ptr);  //sets previous pointer
    DoubleNode<ItemType>* getNext();  // returns next pointer
    DoubleNode<ItemType>* getPrev();  //returns previous pointer
    ~DoubleNode();  // destructor
private:
        ItemType item;
        DoubleNode<ItemType>* next;
        DoubleNode<ItemType>* prev;
};

//#include "DoubleNode.cpp"
#endif /* DOUBLENODE_HPP */
