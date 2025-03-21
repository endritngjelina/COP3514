//Endrit Ngjelina COP3514 U43630372
//This program prompts user for input
//Input is string and taken from command line arguments.
//If input string is in order, program returns 1 
//If input string is not in order, program returns 0
//If the string contains non-alphabetical letters, program returns -1
//If the number of arguments is not 2, then program prints invalid input 

#include <stdio.h>	//include for output, to lower, isAlpha, exit funciton and strings
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int inOrder(char *input) {  //function takes string input
    
    char c_neighbour = '\0';  //assign variable to null
    char *pointer = input;  //pointer to traverse string
    
    while (*pointer != '\0') {          //while character is different from null
        char character = tolower(*pointer);  //switch character to lowercase
        
        if (character < c_neighbour) {      //compare character to neighbour
            return 0;  //not in order
        }
        
        if (!isalpha(character)) {  //detect if character is non-alphabetical
            return -1;  //non-alphabetical character found
        }
        
        c_neighbour = character;
        pointer++;  //increment for next character in string
    }
    
    return 1;  //in order
}

int main(int argc, char *argv[]) {
    
    if (argc != 2) {        //check if there are 2 arguments
        printf("invalid input\n");  //if not, display error message
        return 1;
    }
    
    int result = inOrder(argv[1]);
    
    if (result == 0) {     	//if result equal to 0, display negative message
        printf("not in order\n");
        exit(0);
    } 
    else if (result == 1) {     //if result equal to 1, display positive message
        printf("in order\n");
        exit(0);
    } 
    else if (result == -1) {    //if result equal to 0, display negative message
        printf("invalid input\n");
      	exit(0);
    }
    
    return 0;
}
