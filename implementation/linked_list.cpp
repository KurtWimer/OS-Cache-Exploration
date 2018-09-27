//Created by Kurt Wimer 2018
#include "../headers/linked_list.h"
#include <cstdint>
#include <iostream>

node * list::popfront(){
    if(head == nullptr) exit(EXIT_FAILURE);
    node * temp = head;
    head = head->next;
    if (head ==nullptr) tail = nullptr;
    --size;
    return temp;
}

void list::pushback(node *newNode){
    //check for valid input
    if(newNode == nullptr){
        std::cerr << "Uninitialized node\n";
        exit(EXIT_FAILURE);
    }
    newNode->next = nullptr;
    //first item
    if (head == nullptr) head = tail = newNode;
    //any other case
    else tail = tail->next = newNode;
    ++size;
}

node * list::pop(size_t index){
    //check for valid input
    if(index > size) exit(EXIT_FAILURE);
    node * target;
    //keep head case consistant
    if(index == 0) return popfront();
    else{
        //seek to index
        node *cursor = head;
        for(size_t i = 0; i<index-1; ++i) cursor = cursor->next;
        //update list
        target=cursor->next;
        cursor->next = cursor->next->next;
        //keep tail consistant
        if(index == size-1) tail = cursor;
    }
    --size;
    return target;
}

size_t list::find(size_t block){
    node *cursor = head;
    size_t index = 0;
    while(cursor != nullptr){
        if(cursor->val == block) return index;
        cursor = cursor->next;
        ++index;
    }
    return SIZE_MAX;
}

size_t list::max(){
    //check for valid input
    if(head == nullptr) return SIZE_MAX;   
    node *cursor =head;
    size_t index = 0;
    size_t max_index =0;
    size_t max = head->get_val();//initialize to the first element
    while((cursor = cursor->next) != nullptr) (cursor->get_val()>max) ? max_index = index++ : ++index;
    return index;
}
