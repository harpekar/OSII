//A small assignment to practice using pthread to access a single event buffer using multiple threads

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <pthread.h>
#include "mt19937ar.h"


int main() {

    if (sizeof(int*) == 4){ //If the system is 32bit
     
    }
    
    else {
        unsigned a;
        asm ("RDRAND %%eax" : "=r" (a) );
    
    }
    
    return 0;
}
