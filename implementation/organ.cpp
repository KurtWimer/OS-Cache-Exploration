//Created by Kurt Wimer
#include "../headers/organ.h"
#include <cstdio>
#include <cstdint>

size_t organ::find(size_t block){
    for(size_t i =0;i<count;++i){
        if(block_sequence[i] == block) return i;
    }
    return SIZE_MAX;
}

organ::organ(cache *input){
    //check for valid input
    if(input == nullptr)exit(EXIT_FAILURE);
    count = size = input->size();
    block_sequence = new size_t[size];
    //Alternates betwen add element at low and high pushing outward from middle of the array
    bool odd = true;
    size_t low;
    //find initial middle point;
    ((input->size())%2 == 0) ? low = input->size()/2-1 : low = input->size()/2;
    size_t high = low+1;
    size_t block;
    while((block= input->pop_max())!= SIZE_MAX){
        block_sequence[odd ? low-- : high++] = block;
        odd = !odd;
    }
}

