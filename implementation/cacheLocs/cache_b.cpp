//Created by Kurt Wimer 2018
#include "../../headers/cache.h"
#include "../../headers/virtualdisk.h"
#include <cstdint>

/****************************
 * Private functions
 * ***********************/
size_t drive::seek_to(size_t block){
    const size_t cache_offset = 0;
    size_t distance;
    size_t loc; //sector number to seek to
    //update future cache values
    next_cache->add(block);
    
    //calculate loc
    //check if in cache
    if((loc = my_organ->find(block) != SIZE_MAX)){
        loc = (loc%track_size==0) ? loc/track_size : loc/track_size +1;
        loc+=cache_offset;
    }
    else{
        loc =  block/track_size + my_organ->get_size()/track_size;
    }
    
    //update head location
    size_t old_head = head_loc;
    head_loc = loc;
    return (loc > old_head) ? loc - old_head : old_head -loc;
}

