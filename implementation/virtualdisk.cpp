//Created by Kurt Wimer
//Not complete implementation of virtualdisk compile with only ONE of the files in cacheLocs/
#include "../headers/cache.h"
#include "../headers/virtualdisk.h"
#include <cstdint>

/****************************
 * Private functions
 * ***********************/
//seek_to implemented in the following files cache_b.cpp, cache_m.cpp, and cache_e.cpp for beginning, middle, and end
//copile with only one

/*************************
 * Public Functions
 * ***********************/

drive::drive(size_t track_sz,size_t disk_sz,size_t cache_size){
    track_size = track_sz;
    disk_size = disk_sz;
    my_organ = new organ();
    next_cache = new cache(cache_size);   
    head_loc = 0;
}

void drive::update(){
    delete my_organ;
    my_organ = new organ(next_cache);
}
size_t drive::read(size_t block){
    return seek_to(block);
}

void drive::prep(size_t block){
    next_cache->add(block);
}
