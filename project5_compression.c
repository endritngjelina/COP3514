//Endrit Ngjelina COP3514 U43630372
//This program prompts user for message
//Program performs a simple encoding algorithm on the message
//Algorithm can be describen by consecutive character count followed by the character
//If character appears once or twice consecutively, there is no compression
#include <stdio.h>

void compress(char *input, char *output) {  //function takes 2 character arrays as argument

    char *current = input;  //pointer for input string
    char *outcome = output;  //pointer for output string
    
    while (*current != '\0') {          //while current character is different from null 
        char current_character = *current;   //store current character in current pointer
        int counter = 1;      //initialize counter for consecutive character count to 1

        while (*(current + 1) == current_character) {   //count repeated occurrences of current character
            counter++;      //increment counter
            current++;      //pointer to next character
        }

        if (counter > 2) {
            *outcome = '0' + counter;// Store the count as a character in the result
            outcome++;// Move the result pointer to the next position
        } 
        
        else if (counter == 2) {        //special if counter is 2
        
            *outcome = current_character;       //store current character as the outcome
            
            outcome++;      //outcome pointer to next position
        }

        *outcome = current_character;       //store current character in outcome
        outcome++;      //outcome pointer to next position
        current++;      //current pointer to next character
    }
    *outcome = '\0';
}

int main() {
    char input[1001];   //input no more than 1000 characters
    char output[1001];  //output no more than 1000 characters

    printf("Enter message: ");  //prompt user for message
    scanf("%s", input);

    compress(input, output);        //call function

    printf("Output: %s\n", output); //display output

    return 0;       //return statement
}