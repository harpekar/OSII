//A small assignment to practice using pthread to access a single event buffer using multiple threads

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include <pthread.h>
#include "mt19937ar.h"

struct Item {
    int value;
    int workTime;
};

float randomValue() { //Computes a random value between 0 and 1, using the appropriate method

    unsigned a;
    float result;

    if (sizeof(int*) == 4){ //If the system is 32bit
        result = genrand_real3();         
    }
    else {
        printf("rdrand \n");
        asm ("RDRAND %%ax" : "=r" (a) );
        result = a/(pow(2,16)); 
    }

    return result;
}

int main() {

    if (sizeof(int*) == 4) {init_genrand(time(NULL));} //Initialize the Mersenne Twister if it's needed
    
    float a;
    
    a = randomValue();

    printf("%f \n", a);
    
    return 0;
}
