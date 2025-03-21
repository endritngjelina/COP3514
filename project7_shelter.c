//Endrit Ngjelina COP 3514 #U43630372
//this program prompts user for species and gender, and searches for animals in a data file
//the program keeps track of number of animals in file as it reads from it
//output file is named result.txt
//the output includes name, age, weight of matching animals
#include <stdio.h>
#include <string.h>
#define ANIMALS_MAXIMUM 200     
#define STRING_LENGTH_MAXIMUM 100   //define max number of animals and max length

struct Animal {     //struct for animals
    char gender[STRING_LENGTH_MAXIMUM];
    char name[STRING_LENGTH_MAXIMUM];
    char species[STRING_LENGTH_MAXIMUM];
    int age;
    double weight;
};

int main() {
    FILE *input_file = fopen("animals.txt", "r");    //open input file for reading
    
    struct Animal animals[ANIMALS_MAXIMUM];     //create array to store animal information
    int animals_count = 0;                        //initialize animals count to 0

    while (fscanf(input_file, "%s %s %s %d %lf", animals[animals_count].name, animals[animals_count].species, animals[animals_count].gender, &animals[animals_count].age, &animals[animals_count].weight) == 5) {
        animals_count++;       //read data from input file
    }

    fclose(input_file);      //close input file

    char search_species[STRING_LENGTH_MAXIMUM];      //initialize search for species and gender
    char search_gender[STRING_LENGTH_MAXIMUM];

    printf("Enter species: ");  //prompt user for species
    scanf("%s", search_species);    //take input for species
    printf("Enter gender: ");   ////prompt user for gender
    scanf("%s", search_gender);     //take input for gender
    
    FILE *output_file = fopen("results.txt", "w");   //open output file for writing

    //for loop to match animals and write results in output file
    for (int i = 0; i < animals_count; i++) {
        if (strcmp(animals[i].species, search_species) == 0 && strcmp(animals[i].gender, search_gender) == 0) {
            fprintf(output_file, "%s %d %.2lf\n", animals[i].name, animals[i].age, animals[i].weight);
        }
    }

    fclose(output_file);        //close the output file
    printf("Output file name: results.txt\n");

    return 0;
}