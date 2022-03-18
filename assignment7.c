//
//  main.c
//  Assign7
//  Created by noah holt due 11/22/21.
//  this assignment is to create pet structures(new concept) and
//  store them in linked lists (ne concept) and then sort them or add them sorted
//  to that list so that when printing it works out.
//

//includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <limits.h>

#define NAMESIZE 25

//first up, define our structure
typedef struct pet{
    char name[NAMESIZE];
    int age;
    struct pet *nextPet;
}Pet;
 

//function prototypes
bool validInt(char *buff, long *makeMe);
void introducePet(struct pet **headPtr, struct pet *addMe);
void deletePet(struct pet **headPet, char removeMe[NAMESIZE]);
struct pet createPet(void);
int compareName(const struct pet *name1, const struct pet *name2);

int main(void) {
    
    //first how many pets are there
    
    //start vars
    
    //assignment says no need to validate so...
    int comingIn;
    printf("%s\n", "How many pets will be entered?");
    scanf("%d", &comingIn);
    
    // starting head
    struct pet *headPet = NULL;
    
    for(size_t i = 0; i < comingIn; i++) {
        
        struct pet *aPet = NULL;
        aPet = malloc(sizeof(struct pet));
        //again no validation
        if(aPet != NULL){
            //get name
            printf("%s\n", "enter your pets name:");
            scanf("%s", aPet->name);
            //make name capital
            char goBig[NAMESIZE];
            strncpy(goBig, aPet->name, NAMESIZE);
            goBig[0] = toupper(goBig[0]);
            *aPet->name = *goBig;
            //get age
            printf("What is %s's age?\n", aPet->name);
            scanf("%d", &aPet->age);
            
            aPet->nextPet = NULL;
            
        } else {
            puts("not created");
        }
        
        introducePet(&headPet, aPet);
        
    } // for incoming pets
    
    puts("Names in order: ");
    //print out
    struct pet *printPet = headPet;
    if(headPet == NULL) {
        puts("list is empty");
    } else {
        while(printPet->nextPet != NULL) {
            printf("Pet Name: %s\tage: %d\n", printPet->name, printPet->age);
            printPet = printPet->nextPet;
        }
        //one more
        printf("Pet Name: %s\tage: %d\n", printPet->name, printPet->age);
    } //print
    
    bool deleting = false;
    while(!deleting) {
        puts("would you like to remove a pet? (y or n)");
        char answer[1];
        //no validate
        scanf("%s", answer);
        answer[0] = tolower(answer[0]);
        
        if (strcmp(answer, "y")) {
            
            char remove[NAMESIZE];
            puts("which pet will you remove?");
            scanf("%s", remove);
            remove[0] = toupper(remove[0]);
            
            deletePet(&headPet, remove);
            
        } else {
            deleting = true;
        }
        
    } //while deleting
    
    return 0;
} // main function

void introducePet(struct pet **headPtr, struct pet *addMe) {
    
    if(headPtr == NULL) {
        *headPtr = addMe;
    } else {
        
        struct pet *tempPet = *headPtr;
        struct pet *lastPet = NULL;
        
        while(tempPet != NULL && (compareName(tempPet, addMe) < 0)) {
            
            lastPet = tempPet;
            tempPet = lastPet->nextPet;
            
        } //while not null and not greater
        
        if(lastPet == NULL) {//if head is null
            
            *headPtr = addMe;
            
        } else {
            
            lastPet->nextPet = addMe;
    
        }// else
        
        addMe->nextPet = tempPet;
        
    } //else
    
} //insert

void deletePet(struct pet **headPet, char removeMe[NAMESIZE]) {
    
    //vars
    struct pet *currentPet = *headPet;
    struct pet *previousPet = NULL;
    
    if (strcmp(currentPet->name, *removeMe) == 0) {
        *headPet = (*headPet)->nextPet;
        free(currentPet);
        currentPet = NULL;
    } else {
        
        while( currentPet != NULL && strcmp(currentPet->name, *removeMe) != 0) {
            previousPet = currentPet;
            currentPet = previousPet->nextPet;
        } //find it
        
        if(currentPet !=NULL) {
            previousPet->nextPet = currentPet->nextPet;
            free(currentPet);
            currentPet = NULL;
        } else {
            
            puts("this pet was not in list");
            
        }
        
    } //else not head
    
} //remove

int compareName(const struct pet *name1, const struct pet *name2) {
    
    return strcmp(name1->name, name2->name);
    
}

