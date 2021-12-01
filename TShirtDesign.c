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
#include <string.h>

// overarching vars
#define ADMIN 81405
#define MINPRICE 20
#define MAXPRICE 50
#define MINPERCENT 5
#define MAXPERCENT 20
#define NAMESIZE 20

//iteration 3 part 3: structure
typedef struct fundOrg {
    char orgName[NAMESIZE];
    double orgPrice;
    double orgPercent;
    struct fundOrg *nextOrg;
} FundOrg;

//prototypes
bool getPin(int correctPin); //working //corrections made
double getNumber(int type, int minNum, int maxNum); //working for price and percent //corrections made
char getLetter(int type); //working // corrections made
bool getZip(void); //working //now don't need
bool yesNo(void); //working // no corrections needed
bool getCardNum(void);
bool validateFloat(char *buff, double *makeMe);
//iteration 3 prototypes (ie for linked list)
void insertOrg(FundOrg **headPtr, FundOrg *addMe);
void removeOrg(FundOrg **headPtr, char *removeMe[NAMESIZE]);
int compareName(FundOrg *firstOrg, FundOrg *secondOrg);


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
    struct fundOrg *headOrg = NULL;
    
    //if alread a file read in sales amounts
    
    /* Not needed for iteration 3
    if((tShirtFunds = fopen("/Users/noahholt/Desktop/Coding/C/CS2060/Homework1/Homework1/tshirtfunds.txt", "r")) == NULL) {
        puts("File could not be read or does not exist");
    } else {
        fscanf(tShirtFunds, "%lf", &totalSales);
        fscanf(tShirtFunds, "%lf", &totalAmountRaised);
    }
    
    fclose(tShirtFunds);
    */
    
    
    //user story 1
    while(user1) {
        
        bool makingOrgs = true;
        
        while(makingOrgs) {
            
            struct fundOrg *makingOrg = NULL;
            makingOrg = malloc(sizeof(struct fundOrg));
            double aPrice;
            double aPercent;
            
            puts("what is this organizations name?");
            fgets(makingOrg->orgName, 19, stdin);
            
            bool priceCheck = false;
            while (!priceCheck) {
                aPrice = getNumber(1, MINPRICE, MAXPRICE);
                printf("Is $%.2f the right price? \n", aPrice);
                priceCheck = yesNo();
            }
            printf("Shirt price set to $%.2f\n", aPrice);
            
            bool percentCheck = false;
            while(!percentCheck) {
                aPercent = getNumber(2, MINPERCENT, MAXPERCENT) / 100;
                printf("Is %.2f the correct percentage? \n", (aPercent * 100));
                percentCheck = yesNo();
            }
            printf("Percentage set to %s %.2f \n", "%", (aPercent*100));
            
            makingOrg->orgPrice = aPrice;
            makingOrg->orgPercent = aPercent;
            
            insertOrg(&headOrg, makingOrg);
            
            puts("Will you make another orginization?");
            makingOrgs = yesNo();
            
        } //while setting orgs
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
                        fprintf(tShirtFunds, "%15s\t%.2lf\n", "Sales", totalSales);
                        fprintf(tShirtFunds, "%15s\t%.2lf\n", "amount raised", totalAmountRaised);
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
                //while((getchar()) != '\n');
                
                checkInput = validateFloat(readIn, getThisPtr);
                
            }
                        
        } else if(type == 2) { // number type 2 is percent
            
            bool checkInput = false;
            while (!checkInput) {
                printf("%s\n", "Enter percent amount from 5-20 (format ##.##)");
                fgets(readIn, 6, stdin);
                //while((getchar()) != '\n');
                
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
    bool checking = true;
    char fullCard[20];
    char *checkMe;
    double cardNum = 0;
    int counter = 0;
    
    
    while(!isValid) {
        
        //clear buffers if existed
        
        
        puts("Enter your credit card number (####-####-####-####)");
        fgets(fullCard, 20, stdin);
        
        //proper numbers
        while (checking) {
            //for each number
            for (size_t i = 0; i < 4; i++) {
                checkMe = strtok(fullCard, "-");
                checking = validateFloat(checkMe, &cardNum);
                if (!checking) {
                    counter++;
                } //if true
            } //for all numbers
            
            //if false occured counter is not 0
            if(counter == 0) {
                isValid = true;
            }
            //exit loop
            checking = false;
            
        } // while checking
        
        if(isValid == false) {
            puts("Invalid card number");
        } //if incorrect
        
    } //while not valid
    
    return isValid; //place holder
    
} //card number

bool validateFloat(char *buff, double *makeMe) { //also add double pointer
    
    bool isValid = false;
    
    //from example
    errno = 0;
    char *end;
    
    if(buff[strlen(buff)-1] == '\n') {
        buff[strlen(buff)-1] = '\0';
    }
    
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

//iteration 3
//linked list functions

void insertOrg(FundOrg **headPtr, FundOrg *addMe) {
    
    if(headPtr == NULL) { //nothing in list
        *headPtr = addMe;
    } else {
        
        //place holder values
        FundOrg *currentOrg = *headPtr;
        FundOrg *previousOrg = NULL;
        
        while (currentOrg != NULL && (compareName(currentOrg, addMe)) < 0) {
            previousOrg = currentOrg;
            currentOrg = previousOrg->nextOrg;
        } //while finding spot
        
        if(previousOrg == NULL) {//if placing at head
            
            *headPtr = addMe;
            
        } else { 
            
            previousOrg->nextOrg = addMe;
    
        }// else put in spot
        
        //connect rest of list
        addMe->nextOrg = currentOrg;
        
    } //else find a spot
    
} //insert org

void removeOrg(FundOrg **headPtr, char *removeMe[NAMESIZE]) {
    
    //temp values
    FundOrg *currentOrg = *headPtr;
    FundOrg *previousOrg = NULL;
    
    if(strcmp(*currentOrg->orgName, *removeMe) == 0) { //if removing head
        *headPtr = (*headPtr)->nextOrg;
        free(currentOrg);
        currentOrg = NULL;
    } else {
        
        while(currentOrg != NULL && strcmp(*currentOrg->orgName, *removeMe) != 0) {
            previousOrg = currentOrg;
            currentOrg = previousOrg->nextOrg;
        } //while searching
        
        if(currentOrg != NULL) { //if deleting this one
            previousOrg->nextOrg = currentOrg->nextOrg;
            free(currentOrg);
            currentOrg = NULL;
        } else {
            puts("Org not in list");
        } //not here
        
    } //else not head
    
    
} //remove org

int compareName(FundOrg *firstOrg, FundOrg *secondOrg) {
    
    return strcmp(firstOrg->orgName, secondOrg->orgName);
    
} //compareitor
