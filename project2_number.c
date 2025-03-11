//Endrit Ngjelina COP 3514  U43630372
//This program takes an integer input from the user
//It checks input to see if it is a multiple of 3 or if it contains 3
//If it passes both tests, a positive message is displayed
//if it fails one or both tests, a negative message is displayed

#include<stdio.h>		//include library for input and output fucntions
	
int main(){

	int num, digit;		//establish variables and flag
	int flag = 0;
	
	printf("Enter input:");	//prompt user to enter input
	scanf("%d", &num);

	if (num%3==0){			//check if input is a multiple of three
		while(num != 0){	//while loop to find if there is a three in the input

		digit = num % 10;	

		num/=10;		//while loop continuously checks the remainder and division to see if number three is in there

			if(digit==3){		//set flag true if digit is three
				flag=1;
			}

		}

		if(flag){
			printf("yes");	//if flag picks up three, print positive message
		}

		else{
			printf("no");	//if flag does not pick up three, print negative message
		}
	}

	else{
		printf("no");	//if input is not multiple of three, print negative message
	}

	return 0;
}