//Endrit Ngjelina COP 3514 #U43630372
//This program prompts user to input selection number, days and hours
//program calculates charge based on input
//if input is incorrect, it displays error message
#include <stdio.h>
#include <stdlib.h>

int main() {
    int selection, days, hours, charge;     //declare variable for selection, days, hours and charge

    //store rates for different selection in array
    int selection_rates[4][3] = {
        {7, 10, 40},{27, 39, 156},{61, 87, 348},{59, 84, 336}   //4 hourly rate, dayly rate, weekly rate
    };

    printf("Please select from four equipment: 1, 2, 3, and 4\n");
    printf("Enter equipment selection: ");  //prompt user for input
    scanf("%d", &selection);

    if (selection >= 1 && selection <= 4) { //if selection is valid

        printf("Enter days: "); //prompt user for day input
        scanf("%d", &days);

        if (days >= 0) {
            printf("Enter hours: ");    //prompt user for hour input
            scanf("%d", &hours);

            int selection_index = selection - 1; //calibrate for index 0

            // Calculate the charge based on equipment rates and hours
            if (hours == 0) {		//if hours equal to 0, use the following formula
                charge = (days / 7) * selection_rates[selection_index][2]+
                         (days % 7) * selection_rates[selection_index][1];
            } 
            else if (hours >= 1 && hours <= 4) {	//if hours between 1 and 4, use different formula
                charge = (days / 7) * selection_rates[selection_index][2] +
                         (days % 7) * selection_rates[selection_index][1] + selection_rates[selection_index][0];
            } 
            else if (hours >= 5 && hours <= 23) {	//if hours between 5 and 23, use different formula
                charge = (days / 7) * selection_rates[selection_index][2] +
                         (days % 7) * selection_rates[selection_index][1]+ selection_rates[selection_index][1];
            } 
            else {
                printf("Invalid hours.\n");		//display error message for hours
                exit(0);
            }

            //if charge surpasses weekly cap
            if (charge > ((days / 7) * selection_rates[selection_index][2]) + selection_rates[selection_index][2]) {
                charge = ((days / 7) * selection_rates[selection_index][2]) + selection_rates[selection_index][2];
            }

            printf("Charge($): %d\n", charge);      //print charge
        } 
        else {
            printf("Invalid days.\n"); //display invalid message for days
            exit(0);
        }
    } 
    else {
        printf("Invalid selection. Select from 1 to 4.\n"); //if selection is invalid print error message
        exit(0);
    }
    return 0;
}