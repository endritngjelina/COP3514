//Endrit Ngjelina COP 3514 #U43630372
//this program is a modified version of project 7
//this prorgam uses quick sort to sort the animal list by species and age
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ANIMALS_MAXIMUM 200
#define STRING_LENGTH_MAXIMUM 100

struct Animal {     //define animal structure 
    char gender[STRING_LENGTH_MAXIMUM];
    char name[STRING_LENGTH_MAXIMUM];
    char species[STRING_LENGTH_MAXIMUM];
    int age;
    double weight;
};

//quick sort function to compare animals 
int compare_animals(const void *a, const void *b) {
    
    int compare_species = strcmp(((struct Animal *)a)->species, ((struct Animal *)b)->species);  //compare species
    if (compare_species != 0) {
        return compare_species;
    }

    int compare_age = ((struct Animal *)a)->age - ((struct Animal *)b)->age; //compare age
    return compare_age;
}

int main() {

    FILE *input_file = fopen("animals.txt", "r");       //open input file to read
    struct Animal animals[ANIMALS_MAXIMUM];     //array for storing animal information

    int count = 0;            //initialize the count of animals to 0

    while (fscanf(input_file, "%s %s %s %d %lf",        //read data from input file
                  animals[count].name,
                  animals[count].species,
                  animals[count].gender,
                  &animals[count].age,
                  &animals[count].weight) == 5) {
        count++;
    }
    
    fclose(input_file);     //close input file

    qsort(animals, count, sizeof(struct Animal), compare_animals);  //use quick sort to sort animals

    FILE *output_file = fopen("results.txt", "w");      //open output file to write

    for (int i = 0; i < count; i++) {           //print the sorted animals in desired format
        fprintf(output_file, "%s %d %s %.2lf %s\n",
                animals[i].species,
                animals[i].age,
                animals[i].name,
                animals[i].weight,
                animals[i].gender);
    }

    fclose(output_file);        //close output file

    printf("Output file name: results.txt\n");
    
    return 0;
}