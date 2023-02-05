//  DoublyLinkedList.hpp

//  Name: Robi Gurung
//  Professor Violent Hajdini
//  Date: 20 June 2022
//  CSCI 235 Project - II

#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include "DoubleNode.hpp"
#include <iostream>
#include <stdio.h>

template <class ItemType>
class DoublyLinkedList{
public:
    DoublyLinkedList();  // default constructor
    DoublyLinkedList(const DoublyLinkedList<ItemType> &a_list); // copy constructor
    bool insert(const ItemType &item, const int &position);  // inserts item at position in caller list
    bool remove(const int position);  // removes the node at position
    DoubleNode<ItemType>* getHeadPtr() const;  // returns a copy of the headPtr
    DoubleNode<ItemType>* getLastPtr() const;  // returns a copy of the lastPtr
    DoubleNode<ItemType>* getAtPos(const int &pos) const;  // returns a pointer to the node located at pos
    bool isEmpty();  // returns whether the calling list empty
    void clear();  // clears the list
    void display();  // prints the contents of the calling list in order
    void displayBackwards() const;  // prints the contents of the calling list in reverse order
    DoublyLinkedList<ItemType> interleave(DoublyLinkedList<ItemType> &a_list);  // returns the interleaved list of the calling and parameter list
    int getSize();  // returns the number of nodes in the calling list
    ~DoublyLinkedList();  // destructor
private:
        DoubleNode<ItemType>* headPtr;
        DoubleNode<ItemType>* lastPtr;
        int nodeSize;
};

//#include "DoublyLinkedList.cpp"
#endif /* DOUBLYLINKEDLIST_HPP */
