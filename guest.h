//Endrit Ngjelina COP 3514 #U43630372
//this program contains function prototype for read_line function
//The file enclosed contents of the header file in an #ifndef-#endif pair to protect the file
#ifndef GUEST_H         //ifndef to protect file
#define GUEST_H         //define guest_h

#define NAME_LEN 30
#define PHONE_LEN 20

struct guest {                      //struct for guest
    char phone[PHONE_LEN + 1];
    char last[NAME_LEN + 1];
    char first[NAME_LEN + 1];
    int party_size;
    struct guest *next;
};

struct guest *add_guest(struct guest *list);
void print_list(struct guest *list);
void clear_list(struct guest *list);
void remove_guest(struct guest **list);

#endif              //endif to protect file