//Endrit Ngjelina COP 3514 #U43630372
//This program prompts user to input number of elements in array a and b
//Then it propmts user to input elements of each array
//After calculating using pointer arithmetic and while loops and if else statements
//The program outputs the exclusive or array containing the appropriate elements
#include <stdio.h>      //inculde stdio for input output

void exclusive_or(int *a, int num1, int *b, int num2, int *c, int *size) {  //function for exclusive or
    int *a_end = a + num1;  //pointer to end of array a, b and c
    int *b_end = b + num2;  
    int *c_end = c;       

    while (a < a_end && b < b_end) {        //compare elements from a and b
        if (*a < *b) {              //comapre when a is smaller than b
            *c_end = *a;
            a++;
        } 
        else if (*b < *a) { //if b is smaller than a
            *c_end = *b;    //c = b
            b++;            //increment b
        } 
        else {  //when elements are equal, skip both
            a++;    //increment a and b
            b++;
            continue;
        }
        c_end++;    //increment end of c
    }

    // Copy remaining elements from either a or b (not both)
    while (a < a_end) { 
        *c_end = *a;
        a++;
        c_end++;
    }
    while (b < b_end) {
        *c_end = *b;
        b++;
        c_end++;
    }
    
    *size = c_end - c;  // Calculate the size of the exclusive OR array

}

int main() {
    int size=0, num1=0, num2=0; //initialize variables for number of elements and size
         
    int c[num1 + num2];         //declare array c and its maximum size 
    printf("Enter length of array #1:");    //prompt user to input number of elements for first array
    scanf("%d", &num1);
    
    int a[num1];        //declare first array
    
    printf("Enter array elements: ");    //prompt user to input elements for first array
    for (int i = 0; i < num1; i++) {              //input all elements in array through loop
        scanf("%d", &a[i]);
    }
    
    printf("Enter length of array #2:");    //prompt user to input number of elements for second array
    scanf("%d", &num2);
    int b[num2];        //declare second array
    
    printf("Enter array elements: ");    //prompt user to input elements for second array
    for (int i = 0; i < num2; i++) {              //input all elements in array through loop
        scanf("%d", &b[i]);
    }

    exclusive_or(a, num1, b, num2, c, &size);   //call function

    printf("Output: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");	//end file with new line character
    return 0;
}