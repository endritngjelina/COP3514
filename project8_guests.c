//Endrit Ngjelina COP 3514 #U43630372
//this program manages guest list of a restaurant
//the list is a dynamically allocated linked list
//it stores their phone number, last name, first name and party size
//if user already has been stored, program recognises user
//if user exists program, deallocate the memory allocated for the linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NAME_LEN 30
#define PHONE_LEN 20

struct guest{
    char phone[PHONE_LEN + 1];
    char last[NAME_LEN + 1];
    char first[NAME_LEN + 1];
    int party_size;
    struct guest *next;
};

struct guest *add_guest(struct guest *list);
void print_list(struct guest *list);
void clear_list(struct guest *list);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
    char code;

    struct guest *new_list = NULL;
    printf("Operation Code: a for adding to the list at the end, p for printing the list; q for quit.\n");
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
            case 'q': clear_list(new_list);
		            return 0;
      default:  printf("Illegal code\n");
        }
        printf("\n");
    }
}

struct guest *add_guest(struct guest *list) {
    struct guest *selected = list;
    char new_phone_number[PHONE_LEN];   //store guests new phone number

    printf("Enter phone number: ");          //prompt user for phone number
    read_line(new_phone_number, PHONE_LEN); 

    while (selected != NULL) {              //check if guest already exists
        if (strcmp(selected->phone, new_phone_number) == 0) {
            printf("guest already exists.");        //guest already exists
            return list; 
        }
        selected = selected->next;
    }

    struct guest *new_guest = (struct guest *)malloc(sizeof(struct guest)); //allocate memory for guest

    strcpy(new_guest->phone, new_phone_number);     //gather phone number, last, fist name and party size
    printf("Enter guest's last name: ");

    read_line(new_guest->last, NAME_LEN); 
    printf("Enter guest's first name: ");

    read_line(new_guest->first, NAME_LEN);
    printf("Enter party size: ");

    scanf("%d", &new_guest->party_size);
    new_guest->next = NULL;             //set next pointer of guest to null

    if (list == NULL) return new_guest;   //if list is empty, return new guest
    else {
        selected = list;
        while (selected->next != NULL) {
            selected = selected->next;
        }
        selected->next = new_guest; //add guest at the end of list
        return list;                //return list
    }
}

void print_list(struct guest *list) {       //print list function
    struct guest *selected = list;

    while (selected != NULL) {      //while loop to output data, while selected is not null
        printf("%-15s%-20s%-20s%5d\n", selected->phone, selected->last, selected->first, selected->party_size);
        selected = selected->next;
    }
}

void clear_list(struct guest *list) {       //clear list function

    struct guest *selected = list;
    struct guest *next;

    while (selected != NULL) {      //while loop to deallocate data
        next = selected->next;
        free(selected);
        selected = next;
    }
}

int read_line(char str[], int n) {
    int ch, i = 0;

    while (isspace(ch = getchar()));
    str[i++] = ch;
    while ((ch = getchar()) != '\n') {
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}