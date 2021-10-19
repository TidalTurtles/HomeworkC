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
char getLetter(int type);
bool getZip(int zipCode);
bool yesNo(void); //working

// getting started
int main(void) {
    
    //set vars
    bool user1 = getPin(ADMIN);
    double workingPrice;
    double workingPercent;
    
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
        printf("Percentage set to %s %.2f \n", "%", workingPercent);
        
        user1 = false;
        
    } // user1 check
    
    printf("%s\n", "Exiting program now");
    
    //user story 3 vars
    double totalSales = 0;
    double totalAmountRaised = totalSales * workingPercent;
    
    //user story 3
    
    
    return 0;
}

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
            printf("%s", "Invalid input");
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
            
        } else if (type == 2) { //type 2 is color
            
            printf("%s\n", "Enter shirt color wanted (B)lack or (W)hite");
            scanf("%c", &userInput);
            while((getchar()) != '\n');
            
        } else { //you're wrong
            printf("%s\n", "Invalid input");
        }//if
    }
    return 'c';
    
}
