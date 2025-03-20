//Endrit Ngjelina COP3514 U43630372
//This program takes selection input, day input and hours input from user
//Based on the input, the program calculates the charge, which changes based on selection, day and hour
//If selection and hour input is incorrect, the program prints error message and exits

#include <stdio.h>	//include for inputs, outputs and exit
#include <stdlib.h>

int main(){

	int selection, days, hours, charge;	//declare all integer variables

	printf("Please select from four equipment: 1, 2, 3, and 4\n");	
	printf("Enter equipment selection: ");		// prompt user for selection input
	scanf("%d", &selection);

	if(selection==1){			//if selection is one, prompt user to enter days
		printf("Enter days: ");
		scanf("%d", &days);

		if (days>=0){		//if days are greater than or equal to zero, prompt user to enter hours
			printf("Enter hours: ");
			scanf("%d", &hours);

			if (hours==0){		//if hours equal zero, calculate and print charge

				charge = (days/7)*40+(days%7)*10;	//This is formula to calculate charge when hours are zero
						
				if(charge>((days/7)*40)+40){		//if charge surpasses the weekly cap, charge equals weekly cap
					charge=((days/7)*40)+40 ;
					printf("Charge($): %d", charge);	
				}

				else {					//If charge does not surpass weekly cap, charge is calculated normally
					charge = (days/7)*40+(days%7)*10;	
					printf("Charge($): %d", charge);
				}
			}
			else if (hours>=1 && hours<=4){		//if hours between one and four calculate and print charge

				charge = (days/7)*40+(days%7)*10+7;

				if (charge>((days/7)*40)+40){
					charge = ((days/7)*40)+40;
					printf("Charge($): %d", charge);
				}
 
				else{
					charge = (days/7)*40+(days%7)*10+7;
					printf("Charge($): %d", charge);
				}
			}

			else if(hours>=5 && hours<=23){		//if hours between five and twenty-three calculate and print charge
				charge = (days/7)*40+(days%7)*10+10;

				if(charge>((days/7)*40)+40){
					charge=((days/7)*40)+40;
					printf("Charge($): %d", charge);
				}

				else{
					charge = (days/7)*40+(days%7)*10+10;
					printf("Charge($): %d", charge);
				}
			}		
			else{					//else print error message
				printf("Invalid hours.");
				exit(0);			//exit program
			}
		}

	}
	else if(selection==2){		//if selection is two, prompt user to enter days

		printf("Enter days: ");
		scanf("%d", &days);

		if(days>=0){			//if days entered are greater or equal to zero, prompt user to enter hours 
			printf("Enter hours: ");
			scanf("%d", &hours);

			if(hours==0){		//if hours equal zero, calculate and print charge
				charge = (days/7)*156+(days%7)*39;

				if (charge>((days/7)*156)+156){
					charge=((days/7)*156)+156;
					printf("Charge($): %d", charge);
				}
				else{
					charge =(days/7)*156+(days%7)*39;
					printf("Charge($): %d", charge);
				}
			}

			else if(hours<=4 && hours >=1){		//if hours are between one and four, calculate and print charge
						
				charge = (days/7)*156+(days%7)*39+27;

				if (charge>((days/7)*156)+156){
					charge = ((days/7)*156)+156;
					printf("Charge($): %d", charge);
						}
					
				else{
					charge = (days/7)*156+(days%7)*39+27;
					printf("Charge($): %d", charge);
				}
			}
			else if(hours>=5 && hours<=23){		//if hours are between five and twenty-three, calculate and print charge
				charge = (days/7)*156+(days%7)*39 + 39;

				if(charge>((days/7)*156)+156){
					charge = ((days/7)*156)+156;
					printf("Charge($): %d", charge);
				}
				else{
					charge = (days/7)*156+(days%7)*39+39;
					printf("Charge($): %d", charge);
				}
			}
			else{					//else print error message
				printf("Invalid hours.");
				exit(0);		//exit program
			}
		}				
	}
	else if(selection==3){			//if selection is three, prompt user to enter days
		printf("Enter days: ");
		scanf("%d", &days);

		if(days>=0){			//if days are greater than or equal to zero, prompt user to enter hours
			printf("Enter hours: ");
			scanf("%d", &hours);
			
			if(hours==0){		//if hours are equal to zero, calculate and print charge

				charge =(days/7)*348+(days%7)*87;

				if(charge>((days/7)*348)+348){

					charge=((days/7)*348)+348;
					printf("Charge($): %d", charge);
				}

				else {
					charge = (days/7)*348+(days%7)*87;
					printf("Charge($): %d", charge);
				}
			}
			else if(hours>=1 && hours<=4){		//if hours is between one and four, calculate and print charge
				charge = (days/7)*348+(days%7)*87+61;

				if(charge>((days/7)*348)+348){
					charge = ((days/7)*348)+348;
					printf("Charge($): %d", charge);
				}
				else{
					charge = (days/7)*348+(days%7)*87+61;
					printf("Charge($): %d", charge);
				}
			}

			else if(hours>=5 && hours<=23){		//if hours is between five and twenty-three, calculate and print charge
				charge = (days/7)*348+(days%7)*87+87;
				
				if(charge>((days/7)*348)+348){
					charge = ((days/7)*348)+348;
					printf("Charge($): %d", charge);
				}
				
				else{
					charge = (days/7)*348+(days%7)*87+87;
					printf("Charge($): %d", charge);
				}
							}
			else{					//else print error message
				printf("Invalid hours.");
				exit(0);			//exit program
				}
		}
	}
	else if(selection==4){		//if selection equals four, prompt user to enter days
		printf("Enter days: ");
		scanf("%d", &days);

		if (days>=0){		//if days are greater than or equal to zero, prompt user to input hours
			printf("Enter hours: ");
			scanf("%d", &hours);

				if(hours==0){	//if hours are equal to zero, calculate and output charge

					charge =(days/7)*336+(days%7)*84;
					printf("Charge($): %d", charge);
					
					if(charge>((days/7)*336)+336){
						charge=((days/7)*336)+336;
						printf("Charge($): %d", charge);
					}
					else{
						charge=(days/7)*336+(days%7)*84;
						printf("Charge($): %d", charge);
					}	
				}

				else if(hours<=4 && hours>=1){ 			//if hours between four and one, calculate and print charge
					charge = (days/7)*336 + (days%7)*84 + 59;

					if (charge>((days/7)*336)+336){
						charge = ((days/7)*336)+336;
						printf("Charge($): %d", charge);
					}

					else{
						charge = (days/7)*336+(days%7)*84+59;
						printf("Charge($): %d", charge);
					}
				}
				else if(hours>=5 && hours<=23){			//if hours between five and twenty-three, calculate and print charge
					charge = (days/7)*336 + (days%7)*84+ 84;
					
					if(charge>((days/7)*336)+336){
						
						charge = ((days/7)*336)+336;
						printf("Charge($): %d", charge);
						}			
					
					else{
						charge = (days/7)*336+(days%7)*84+84;
						printf("Charge($): %d", charge);
						}
				}
				else{					//else output error message fofr hours
					printf("Invalid hours.");
					exit(0);			//exit program
				}
		}
	}

	else{								//output error message if selection is incorrect
		printf("Invalid selection. Select from 1 to 4.");
		exit(0);  						//exit program if selection is incorrect
  	}
	
	return 0;
}