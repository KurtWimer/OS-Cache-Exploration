//Created by Kurt Wimer 2018
//Keeps track of blocks and generates a list of "optimal" blocks to cache

#ifndef __CACHE_H
#define __CACHE_H
#include <cstdlib> //for size_t

#include "../headers/linked_list.h"
//Use pop_max to empty the list easily

class cache{
    private:
        size_t max_size;//limit on blocks the cache can hold
        size_t count;//current number of blocks held
        list *info;//linked list with blocks
    public:
        //Input: block to add or update
        void add(size_t x);
        //Returns and deletes the value of the front item
        size_t popfront();
        //Returns and deletes the maximum value
        size_t pop_max();
        //Returns the current number of blocks held in the cache
        size_t size(){return count;};
        cache(size_t size){max_size = size;info = new list(); count =0;};
        ~cache(){delete info;};
};


#endif
