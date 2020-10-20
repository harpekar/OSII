//A small assignment to practice using pthread to access a single event buffer using multiple threads

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include <pthread.h>
#include "mt19937ar.h"

struct Item {
    float value;
    float workTime;
};

float randomValue() { //Computes a random value between 0 and 1, using the appropriate method

    unsigned a;
    float result;

    if (sizeof(int*) == 4){ //If the system is 32bit
        result = genrand_real3();         
    }
    else {
        asm ("RDRAND %%ax" : "=r" (a) );
        result = a/(pow(2,16)); 
    }

    return result;
}

struct Item makeItem() {

    struct Item item;

    item.value = randomValue() * 10; 
    item.workTime = randomValue()*7 + 2;

    return item;

}

int main() {

    if (sizeof(int*) == 4) {init_genrand(time(NULL));} //Initialize the Mersenne Twister if it's needed
    
    struct Item i;
    
    i = makeItem();

    printf("%f \n", i.value);
    printf("%f \n", i.workTime);
    
    return 0;
}
