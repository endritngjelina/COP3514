//Endrit Ngjelina COP 3514 #U43630372
//this program works the same as project 9, but is split in numerous files
//There is a guest and read_line file, there is a header file for both aforementioned files and this file with the main function
#include <stdio.h>
#include "guest.h"
#include "read_line.h"

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/

int main(void) {
   char code;

    struct guest *new_list = NULL;
    printf("Operation Code: a for adding to the list at the end, r for removing from the list, p for printing the list; q for quit.\n");
    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')   /* skips to the end of the line */
            ;
        switch (code) {
            case 'a': new_list = add_guest(new_list);
                    break;
            case 'p': print_list(new_list);
                    break;
            case 'r': remove_guest(&new_list);
                    break;
            case 'q': clear_list(new_list);
                    return 0;
            default:  printf("Illegal code\n");
        }
        printf("\n");
    }
}