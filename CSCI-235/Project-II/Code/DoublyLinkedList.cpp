//  DoublyLinkedList.cpp

//  Name: Robi Gurung
//  Professor Violent Hajdini
//  Date: 20 June 2022
//  CSCI 235 Project - II

#include "DoublyLinkedList.hpp"

// default constructor
template <class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(){
        headPtr = nullptr;
        lastPtr = nullptr;
        nodeSize = 0;
}

// copy constructor
/*
 
 
*/

// insert function
template <class ItemType>
bool DoublyLinkedList<ItemType>::insert(const ItemType &item, const int &position){
    if(position>=1 && headPtr!=nullptr){
        DoubleNode<ItemType>* temp = headPtr;
        DoubleNode<ItemType>* pos = getAtPos(position);
        if(pos == nullptr){
            while(temp->getNext()!=nullptr){
                temp = temp->getNext();
            }
            DoubleNode<ItemType>* last = new DoubleNode<ItemType>(item);
            last->setPrev(temp);
            temp->setNext(last);
            lastPtr = last;
            
        }else{
            DoubleNode<ItemType>* middle = new DoubleNode<ItemType>(item);
            DoubleNode<ItemType>* right = pos->getNext();
            right->setPrev(middle);
            middle->setNext(right);
            middle->setPrev(pos);
            pos->setNext(middle);
        }
    }
    else{
        headPtr = new DoubleNode<ItemType>(item);
        lastPtr = headPtr;
    }
    nodeSize++;
    return true;
}

// remove function
template <class ItemType>
bool DoublyLinkedList<ItemType>::remove(const int position){
    if(position>1 && position<=nodeSize){
        if(nodeSize == 1 || position == 1){
            if(nodeSize==1){
                headPtr = nullptr;
                lastPtr = nullptr;
            }else{
                headPtr = headPtr->getNext();
            }
        }
        else if(position == nodeSize){
            lastPtr = lastPtr->getPrev();
            lastPtr->setNext(nullptr);
        }
        else{
            DoubleNode<ItemType>* current = headPtr;
            for(int i=2; i<=nodeSize; i++){
                if(position == i){
                    DoubleNode<ItemType>* left = current->getPrev();
                    DoubleNode<ItemType>* right = current->getNext();
                    left->setNext(right);
                    right->setPrev(left);
                    nodeSize--;
                    return true;
                }
                current = current->getNext();
            }
        }
        nodeSize--;
    }
    else{
        return false;
    }
}

// returns head pointer
template <class ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getHeadPtr()const{
    return headPtr;
}
    
// returns last pointer
template <class ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getLastPtr()const{
    return lastPtr;
}

// getAtPos function
template <class ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getAtPos(const int &pos) const{
    if(headPtr!=nullptr){
        DoubleNode<ItemType>* temp = headPtr;
        for(int i=1; i<nodeSize; i++){
            if(i==pos){
                return temp;
            }
            temp = temp->getNext();
        }
    }
    return nullptr;
}

// isEmpty function
template <class ItemType>
bool DoublyLinkedList<ItemType>::isEmpty(){
    if(headPtr==nullptr){
        return true;
    }
    else{
        return false;
    }
}

// clear function
template <class ItemType>
void DoublyLinkedList<ItemType>::clear(){
    headPtr = nullptr;
    nodeSize = 0;
}

// display function
template <class ItemType>
void DoublyLinkedList<ItemType>::display(){
    if(headPtr!=nullptr){
        DoubleNode<ItemType>* temp = headPtr;
        while(temp->getNext()!=nullptr){
            std::cout<<temp->getItem();
            temp = temp->getNext();
        }
        std::cout<<temp->getItem();
    }
    else{
        std::cout<<"Empty\n";
    }
}

// displayBackwards function
template <class ItemType>
void DoublyLinkedList<ItemType>::displayBackwards()const{
    if(headPtr!=nullptr){
        DoubleNode<ItemType>* temp = lastPtr;
        while(temp->getPrev()!=nullptr){
            std::cout<<"Value: "<<temp->getItem()<<"\n";
            temp = temp->getPrev();
            
        }
        std::cout<<"Value: "<<temp->getItem()<<"\n-------------\n";
    }
    else{
        std::cout<<"Empty\n";
        
    }
}

// interleave function
template <class ItemType>
DoublyLinkedList<ItemType> DoublyLinkedList<ItemType>::interleave(DoublyLinkedList<ItemType> &a_list){
    if(!a_list->isEmpty()){
        headPtr = a_list->getHeadPtr();
        lastPtr = a_list->getLastPtr();
    }
    else if(!a_list->isEmpty()){
        if(nodeSize<=a_list->nodeSize){
            DoubleNode<ItemType>* left = headPtr;
            DoubleNode<ItemType>* right = nullptr;
            DoubleNode<ItemType>* middle = a_list->getHeadPtr();
            DoubleNode<ItemType>* swap_middle = middle->getNext();
            if(nodeSize > 1){
                right = headPtr->getNext();
                while(right!=nullptr){
                    left->setNext(middle);
                    middle->setPrev(left);
                    middle->setNext(right);
                    right->setPrev(middle);
                    left = right;
                    middle = swap_middle;
                    right = right->getNext();
                    swap_middle = swap_middle->getNext();
                }
                left->setNext(swap_middle);
                swap_middle->setPrev(left);
                
            }
            else{
                headPtr->setNext(a_list->getHeadPtr());
                lastPtr = a_list->getLastPtr();
            }
            
        }
        else{
            DoubleNode<ItemType>* left = headPtr;
            DoubleNode<ItemType>* right = headPtr->getNext();
            DoubleNode<ItemType>* middle = a_list->getHeadPtr();
            if(a_list->getSize()>1){
                DoubleNode<ItemType>* swap_middle = middle->getNext();
                while(swap_middle!=nullptr){
                    left->setNext(middle);
                    middle->setPrev(left);
                    middle->setNext(right);
                    right->setPrev(middle);
                    left = right;
                    middle = swap_middle;
                    right = right->getNext();
                    swap_middle = swap_middle->getNext();
                }
            }
            else{
                left->setNext(middle);
                middle->setPrev(left);
                middle->setNext(right);
                right->setPrev(middle);
            }
        }
    }
}

// getSize function
template <class ItemType>
int DoublyLinkedList<ItemType>::getSize(){
    return nodeSize;
}

// destructor
template <class ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList(){
    //DoublyLinkedList Destructor
};

