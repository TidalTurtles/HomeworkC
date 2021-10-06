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
void getGrades(int grades[][GRADES], size_t pupils, size_t scores);
void displayGrades(int grades[][GRADES], size_t pupils, size_t scores);
double finalGrades(int grades[][GRADES], size_t pupils, size_t scores);
void printFinals(double finals[], size_t scores);
double averageGrade(double finals[], size_t scores);
void displayAverage(double average);

//main
int main() {
    
    //int studentGrades[STUDENTS][GRADES];
    double finals[] = {55.5, 77.6, 89.3, 99, 61.4};
    double studentAverage = averageGrade(finals, 5);
    displayAverage(studentAverage);
    
    return 0;
}

//get grades



//display grades table



//calculate final grades



//display final grades table



//print display



//calc average
double averageGrade(double finals[], size_t scores) {
    
    double average = 0;
    
    for(unsigned i = 0; i < scores; i++) {
        average += finals[i];
    }
    average = average/scores;
    return average;
    
}

//display average
void displayAverage(double average) {
    
    printf("%.1f\n", average);
    
}

