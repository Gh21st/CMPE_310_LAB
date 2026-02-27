//Isaac Boteler BA01014@umbc.edu 
//CMPE 310 LAB 2 
//Driver code for hamming_distance_calculator 
//Prompts user for 2 strings, returns hamming distance 
//Loops until user requests exist
//string input must be 255 characters or less 
//string must be of standard printable characters (ASCII 33 - 127)

#include <string.h>
#include <stdio.h>

//for strings up to size 255 we need an additional character for null 
const int INPUT_SIZE = 256; 
// inputs for assembly function 
extern unsigned char string_1[]; 
extern unsigned char string_2[];
extern int find_hamming_distance(void);   // Assembly function

void getInput(char* input); //function for getting input 

int main()
{
    //Welcome  
    printf("Welcome to the program to calculate the hamming distance between 2 strings\n"); 
    //Prompt to exit 
    char user_input = 'n';
    //main loop 
    while (user_input != 'y' && user_input != 'Y') {
        //Prompt for string
        printf("please input the first string \n");
        getInput(string_1); 
        printf("Please input the second string \n");
        getInput(string_2);
        printf("Thank you, the hamming distance for strings ");
        printf(string_1);
        printf(" and ");
        printf(string_2); 
        printf("\nis: ");

        //Function call to assembly code 
        int hamming_distance = find_hamming_distance();

        printf("%d", hamming_distance); 
        printf("\n");

        //Exit program prompt
        //Any character aside from y/Y will continue the program
        printf("exit program? (y/Y or n/N)\n");
        scanf("%c", &user_input);
        //flush newline 
        while ((getchar()) != '\n');
    }


    return 0;
}
void getInput(char* input) {
    //prompt user until we have valid input
    //invalid input is input that is too long  
    while (fgets(input, INPUT_SIZE, stdin) == NULL) {
        printf("input can be no longer than 255 characters \n");
    } 
    //strip LF character from input, replace with null character 
    input[strcspn(input,"\n")] = '\0';

    return; 
}