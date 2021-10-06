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
void displayGrades(const int grades[][GRADES], size_t pupils, size_t scores);
double finalGrades(int grades[][GRADES], size_t pupils, size_t scores);
void printFinals(const double finals[], size_t scores); //check
double averageGrade(const double finals[], size_t scores); // check
void displayAverage(const double average); //check

//main
int main() {
    
    //int studentGrades[STUDENTS][GRADES];
    double finals[] = {55.5, 77.6, 89.3, 99, 61.4, 87.6, 55, 89, 92.7, 78.54};
    printFinals(finals, STUDENTS);
    double studentAverage = averageGrade(finals, STUDENTS);
    displayAverage(studentAverage);
    
    return 0;
}

//get grades
void getGrades(int grades[][GRADES], size_t pupils, size_t scores){
    
    
    
}

//display grades table



//calculate final grades



//display final grades table



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

