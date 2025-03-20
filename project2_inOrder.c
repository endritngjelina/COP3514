//Endrit Ngjelina COP3514 U43630372
//This program prompts user for input
//If input consists of letters ordered alphabetically, it prints "in order"
//If input consists of disordered letters, it prints "not in order" 
//Any other input is met with an "invalid input" error message 
#include <stdio.h>      
#include <ctype.h>
#include <stdlib.h>     //include for input, output, getchar, tolower, isalpha and exit
int main()
{
    char character, character_neighbour;    //declare variable for character and neighbour
    
    printf("Enter input:");     //prompt user for input 

    while((character = getchar()) != '\n'){     //while loops gets characters until new line character 
        
        character = tolower(character);     //Convert everything to lowercase
        
        if(!isalpha(character)){        //if statement to check if all inputs are character type
            printf("invalid input");    
            exit (0);               
        }
        
        if(character < character_neighbour){    //if statement to compare two neighbouring characters 
            printf("not in order");
            exit (0);
        }
        
        character_neighbour = character;     //assign character to neighbour
       
    }
    printf("in order");
    
    return 0;
}