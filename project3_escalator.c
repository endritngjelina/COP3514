//Endrit Ngjelina COP 3514 #U43630372
//This program prompts user to input number of people aboarding the escalator
//And the time in seconds when they hop in
//program calculates the time escalator is active, knowing that a ride is 10 seconds

#include <stdio.h>   //include for input output

int active_seconds(int arrival[], int n) {  
    
    int active_time = 0;        //variable for when escalator is active and escalator is inactive
    int inactive_time = -1; 

    for (int i = 0; i < n; i++) {       //for loop iterates for each time in array
    
        int person_enters = arrival[i];        //assign arrival time with array input
        int person_leaves = person_enters + 10;    //person leaves 10 seconds after entering

        if (person_enters > inactive_time) {
            active_time += (person_leaves - person_enters);    //add to active time the difference if times overlap
            inactive_time = person_leaves;     //update escalator end when person leaves
        } 
        else if (person_leaves > inactive_time) {	//if statement if person leaves before escalator is inactive
            active_time += (person_leaves - inactive_time);
            inactive_time = person_leaves;
        }
    }

    return active_time;
}

int main() {
    int n=0;		//initialize variable for people

    printf("Enter number of people: ");		//prompt user for number of people
    scanf("%d", &n);

    int arrival[n];		//variable array for time

    printf("Enter arrival times:");		//prompt user for time

    for (int i = 0; i < n; i++) {		//for loop to add time in array
        scanf("%d", &arrival[i]);   
    }

    printf("Active seconds: %d", active_seconds(arrival, n));		//print active seconds

    return 0;
}