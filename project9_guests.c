//Endrit Ngjelina COP 3514 #U43630372
//this program manages the guest list of a restaurant
//it is updated so that it can remove a guest from the list
//it does so from the custom remove_guest function
//it works by locating the node, altering the previous node and calling free that memory space
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
struct guest *add_guest(struct guest *list);
void print_list(struct guest *list);
void clear_list(struct guest *list);
void remove_guest(struct guest **list);
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

void print_list(struct guest *list) { //print list function
    struct guest *selected = list;

    while (selected != NULL) {      //while loop to output data, while selected is not null
        printf("%-15s%-20s%-20s%5d\n", selected->phone, selected->last, selected->first, selected->party_size);
        selected = selected->next;
    }
}

void clear_list(struct guest *list) { //clear list function

    struct guest *selected = list;
    struct guest *next;

    while (selected != NULL) {      //while loop to deallocate data
        next = selected->next;
        free(selected);
        selected = next;
    }
}

void remove_guest(struct guest **list) {

    char remove_phone[PHONE_LEN];   //char arrays to store data
    char remove_last[NAME_LEN];
    char remove_first[NAME_LEN];

    printf("Enter phone number:");      //prompt user for input
    read_line(remove_phone, PHONE_LEN);
    printf("Enter guest's last name:");
    read_line(remove_last, NAME_LEN);
    printf("Enter guest's first name:");
    read_line(remove_first, NAME_LEN);

    struct guest *selected = *list;      //pointers for traversal
    struct guest *previous = NULL;

    while (selected != NULL) {       //ckeck if current guest matches target criteria
        if (strcmp(selected->phone, remove_phone) == 0 && strcmp(selected->last, remove_last) == 0 && strcmp(selected->first, remove_first) == 0) {
            if (previous == NULL) {         //check if matched guest is head of list
                *list = selected->next;      //update head of list
            } 
            else {
                previous->next = selected->next;     //update previous nodes next pointer
            }

            free(selected);      //free memory for removed guest
            return;
        }
        //go to next guest in the list
        previous = selected;     
        selected = selected->next;
    }
    printf("Guest does not exist.\n");
}