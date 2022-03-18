
// Practice working with strings and writing to a file
// #1 implement code that will write to a file and test it
// #2 initialize variables and seed random number generator
// #3 create random number and test it
// #4 Use strncpy to copy the random suit chosen into the suit array
// #5 capitalize the first letter

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 10
#define NUMBER 20

int main(void)
{ 
	// #1 create file pointer
    FILE *printSuits;
    
    
    
	// #2 create an array of pointers called suitPtr
	// to hold the strings for the suits hearts diamonds clubs and spades  
    char *suitsPtr[4] = {"hearts", "diamonds", "clubs", "spades"};
	//#2initialize a character array called suit of length 10
    char suit[10];
	// #2initalize an integer randNum to hold a random number
    //set the seed
    srand(time(NULL));
    //get the random number between 0 and 3 by making it a mod
    int randNum;
	
	//#1 create a file randomSuit.txt. 
	//#1 Exit program if unable to create file 
    if((printSuits = fopen("/Users/noahholt/Desktop/Coding/C/CS2060/classwork7/classwork7/randomSuit.txt", "w")) == NULL) {
        puts("File could not be opened");
    } else {    // else  do the following
            //loop 20 times to randomly choose a suit
        for(size_t i = 0; i < 20; i++) {
            
            //#3 assign the randNum to a random number between 0 and 3
            randNum  = rand() % 4;
            //#4 use strncopy to copy the random suit into the suit array
            strncpy(suit, suitsPtr[randNum], 10);
            //#5 capitalize first letter of the string in suit array
            char replace = toupper(suit[0]);
            suit[0] = replace;
            
            //write suit to the file using fputs
            fputs(suit, printSuits);
            // write newline to the file using fputs
            fputs("\n", printSuits);
            
        }//for loop
        
    } //else section
	  
    // #1 close the file
    fclose(printSuits);
	
} 



