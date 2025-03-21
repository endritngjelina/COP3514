//Endrit Ngjelina COP 3514 #U43630372
//this program takes first letter of each word in a file
//it asks user to enter the file name, it opens and reads file
//the program decodes message, then writes result message to same file but with decoded
#include <stdio.h>
#include <string.h>

void decode(char words[][101], int num_words, char *result) {   //custom void function with three parameters
    for (int i = 0; i < num_words; i++) {       //for loop to iterate through
        if (words[i][0] != '\0') {          //conditional statement to check null statement
            *result++ = words[i][0];  //copy first character of each word to the result string
        }
    }
    *result = '\0';  //null-terminate the result string
}

int main() {                    //main function
    char namefile[101];
    printf("Enter the file name: ");        //prompt user to enter file name
    scanf("%s", namefile);         //read name of the input file from user

    FILE *fileinput = fopen(namefile, "r");  //open input file for reading

    if (fileinput == NULL) {
        printf("Unable to open the file.\n");
        return 1;  //exit with error code if the file cannot be opened
    }

    char name_output_file[201];
    snprintf(name_output_file, sizeof(name_output_file), "decoded_%s", namefile);  //create output file name

    FILE *fileoutput = fopen(name_output_file, "w");  //open output file for writing

    if (fileoutput == NULL) {      //conditional statement if file output equals null
        printf("Unable to create the output file.\n");
        fclose(fileinput);
        return 1;  //exit with error code if the output file cannot be created
    }

    char words[1000][101];  //array to store words from input
    int num_words = 0;

    char word[101];  //temporary buffer for reading words from input
    int wordindex = 0;
    char c;

    while ((c = fgetc(fileinput)) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (wordindex > 0) {
                word[wordindex] = '\0';
                strcpy(words[num_words], word);  //copy the word to the words array
                num_words++;
                wordindex = 0;
            }
        } 
        else {
            word[wordindex++] = c;  //build words character by character
        }
    }

    if (wordindex > 0) {           //conditional statement if word index is greater than 0
        word[wordindex] = '\0';
        strcpy(words[num_words], word);  //copy last word to the words array
        num_words++;
    }

    char result[1001];  //buffer for decoded message
    decode(words, num_words, result);  //call the decode function to process the words

    fprintf(fileoutput, "%s", result);  //write decoded message to the output file

    printf("Decoded message written to %s\n", name_output_file);

    fclose(fileinput);  //close input file
    fclose(fileoutput);  //close output file

    return 0;  //exit with success code
}