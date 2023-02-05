//  Name: Robi Gurung
//  Professor Violent Hajdini
//  Date: 14 July 2022
//  CSCI 235 Project - V

//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//
//  modified position s.t. 0 <= position < item_count_
//  some style modification, mainly variable names
//  added getHeadPtr()

/** ADT list: Singly linked list implementation.

 Implementation file for the class LinkedList.
 @file LinkedList.cpp */

#include "LinkedList.hpp" // Header file
#include <iostream>
#include <cassert>

// constructor
template <class T>
LinkedList<T>::LinkedList() : head_ptr_(nullptr), item_count_(0)
{
} // end default constructor

// copy constructor
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &a_list) : item_count_(a_list.item_count_)
{
   Node<T> *orig_chain_pointer = a_list.head_ptr_; // Points to nodes in original chain

   if (orig_chain_pointer == nullptr)
      head_ptr_ = nullptr; // Original list is empty
   else
   {
      // Copy first node
      head_ptr_ = new Node<T>();
      head_ptr_->setItem(orig_chain_pointer->getItem());

      // Copy remaining nodes
      Node<T> *new_chain_ptr = head_ptr_;                 // Points to last node in new chain
      orig_chain_pointer = orig_chain_pointer->getNext(); // Advance original-chain pointer
      while (orig_chain_pointer != nullptr)
      {
         // Get next item from original chain
         T next_item = orig_chain_pointer->getItem();

         // Create a new node containing the next item
         Node<T> *new_node_ptr = new Node<T>(next_item);

         // Link new node to end of new chain
         new_chain_ptr->setNext(new_node_ptr);

         // Advance pointer to new last node
         new_chain_ptr = new_chain_ptr->getNext();

         // Advance original-chain pointer
         orig_chain_pointer = orig_chain_pointer->getNext();
      } // end while

      new_chain_ptr->setNext(nullptr); // Flag end of chain
   }                                   // end if
} // end copy constructor

// destructor
template <class T>
LinkedList<T>::~LinkedList()
{
   clear();
} // end destructor

/**@return true if list is empty - item_count_ == 0 **/
template <class T>
bool LinkedList<T>::isEmpty() const
{
   return item_count_ == 0;
} // end isEmpty

/**@return the number of items in the list - item_count_ **/
template <class T>
int LinkedList<T>::getLength() const
{
   return item_count_;
} // end getLength

/**
 @pre list positions follow traditional indexing from 0 to item_count_ -1
 @param positions indicating point of insertion
 @param new_entry to be inserted in list
 @post new_entry is added at position in list (the node previously at that position is now at position+1)
 @return true if valid position (0 <= position <= item_count_) **/
template <class T>
bool LinkedList<T>::insert(int positions, const T &new_entry)
{
   bool able_to_insert = (positions >= 0) && (positions <= item_count_);
   if (able_to_insert)
   {
      // Create a new node containing the new entry
      Node<T> *new_node_ptr = new Node<T>(new_entry);

      // Attach new node to chain
      if (positions == 0)
      {
         // Insert new node at beginning of chain
         new_node_ptr->setNext(head_ptr_);
         head_ptr_ = new_node_ptr;
      }
      else
      {
         // Find node that will be before new node
         Node<T> *prev_ptr = getNodeAt(positions - 1);

         // Insert new node after node to which prev_ptr points
         new_node_ptr->setNext(prev_ptr->getNext());
         prev_ptr->setNext(new_node_ptr);
      } // end if

      item_count_++; // Increase count of entries
   }                 // end if

   return able_to_insert;
} // end insert

/**
 @pre list positions follow traditional indexing from 0 to item_count_ -1
 @param position indicating point of deletion
 @post node at position is deleted, if any. List order is retains
 @return true if there is a node at position to be deleted, false otherwise */
template <class T>
bool LinkedList<T>::remove(int position)
{
   bool able_to_remove = (position >= 0) && (position < item_count_);
   if (able_to_remove)
   {
      Node<T> *cur_ptr = nullptr;
      if (position == 0)
      {
         // Remove the first node in the chain
         cur_ptr = head_ptr_; // Save pointer to node
         head_ptr_ = head_ptr_->getNext();
      }
      else
      {
         // Find node that is before the one to delete
         Node<T> *prev_ptr = getNodeAt(position - 1);

         // Point to node to delete
         cur_ptr = prev_ptr->getNext();

         // Disconnect indicated node from chain by connecting the
         // prior node with the one after
         prev_ptr->setNext(cur_ptr->getNext());
      } // end if

      // Return node to system
      cur_ptr->setNext(nullptr);
      delete cur_ptr;
      cur_ptr = nullptr;

      item_count_--; // Decrease count of entries
   }                 // end if

   return able_to_remove;
} // end remove

/**@post the list is empty and item_count_ == 0*/
template <class T>
void LinkedList<T>::clear()
{
   while (!isEmpty())
      remove(0);
} // end clear

template <class T>
Node<T> *LinkedList<T>::getHeadPtr() const
{
   return head_ptr_;
}

/**
 @pre list positions follow traditional indexing from 0 to item_count_ -1
 @param position indicating the position of the data to be retrieved
 @return data item found at position. If position is not a valid position < item_count_
 throws  PrecondViolatedExcep */
template <class T>
T LinkedList<T>::getEntry(int position) const
{
   // Enforce precondition
   bool ableToGet = (position >= 0) && (position < item_count_);
   if (ableToGet)
   {
      Node<T> *nodePtr = getNodeAt(position);
      return nodePtr->getItem();
   }
   else
   {
      std::string message = "getEntry() called with an empty list or ";
      message = message + "invalid position.";
      throw(PrecondViolatedExcep(message));
   } // end if
} // end getEntry

/**
    @pre k >= 0
    @post the contents of the list are rotated to the right by k places,
        so that every element at position i shifts to position i+k % item_count_
*/
template <class T>
void LinkedList<T>::rotate(int k)
{
    //initializing position with the value of item_count_
   int position = item_count_;
   //checking if the k input is less than or equal to 0
   //if it is then we simply return 
   if(k <= 0){
    return;
   }
   //condition if k is greater than 0, non-negative number, then we rotate the list
   else if(k > 0){
    //create a pointer current and point it to the position-1 node
    //moving the last node to the front
    Node<T> *current = getNodeAt(position-1);
    //Node<T> *current = head_ptr_;
    Node<T> *second = getNodeAt(position-2);
    //Node<T> *second = head_ptr_->getNext();
    while(current->getNext()!=nullptr){
            current = current->getNext();
    } 
    //setting the next node to the first
    current->setNext(head_ptr_); 
    //curret->getNext();
    //reassigning the last node to be nullptr
    second->setNext(nullptr); 
    //assigning the head_ptr_ after rotating
    head_ptr_ = current; 

    //calling recursive function rotate with decrement of k size by 1 
    //to rotate all the items in the list
    rotate(k-1); 
   } 
   //List: 1 2 3 4 
   //rotate(0): 1 2 3 4 
   //rotate(1): 4 1 2 3 
   //rotate(2): 3 4 1 2 
   //rotate(3): 2 3 4 1 
   //rotate(4): 1 2 3 4 
   //rotate(5): 4 1 2 3
};


/**
    A wrapper to a recursive method that inverts the contents of the list

    @post the contents of the list are inverted such that:
        the item previously at position 1 is at position item_count_,
        the item previously at position 2 is at position item_count_-1 ...
        the item previously at position ⌊item_count/2⌋ is at position
            ⌈item_count_/2⌉
*/
template<class T>
void LinkedList<T>::invert()
{
    //if the head_ptr_ is not equal to nullptr
    //then we call the recursion function inverRest()
    //to invert the items in the list
    if(head_ptr_!=nullptr){
        invertRest(head_ptr_);
    }
};

/**
    private function to invert, used for safe programming to avoid
    exposing pointers to list in public methods

    @post the contents of the list are inverted such that:
        the item previously at position 1 is at position item_count_,
        the item previously at position 2 is at position item_count_-1 ...
        the item previously at position ⌊item_count/2⌋ is at position
            ⌈item_count_/2⌉
*/
template<class T>
void LinkedList<T>::invertRest(Node<T>* current_first_ptr){
    //creating a base case where if the list is empty then we simply return
    if(current_first_ptr == nullptr){ 
        return;
    }
    //creating a pointer current to point the next item of current_first_ptr
    Node<T> *current = current_first_ptr->getNext();
    //if condition that checks if the pointer is pointing to nullptr or not
    if(current != nullptr){
        //creating another pointer and assigning it with current_first_ptr
        Node<T> *second = current_first_ptr;
        //recursion function to go through the list
        invertRest(current);
        //setting second pointer to the next of the current pointer creating a reverse list
        current->setNext(second);
        //setting the second pointer to nullptr to unlink from the chain
        second->setNext(nullptr);
    }else{
        //if the current_first_ptr points to nullptr then 
        //setting the head_ptr_ to current_first_ptr
        //since the last node is inverted to front 
        head_ptr_ = current_first_ptr;
        return;
    }
    //List 1:
    //1 9 2 8 3 7 4 6 5 
    //5 6 4 7 3 8 2 9 1 
    //List 2:
    //0 5 10 15 20 25 30 35 45
    //45 35 30 25 20 15 10 5 0
}

/************* PRIVATE METHODS ************/

// Locates a specified node in this linked list.
// @pre list positions follow traditional indexing from 0 to item_count_ -1
// @param position the index of the desired node
//       0 <= position < item_count_
// @return  A pointer to the node at the given position or nullptr if position is >= item_count_
template <class T>
Node<T> *LinkedList<T>::getNodeAt(int position) const
{
   // Count from the beginning of the chain
   Node<T> *cur_ptr = head_ptr_;
   for (int skip = 0; skip < position; skip++)
      cur_ptr = cur_ptr->getNext();

   return cur_ptr;
} // end getNodeAt

//  End of implementation file.
