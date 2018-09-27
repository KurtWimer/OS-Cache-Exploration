//Created by Kurt Wimer 2018
//A fake drive to abstract simulation of head movement/seeking
//include only one of the following in compilation cache_x where x=b,m,e
//this dictates the caches 'physical' location on the drive

#ifndef __DISK_H
#define __DISK_H
#include "../headers/linked_list.h"
#include "../headers/organ.h"
#include "../headers/cache.h"

class drive{
    private:
        size_t track_size;
        size_t disk_size;
        size_t head_loc;
        organ *my_organ;
        cache *next_cache;
        size_t seek_to(size_t block);;
    public:
        drive(size_t track,size_t disk,size_t cache_size);
        void prep(size_t block); 
        //Restructures drive based upon recorded block accesses
        //update must be run prior to any of the following functions
        void update();
        //Positions head at bloack, returns seek distance
        size_t read(size_t block);
        //Positions head at block, updates dirty bits if neccesary, returns seek distance
        size_t write(size_t block);
};
#endif
