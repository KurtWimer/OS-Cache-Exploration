//Created by Kurt Wimer 2018
//simple singly-linked list

#ifndef __LIST_H
#define __LIST_H

#include <cstdlib> //for size_t

class node{
    public:
    size_t count;
    size_t val;
    size_t get_val(){return val;};
    node * next;
    node(size_t newval,size_t frequency  = 1){ val = newval; count = frequency;next = nullptr;};
};

class list{
    private:
    node* head;
    node* tail;
    size_t size;
    public:
    //empties list
    void clear(){
            while(head != nullptr){delete popfront();}
            size = 0;}
    //removes first element, caller is responsible for maintaining of freeing the node
    node * popfront();
    //returns size
    size_t get_size(){return size;};
    //add new alement to back
    void pushback(node *);
    //Removes a node from the list and return it, caller is responsible for maintaining of freeing the node
    node * pop(size_t index);
    //Return index of the data if in the list SIZE_MAX otherwise
    size_t find(size_t block);
    //Returns index  of the list SIZE_MAX if invalid
    size_t max();
    list(){head= tail = nullptr;size =0;};
    ~list(){clear();}
};



#endif
