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
#include <time.h>
#include <stdlib.h>
#include <float.h>
#include <errno.h>

// overarching vars
#define ADMIN 81405
#define MINPRICE 20
#define MAXPRICE 50
#define MINPERCENT 5
#define MAXPERCENT 20

//prototypes
bool getPin(int correctPin); //working //corrections made
double getNumber(int type, int minNum, int maxNum); //working for price and percent //corrections made
char getLetter(int type); //working // corrections made
bool getZip(void); //working //now don't need
bool yesNo(void); //working // no corrections needed
bool getCardNum(void);
bool validateFloat(const char *buff, double *makeMe);

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
    
    //NEW: file for receipt
    FILE *receiptFile;
    FILE *tShirtFunds;
    
    //if alread a file read in sales amounts
    char *blank = "filler";
    if((tShirtFunds = fopen("/Users/noahholt/Desktop/Coding/C/CS2060/Homework1/Homework1/tshirtfunds.txt", "r")) == NULL) {
        puts("File could not be read or does not exist");
    } else {
        fscanf(tShirtFunds, "%s%lf", blank, &totalSales);
        fscanf(tShirtFunds, "%s%lf", blank, &totalAmountRaised);
    }
    
    fclose(tShirtFunds);
    
    
    //user story 1
    while(user1) {
        
        bool priceCheck = false;
        while (!priceCheck) {
            workingPrice = getNumber(1, MINPRICE, MAXPRICE);
            printf("Is $%.2f the right price? \n", workingPrice);
            priceCheck = yesNo();
        }
        printf("Shirt price set to $%.2f\n", workingPrice);
        
        bool percentCheck = false;
        while(!percentCheck) {
            workingPercent = getNumber(2, MINPERCENT, MAXPERCENT) / 100;
            printf("Is %.2f the correct percentage? \n", (workingPercent * 100));
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
                    if((tShirtFunds = fopen("/Users/noahholt/Desktop/Coding/C/CS2060/Homework1/Homework1/tshirtfunds.txt", "w")) == NULL) {
                        puts("File could not be opened");
                    } else {
                        fprintf(tShirtFunds, "Total sales was %.2f\n", totalSales);
                        fprintf(tShirtFunds, "Money made for organization is %.2f\n", totalAmountRaised);
                    }
                    
                    //close files
                    fclose(tShirtFunds);
                    
                    
                    checkProgress = false;
                    user3 = true;
                    
                }//while checking progress.
                
            } else {
                
                while(!checkColor){
                    shirtColor = getLetter(2);
                    printf("Is %c the correct color?\n", shirtColor);
                    checkColor = yesNo();
                } //while color
                
                //payment (ie zip code)
                getCardNum();
                totalSales += workingPrice;
                totalAmountRaised = totalSales * workingPercent;
                printf("%s\n", "Would you like a recipt?");
                bool recipt = yesNo();
                
                if(recipt == true) {
                    srand(time(NULL));
                    int order = rand();
                    
                    if((receiptFile = fopen("/Users/noahholt/Desktop/Coding/C/CS2060/Homework1/Homework1/receipt.txt", "w")) == NULL) {
                        puts("File could not be opened");
                    } else {
                        fprintf(receiptFile, "Order Number: %d\n", order);
                        fprintf(receiptFile, "Your shirt size was %c in the color %c\n", shirtSize, shirtColor);
                        fprintf(receiptFile, "The cost of the shirt will be $%.2f\n", workingPrice);
                        fprintf(receiptFile, "The amount towards the fundraiser will be %.2f\n", (workingPercent*100));
                        fprintf(receiptFile, "The fundraiser has made $%.2f so far \n", totalAmountRaised);
                        fprintf(receiptFile, "\n"); //new line to seperate orders
                    }
                    
                    fclose(receiptFile);
                    
                }
                
                printf("%s", "Would you like to order another?");
                bool keepGoing = yesNo();
                if(keepGoing == false) {
                    user3 = true;
                }// if continue
                
            } // if q
            
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
    
    while(!isCorrect && counter != 4) {
        
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
    
    double getThis = 0;
    char readIn[6]; //six in case of 25.25
    bool inRange = false;
    double *getThisPtr = &getThis;
    
    while( !inRange ) {
        if(type == 1) { //number type 1 price
                        
            bool checkInput = false;
            while(!checkInput) {
                printf("%s\n", "Enter price amount from 20-50 (format ##.##)");
                fgets(readIn, 6, stdin);
                while((getchar()) != '\n');
                
                checkInput = validateFloat(readIn, getThisPtr);
                
            }
                        
        } else if(type == 2) { // number type 2 is percent
            
            bool checkInput = false;
            while (!checkInput) {
                printf("%s\n", "Enter percent amount from 5-20 (format ##.##)");
                fgets(readIn, 6, stdin);
                while((getchar()) != '\n');
                
                checkInput = validateFloat(readIn, getThisPtr);
                
            }
            
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
} //yesNO

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
            
            printf("%s\n", "Enter shirt color wanted Blac(k), (W)hite, (R)ed, (B)lue, or (P)urple ");
            scanf("%c", &userInput);
            while((getchar()) != '\n');
            
            if(tolower(userInput) != 'b' && tolower(userInput) != 'w' && tolower(userInput) != 'k' && tolower(userInput) != 'r' &&tolower(userInput) != 'p') {
                printf("%s\n", "Invalid input");
            } else {
                goodLetter = true;
            } //if else make lower case
            
        }//if for type
        
    } //while not good letters
    return userInput;
    
} //get letters

bool getZip(void) {
    
    bool isValid = false;
    int zipCode;
    
    while(!isValid){
        printf("%s\n", "Enter your zip code:");
        scanf("%d", &zipCode);
        while((getchar()) != '\n');
        
        if(zipCode < 10000 || zipCode > 99999) {
            printf("%s\n", "Invalid zip");
        } else {
            isValid = true;
        } // if else
        
    } //while not valid
    return isValid;
    
} // get zip

bool getCardNum(void) {
    
    bool isValid = false;
    int cardNum1[5];
    int cardNum2[5];
    int cardNum3[5];
    int cardNum4[5];
    
    while(!isValid) {
        
        puts("Enter your credit card number (####-####-####-####)");
        isValid = scanf("%4d*c%4d*c%4d*c%4d", cardNum1, cardNum2, cardNum3, cardNum4);
        while((getchar()) != '\n');
        
        if(isValid == false) {
            puts("Invalid card number");
        } //if incorrect
        
    } //while not valid
    
    return isValid; //place holder
    
} //card number

bool validateFloat(const char *buff, double *makeMe) { //also add double pointer
    
    bool isValid = false;
    
    //from example
    errno = 0;
    char *end;
    double doubleTest = strtod(buff, &end);
    
    if(end == buff) {
        printf("%s: not a number\n:", buff);
    } else if('\0' != *end) {
        printf("%s; extra characters at end of input: %s\n", buff, end);
    } else if((DBL_MAX == doubleTest || DBL_MIN == doubleTest) && ERANGE == errno) {
        printf("%s out of range of type double\n", buff);
    } else {
        *makeMe = doubleTest;
        isValid = true;
    }
    
    return isValid;
    
} //validate float
