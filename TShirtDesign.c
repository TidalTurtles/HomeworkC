//
//  TShirtDesign.c
//  HomeworkC
//
//  This Assignment is to use the design that we created for iteration 1
//  design notebook and use it and the changes made to create code for this
//  3 step/sided project
//
//  Created by noah holt due 10/21/21.
//

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// overarching vars
#define ADMIN 81405
#define MINPRICE 10
#define MAXPRICE 50
#define MINPERCENT 0
#define MAXPERCENT 100

//prototypes
bool getPin(int correctPin); //working
double getNumber(int type, int minNum, int maxNum); //working for price and percent
char getLetter(int type); //working
bool getZip(void);
bool yesNo(void); //working

// getting started
int main(void) {
    
    //set vars
    bool user1 = getPin(ADMIN);
    double workingPrice;
    double workingPercent;
    
    //user story 3 vars
    double totalSales = 0;
    double totalAmountRaised;
    char shirtSize;
    char shirtColor;
    
    //user story 1
    while(user1) {
        
        bool priceCheck = false;
        while (!priceCheck) {
            workingPrice = getNumber(1, MINPRICE, MAXPRICE);
            printf("Is $%.2f the right price? \n", workingPrice);
            priceCheck = yesNo();
        }
        printf("Shirt price set to $%.2f", workingPrice);
        
        bool percentCheck = false;
        while(!percentCheck) {
            workingPercent = getNumber(2, MINPERCENT, MAXPERCENT) / 100;
            printf("Is %.0f the correct percentage? \n", (workingPercent * 100));
            percentCheck = yesNo();
        }
        printf("Percentage set to %s %.2f \n", "%", (workingPercent*100));
        
        //user story 3
        bool user3 = false;
        while (!user3) {
            
            bool checkSize = false;
            while(!checkSize){
                shirtSize = getLetter(1);
                printf("Is %c the correct size?\n", shirtSize);
                checkSize = yesNo();
            } //while size
            
            bool checkColor = false;
            
            if(shirtSize == 'q'){
                bool checkProgress = getPin(ADMIN);
                while(checkProgress) {
                    totalAmountRaised = totalSales * workingPercent;
                    printf("Total sales was %f\n", totalSales);
                    printf("Money made for organization is %f\n", totalAmountRaised);
                    checkProgress = false;
                }//while checking progress.
                
            } else {
                
                while(!checkColor){
                    shirtColor = getLetter(2);
                    printf("Is %c the correct color?\n", shirtColor);
                    checkColor = yesNo();
                } //while color
                
            } // if q
            
            //payment (ie zip code)
            getZip();
            totalSales += workingPrice;
            totalAmountRaised = totalSales * workingPercent;
            printf("%s\n", "Would you like a recipt");
            bool recipt = yesNo();
            
            if(recipt == true) {
                // create random number
                printf("Your shirt size was %c in the color %c\n", shirtSize, shirtColor);
                printf("The cost of the shirt will be $%.2f\n", workingPrice);
                printf("The amount towards the fundraiser will be %.2f\n", (workingPercent*100));
                printf("The fundraiser has made $%.2f so far \n", totalAmountRaised);
            }
            
            user3 = true;
            
        } //user 3
        
        user1 = false;
        
    } // user1 check
    
    printf("%s\n", "Exiting program now");
    
    return 0;
} // main


bool getPin(int correctPin) { //return whether or not pin was correct
    
    int pinNumber;
    int counter = 0;
    bool isCorrect = false;
    
    while(!isCorrect && counter != 3) {
        
        printf("%s\n", "Please enter your pin number");
        scanf("%d", &pinNumber);
        
        while((getchar()) != '\n');
        
        if(pinNumber == correctPin) {
            isCorrect =  true;
        } else {
            printf("%s\n", "invalid Pin");
        }
        counter++;
        
    } //while false
    
    return isCorrect;
} //get Pin

double getNumber(int type, int minNum,  int maxNum) {
    
    float getThis = 0;
    bool inRange = false;
    
    while( !inRange ) {
        if(type == 1) { //number type 1 price
            
            printf("%s\n", "Enter price amount from 20-50");
            scanf("%f", &getThis);
            while((getchar()) != '\n');
            
        } else if(type == 2) { // number type 2 is percent
            
            printf("%s\n", "Enter percent amount from 0-100");
            scanf("%f", &getThis);
            while((getchar()) != '\n');
            
        } //type dependent
        
        // check in range
        if(getThis >= minNum && getThis <= maxNum){
            inRange = true;
        } else {
            printf("%s\n", "Not in range please try again");
        }// check in range
    }
    return (double)getThis;
} //get Number

bool yesNo(void){
    
    char yesOrNo;
    bool needThis;
    bool getOut = false;
    
    
    while(!getOut){
        
        scanf("%c", &yesOrNo);
        while((getchar()) != '\n');
        
        if(tolower(yesOrNo) == 'y'){
            needThis = true;
            getOut = true;
        } else if(tolower(yesOrNo) == 'n') {
            needThis = false;
            getOut = true;
        } else {
            printf("%s\n", "Invalid input");
        }//if
    }//while
    
    return needThis;
}

char getLetter(int type) {
    
    char userInput;
    bool goodLetter = false;
    
    while (!goodLetter) {
        
        if(type == 1) { //type 1 for shirt size
            
            printf("%s\n", "Enter shirt size s, m, l, x");
            scanf("%c", &userInput);
            while((getchar()) != '\n');
            
            if(tolower(userInput) != 's' && tolower(userInput) != 'm' && tolower(userInput) != 'l' && tolower(userInput) != 'x' && tolower(userInput) != 'q') {
                printf("%s\n", "Invalid input");
            } else {
                goodLetter = true;
            }
            
        } else if (type == 2) { //type 2 is color
            
            printf("%s\n", "Enter shirt color wanted (B)lack or (W)hite");
            scanf("%c", &userInput);
            while((getchar()) != '\n');
            
            if(tolower(userInput) != 'b' && tolower(userInput) != 'w') {
                printf("%s\n", "Invalid input");
            } else {
                goodLetter = true;
            }
            
        }//if
        
    }
    return userInput;
    
}

bool getZip(void) {
    
    bool isValid = false;
    int zipCode;
    
    while(!isValid) {
        printf("%s", "Enter your zip to complete.");
        isValid = scanf("%5d", &zipCode);
        if (!isValid) {
            printf("%s", "Invalid zip");
        }
    } //while valid
    
    return true;
    
}
