//Isaac Boteler BA01014@umbc.edu 
//CMPE 310 LAB 4 
//Driver code for aggregate_ints.s  
//Prompts user for file to read from 
//puts ints into array
//calls assembly function find_sum and prints output 

#include <stdio.h> //for io
#include <stdlib.h> //for conversion operations 
#include <stdint.h> //for sized ints, keeping everything in 64 for ease of access 

extern int64_t find_sum(int64_t*,int64_t); //Assembly function

//function to prompt user for file name, loops until acceptable input (fopen != null) 
FILE* getFileName(char *file_name);
int64_t readInt(FILE* fptr); //function for reading file 

int main()
{

    //Welcome  
    printf("Welcome to the program to find the of sum all integers in a file \n"); 
    //Prompt to exit 
    char user_input = 'n';
    char file_name[50];
    //main loop 
    while (user_input != 'y' && user_input != 'Y') {
        //declaration of array for the ints, we will allocate space once we read the file size  
        int64_t* int_values = NULL; 
        //Prompt for file_name until valid file 
        FILE* fptr = getFileName(file_name);
 
        //read first input 
        int64_t size = readInt(fptr);  
        //number of data values is contained in first entry of file 
        int_values = calloc(size,sizeof(int64_t)); 
        
        //read rest of values 
        for (int64_t i = 0;i < size;i++ ) {
            int_values[i] = readInt(fptr);
        }
        /*
        for (int64_t i = 0;i < size;i++ ) {
            printf("%d", int_values[i]);
            printf("\n");
        }
        */
        //Function call to assembly code 
        int64_t file_sum = find_sum(int_values,size);

        printf("%d", file_sum); 
        printf("\n");

        //Exit program prompt
        //Any character aside from y/Y will continue the program
        printf("exit program? (y/Y or n/N)\n");
        //flush newline 
        while ((getchar()) != '\n');
        scanf("%c", &user_input);
        //deallocate array 
        free(int_values);
    }
     
    return 0;
}
FILE* getFileName(char *file_name) {
    printf("Please input file name\n");
    scanf("%s",file_name);
    FILE* fptr = NULL; 
    while ( (fptr = fopen(file_name,"r")) == NULL) {
        printf("Could not open file, try again\n");
        scanf("%s",file_name);
    }
    return fptr;
}
//no error handling at this level; files are expected to have proper input 
int64_t readInt(FILE* fptr) {
    char data[50];
    fgets(data,50,fptr);

    return atoi(data); 
}