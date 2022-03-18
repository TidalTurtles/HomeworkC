//
//  A04.c
//  Homework1
//  starting from the end of A04 we are going to start coding it
//  Created by noah holt on 9/21/21.
// maybe try to recreate this and modualize it.

#include <stdio.h>
#include <stdbool.h>


int main(void) {
    
    //initialize vars
    int numCars = 0;
    int numHrs = 0;
    int totalHrs = 0;
    double amountCharged = 0;
    bool isValid = false;
    
    //start asking for inputs
    while (numHrs != -1) {
        
        printf("Enter the number of hours the car was parked or -1 to finish");
        isValid = scanf("%d", &numHrs);
        //clear input buffer
        while((getchar()) != '\n');
        //check is valid is true now
        while(isValid != 1) {
            
            printf("%s", "Improper entry, enter the number of hours or -1 to finish");
            isValid = scanf("%d", &numHrs);
            
        }
        //also check for nums less than -1
        while(numHrs < -1) {
            
            printf("%s", "Improper entry, enter the number of hours or -1 to finish");
            isValid = scanf("%d", &numHrs);
            
        } //answer whould now be valid
        
        //putting charges here because doesnt make sense else where
        if(numHrs <=3 && numHrs > 0) {
            amountCharged += 2.00;
        } else if (numHrs > 3 && numHrs <= 19) {
            int toCharge = numHrs - 3;
            amountCharged = 2.00 + (double)toCharge*0.50;
        }
        
        //tally up the hours and number of cars
        totalHrs += numHrs;
        numCars++;
        
    } //while not done with cars
    //correct hours for the final value of -1
    totalHrs = totalHrs + 1;
    
    //testing
    //dont forget main returns int
    return 0;
} //main
