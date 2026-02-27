//Isaac Boteler BA01014@umbc.edu 
//CMPE 310 LAB 2 HAMMING DISTANCE TESTER
//Runs a series of tests against the find_hamming_distance function 
//cases include normal and edge 
#include <stdbool.h> 
#include <stdio.h>
//Constants
const int INPUT_SIZE = 256; 
const int NUM_TESTS = 10;

// inputs for assembly function 
extern unsigned char string_1[]; 
extern unsigned char string_2[];
extern int find_hamming_distance(void);   // Assembly function

//Testing function 
bool test_hamming(char *input_1, char* input_2,int distance);

int main()
{   printf("Testing the function find_hamming_distance\n");
    bool allTestsPassed = true; 
    //tests are for normal and edge cases, the driver handles the error handling of weird inputs 
    //distance is calculated by hand and by https://www.compscilib.com/calculate/hamming-distance?variation=default
    printf("Testing trivial:\n");
    if (allTestsPassed = test_hamming("1","1",0)) 
        printf("  Passed\n");
    else 
        printf("  Failed\n");

    printf("Testing different string lengths (1):\n");
    if (allTestsPassed = test_hamming("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        ,"a",0)) 
        printf("  Passed\n");
    else 
        printf("  Failed\n");

    printf("Testing different string lengths (2):\n");
    if (allTestsPassed = test_hamming("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        ,"b",2)) 
        printf("  Passed\n");
    else 
        printf("  Failed\n");

    printf("Testing normal:\n");
    if (allTestsPassed = test_hamming("car","truck",10)) 
        printf("  Passed\n");
    else 
        printf("  Failed\n");

    printf("Testing max length:\n");
    if (allTestsPassed = test_hamming("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        ,"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"
        ,510)) 
        printf("  Passed\n");
    else 
        printf("  Failed\n");

    if (allTestsPassed) 
        printf(" All Tests Passed :)\n");
    else 
        printf(" Do Better :(\n");

    return 0;
}

bool test_hamming(char *input_1, char* input_2,int actual_distance) {
    //load inputs into function
    for (int i = 0;i < INPUT_SIZE; i++) {
        string_1[i] = input_1[i]; 
        //check for null (end of string)
        if (input_1[i] == '\0') {
            break; 
        }
    }
    for (int i = 0;i < INPUT_SIZE; i++) {
        string_2[i] = input_2[i]; 
        //check for null (end of string)
        if (input_2[i] == '\0') {
            break; 
        }
    }   
    //calculate and check    
    int calculated_distance = find_hamming_distance();   
    //print inputs and outputs if test fails 
    if (actual_distance != calculated_distance) {
        printf("%s \n%s \n", input_1, input_2);
        printf("Should have calculated: %d,Instead %d",actual_distance,calculated_distance);  
        return false; 
    } 
    return true; 
}
