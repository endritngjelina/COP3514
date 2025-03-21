//Endrit Ngjelina COP 3514 #U43630372
//this file contains the read_line function of the program 
#include <ctype.h>
#include <stdio.h>
#include "read_line.h"      //include read_line header

int read_line(char str[], int n) {      //read line function
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