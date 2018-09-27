//Created by Kurt Wimer 2018
//Arranges sorted priority highest first data into an "organ" sequence cascading frequences from the center of an array outward.
//Such that a graph of position and frequency will look like a bell curve or organ 
//must know exact size when creating

#ifndef __ORGAN_H
#define  __ORGAN_H

#include "../headers/cache.h"
#include <cstddef>

class organ{
    private:
        size_t *block_sequence;//array containing block number sorted 
        size_t size;//maximum elements stored
        size_t count;//current number of elements stored
   public:
        //dummy constructor
        organ(){block_sequence = nullptr; size = count = 0;};
        //constructs sequence by using the cache passed it will empty that cache
        organ(cache *data);
        //Theoretically this line should be here but it resulted in deleting items twice
        ~organ(){delete block_sequence;block_sequence = nullptr;};
        //returns index of block MAX_SIZE if failed
        size_t find(size_t block);
        size_t get_size(){return size;};
};
#endif
