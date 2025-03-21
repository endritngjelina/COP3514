//Endrit Ngjelina COP 3514 #U43630372
//this program contains all functions related to operations on list of guests 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "guest.h"      //add both header files for guest and read_line
#include "read_line.h"

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

void print_list(struct guest *list) {
    struct guest *selected = list;

    while (selected != NULL) {      //while loop to output data, while selected is not null
        printf("%-15s%-20s%-20s%5d\n", selected->phone, selected->last, selected->first, selected->party_size);
        selected = selected->next;
    }
}

void clear_list(struct guest *list) {
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
