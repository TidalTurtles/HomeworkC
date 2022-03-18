//
//  main.c
//  Assignment6
//  We are creating a mad lib of sorts this
//  assignment by creating String arrays of
//  different word types and then combining them
//  together and printing to a file.
//  Created by noah holt due 11/5/21.
//
// starting with included studios to use
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

//define the size
#define SIZE 5

//maybe some function prototypes
int pickRandomNumber(int length);

int main(void) {
    // insert code here...
    //lets start easy and make the pointer arrays
    //articles
    char *artiPtr[SIZE] = {"the", "a", "one", "some", "any"};
    //nouns
    char *nounPtr[SIZE] = {"baby", "bunny", "dog", "town", "car"};
    //verbs
    char *verbPtr[SIZE] = {"drove", "jumped", "ran", "walked", "skipped"};
    //prepositions
    char *prepPtr[SIZE] = {"to", "from", "over", "under", "on"};
    //simple enough to start
    
    //make regular char array to conver to upper
    //only five because mak article is 4 letters
    char first[SIZE];
    
    
    //opening file up
    FILE *randomSentence;
    
    //set seed get random
    srand(time(NULL));
    int randomNum;
    
    //sentice structure is Arti, noun, verb, prep, arti, noun
    
    //start if opens
    if((randomSentence = fopen("/Users/noahholt/Desktop/Coding/C/CS2060/Assignment6/Assignment6/randomSentence.txt", "w")) == NULL) {
        puts("File couldnot be opened");
    } else {
        
        //loop it 20 times now (made after sentence creation worked
        int count = 0;
        while(count < 20) {
        //get first word: article
            int firstWord = rand() % SIZE;
            strncpy(first, artiPtr[firstWord], SIZE);
            first[0] = toupper(first[0]);
            fputs(first, randomSentence);
            fputs(" ", randomSentence);
            
            //second word: noun
            int secondWord = rand() % SIZE;
            fputs(nounPtr[secondWord], randomSentence);
            fputs(" ", randomSentence);
            
            //third word: verb
            int thirdWord = rand() % SIZE;
            fputs(verbPtr[thirdWord], randomSentence);
            fputs(" ", randomSentence);
            
            //fourth word: prep
            int fourthWord = rand() % SIZE;
            fputs(prepPtr[fourthWord], randomSentence);
            fputs(" ", randomSentence);
            
            //fifth word: arti2
            int fifthWord = rand() % SIZE;
            fputs(artiPtr[fifthWord], randomSentence);
            fputs(" ", randomSentence);
            
            //final word: noun
            int lastWord = rand() % SIZE;
            fputs(nounPtr[lastWord], randomSentence);
            fputs(".", randomSentence);
            fputs("\n", randomSentence);
            
            count++;
            
        } // for 20 times
        
    } //else make .txt doc
    
    //close the file
    fclose(randomSentence);
    
    return 0;
}

/*int pickRandomNumber(int length) {
    
    //set the seed and init var
    //hey, I am on a mac w/ xcode and it gives me a little yellow warning
    //for srand. Do you know why? I ignore it and it works but it is adgitating is all.
    srand(time(NULL));
    int randomNum;
    
    //now pick random
    randomNum = rand() % length;
    //all done
    return randomNum;
    
} //pick random number
 */

//weird so i tried to use this function for the random numbers for practice
//making functions and prototypes but it made all the sentences the exact same
// dont know why but that is what happens, if you would like to try and see

