//Created by Kurt Wimer 2018

#include "../headers/cache.h"
#include <cstdint>

void cache::add(size_t block){
    size_t index;
    //already in list
    if((index = info->find(block)) != SIZE_MAX){
        //increment and move to the end
        node * block_node = info->pop(index);
        ++(block_node->count);
        info->pushback(block_node);
        return;
    }
    //not in list
    //remove lru and insert new element
    else if(count >= max_size){
        --count;
        delete info->popfront();
    }
    info->pushback(new node(block));
    ++count;
}
size_t cache::popfront(){
    node * temp = info->popfront();
    size_t val = temp->get_val();
    delete temp;
    --count;
    return val;
}

size_t cache::pop_max(){
    if(count == 0)return SIZE_MAX;
    node * temp =info->pop(info->max());
    --count;
    size_t val = temp->get_val();
    delete temp;
    return val;
}
