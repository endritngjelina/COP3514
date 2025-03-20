//Endrit Ngjelina COP 3514 #U43630372
//This program prompts user to input number of people aboarding the escalator
//And the time in seconds when they hop in
//program calculates the time escalator is active, knowing that a ride is 10 seconds
//Function uses pointer arithmetic to visit array elements
#include <stdio.h>      //include stdio for input and output

int active_seconds(int arrival[], int n) {
    int active_time = 0;    //variables when escalator is active or inactive
    int inactive_time = -1;

    int *arr_pointer = arrival;  //initialize pointer to the beginning of array

    for (int i = 0; i < n; i++) {       //loop through all elements of array 
        int person_enters = *arr_pointer;          //use pointer to access array element
        int person_leaves = person_enters + 10;     //person leaves 10 seconds after entering

        if (person_enters > inactive_time) {
            active_time += (person_leaves - person_enters); //add to active time the difference if times overlap
            inactive_time = person_leaves;  //update escalator end when person leaves
            
        } 
        else if (person_leaves > inactive_time) {   //if statement if person leaves before escalator is inactive
            active_time += (person_leaves - inactive_time);
            inactive_time = person_leaves;
        }

        arr_pointer++;  //move pointer to next element
    }
    return active_time;
}

int main() {
    int n = 0;  //initialize variable for people
    
    printf("Enter number of people: ");     //prompt user to input people 
    scanf("%d", &n);

    int arrival[n];                     //initialize array for time
    printf("Enter arrival times: ");     //prompt user to input times

    for (int i = 0; i < n; i++) {       //for loop to add time in array
        scanf("%d", &arrival[i]);
    }
    
    printf("Active seconds: %d", active_seconds(arrival, n));   //print active seconds
    return 0;
}