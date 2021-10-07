//
//  A05Assignment.c
//  This assignment is to create a multidimensional array that
//  calculates grades to simulate canvas
//  Created by noah holt due 10/8/21.
//

#include <stdio.h>

#define STUDENTS 10
#define GRADES 5

#define CLASS 0.1
#define ASSIGNMENT 0.3
#define PROJECT 0.3
#define MIDTERM 0.15
#define FINAL 0.15

//prototypes
void getGrades(int grades[][GRADES], size_t pupils, size_t scores); //check
void displayGrades(const int grades[][GRADES], size_t pupils, size_t scores);//check
double finalGrades(int grades[][GRADES], size_t pupils, size_t scores); //check
void printFinals(const double finals[], size_t scores); //check
double averageGrade(const double finals[], size_t scores); // check
void displayAverage(const double average); //check

//main
int main() {
    
    int studentGrades[STUDENTS][GRADES];
    getGrades(studentGrades, STUDENTS, GRADES);
    displayGrades(studentGrades, STUDENTS, GRADES);
    printf("\n");
    double finalGrade[STUDENTS];
    for(size_t i = 0; i < STUDENTS; i++) {
        finalGrade[i] = finalGrades(studentGrades, i, GRADES);
    }
    printFinals(finalGrade, STUDENTS);
    double studentAverage = averageGrade(finalGrade, STUDENTS);
    displayAverage(studentAverage);
    
    return 0;
}

//get grades
void getGrades(int grades[][GRADES], size_t pupils, size_t scores){
    
    for(unsigned i = 0; i < pupils; i++) {
        
        printf("%s%u\n", "Enter Grades for Sturdent ", i+1);
        for(unsigned j = 0; j < scores; j++) {
            printf("%s%u\t", "Enter grade ", j+1);
            scanf("%d", &grades[i][j]);
        }
        
    }
    
}

//display grades table
void displayGrades(const int grades[][GRADES], size_t pupils, size_t scores) {
    
    for (unsigned i = 0; i < pupils; i++) {
        printf("%s%u\n", "Student ", i+1);
        for (unsigned j = 0; j < scores; j++) {
            printf("%d\t", grades[i][j]);
        }
        printf("\n");
    }
    
}


//calculate final grades
double finalGrades(int grades[][GRADES], size_t pupils, size_t scores) {
    
    double final = 0;
    for (size_t i = 0; i < scores; i++) {
        switch (i) {
            case 0:
                final += grades[pupils][i] * CLASS;
                break;
            case 1:
                final += grades[pupils][i] * ASSIGNMENT;
                break;
            case 2:
                final += grades[pupils][i] * PROJECT;
                break;
            case 3:
                final += grades[pupils][i] * MIDTERM;
                break;
            case 4:
                final += grades[pupils][i] * FINAL;
                break;
            default:
                break;
        }
    }
    return final;
    
}

//print display
void printFinals(const double finals[], size_t scores) {
    
    printf("%s\n", "Final Grades");
    for(size_t i = 0; i < scores; i++) {
        printf("%.1f\t", finals[i]);
    }
    printf("\n\n");
    
}

//calc average
double averageGrade(const double finals[], size_t scores) {
    
    double average = 0;
    
    for(unsigned i = 0; i < scores; i++) {
        average += finals[i];
    }
    average = average/scores;
    return average;
    
}

//display average
void displayAverage(const double average) {
    
    printf("%s\n", "Average Grade for this Class");
    printf("%.1f\n", average);
    printf("\n");
    
}

