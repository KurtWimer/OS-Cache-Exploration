//Created by Kurt Wimer
//Program that simulates hard drives execution based upon command line file containing block read requests
//Takes 3 command line arguments track, disk, and cache sizes.

#include "../headers/virtualdisk.h"
#include <stdio.h>
#include <iostream>

//Argument orders file, cache_size,
int main(int argc,char * argv[]){
//parse command line arguments
if(argc != 4){
    std::cerr << "Please input sector size, disk size, and cache size";
    exit(EXIT_FAILURE);
}
const size_t track_size = strtoul(argv[1],nullptr, 0);
const size_t disk_size = strtoul(argv[2],nullptr, 0);
const size_t cache_size = strtoul(argv[3],nullptr, 0);
const size_t refresh_freq = 100000; 

drive * disk = new drive(track_size,disk_size,cache_size);

size_t block = 0;
size_t reset_timer= refresh_freq;
size_t cache_fill = 0;
//prepare drive with initial sample data 
while(scanf("%zd",&block) != EOF){
    disk->prep(block);
    if(++cache_fill == cache_size){
        disk->update();
        break;
    }
}


size_t distance = 0;
while(scanf("%zd",&block) != EOF){
    distance+= disk->read(block);
    if(--reset_timer == 0){
        disk->update();
        reset_timer= refresh_freq;
    }
}
//Output total seek distance
std::cout << distance << "\n";


}
