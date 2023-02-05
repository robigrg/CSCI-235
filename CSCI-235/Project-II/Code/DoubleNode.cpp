//  DoubleNode.cpp

//  Name: Robi Gurung
//  Professor Violent Hajdini
//  Date: 20 June 2022
//  CSCI 235 Project - II

#include "DoubleNode.hpp"

// default constructor
template <class ItemType>
DoubleNode<ItemType>::DoubleNode(){
    next = nullptr;
    prev = nullptr;
}

// parameterized constructor
template <class ItemType>
DoubleNode<ItemType>::DoubleNode(ItemType value){
    item = value;
    next = nullptr;
    prev = nullptr;
}

// getItem function
template <class ItemType>
ItemType DoubleNode<ItemType>::getItem() const{
        return item;
}

// setNext function
template <class ItemType>
bool DoubleNode<ItemType>::setNext(DoubleNode* ptr){
        next = ptr;
        return true;
}

// setPrev function
template <class ItemType>
bool DoubleNode<ItemType>::setPrev(DoubleNode* ptr){
            prev = ptr;
            return true;
}

//getNext function
template <class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getNext(){
            return next;
}

// getPrev function
template <class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getPrev(){
    return prev;
}

// destructor
template <class ItemType>
DoubleNode<ItemType>::~DoubleNode(){
    //DoubleNode Destructor
}
