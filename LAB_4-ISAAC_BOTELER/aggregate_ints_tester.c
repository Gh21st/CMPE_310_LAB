//Isaac Boteler BA01014@umbc.edu 
//CMPE 310 LAB 4 
//Tester code for aggregate_ints.s  
//Runs a series of tests for the assembly function find_sum in aggegate_ints.s 
//calls assembly function find_sum and prints output 
#include <stdio.h> //for io
#include <stdint.h> //for sized ints, keeping everything in 64 for ease of access 
extern int64_t find_sum(int64_t*,int64_t); //Assembly function

int main() {
    //Declaration of testing variables
    int64_t mixed_values[] = {
        -10,
        0,
        10,
        20,
        30,
        40,
        50,
        60,
        70,
        80,
        90,
        100
    };
    int64_t mixed_values_len = 12; 
    int64_t mixed_values_sum = 540; 

    int64_t LARGE_values[] = {
        256, 
        65536,
        4294967296
    };
    int64_t LARGE_values_len = 3;
    int64_t LARGE_values_sum = 4295033088; 
    //End of declaration 

    printf("Testing assembly function find_sum:\n\n"); 
    
    printf("Testing mixed value array (-,0,+)\n");
    if (find_sum(mixed_values,mixed_values_len) == mixed_values_sum)
        printf("  Passed mixed value test\n");
    else 
        printf("  Failed mixed value test\n");

    printf("testing large value array (2^8,2^16,2^32)\n");
    if (find_sum(LARGE_values,LARGE_values_len) == LARGE_values_sum)
        printf("  Passed large value test\n");
    else 
        printf("  Failed large value test\n");


    printf("All tests completed\n");
    return 0; 
}

