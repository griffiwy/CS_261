/* CS261- Assignment 1 - Q.1*/
/* Name: Wyatt Griffith
 * Date: 07/09/18
 * Solution description: main creates an array and a pointer and points it to the array
 *                       then main calls allocate, generate, output, summary and deallocate
 *                       allocate and deallocate allocate and free memory for the array
 *                       generate fills the array with 10 students with random ids and scores
 *                       output prints all of the students ids and scores
 *                       summary calculates and prints the min, max, and avg scores
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
    int id;
    int score;
};


struct student* allocate(){
/*Allocate memory for ten students*/
    void* mem_block = malloc(sizeof(int)*20);
/*Return the pointer*/
    return mem_block;
}

void generate(struct student* students){
/* Generate Random and Unique ids between 1 and 10*/
/* Initialize Variables */
    int shufArray[11];
    int temp = 0;
    int j = 0;

/* Make an array of possible id numbers */
    for(int i = 1; i < 11; i++){
        shufArray[i-1] = i;
    }
/* Using Fisher Yates Shuffle to randomize the array */
    for(int i = 9; i > 0; i--){
        j = rand() %i;
        temp = shufArray[j];
        shufArray[j] = shufArray[i];
        shufArray[i] = temp;
    }

/* Generate 10 students and assign them ids */
/* Generate random scores between 0 and 100 */
    struct student one;
    one.id = shufArray[0];
    one.score = rand() %101;
    struct student two;
    two.id = shufArray[1];
    two.score = rand() %101;
    struct student three;
    three.id = shufArray[2];
    three.score = rand() %101;
    struct student four;
    four.id = shufArray[3];
    four.score = rand() %101;
    struct student five;
    five.id = shufArray[4];
    five.score = rand() %101;
    struct student six;
    six.id = shufArray[5];
    six.score = rand() %101;
    struct student seven;
    seven.id = shufArray[6];
    seven.score = rand() %101;
    struct student eight;
    eight.id = shufArray[7];
    eight.score = rand() %101;
    struct student nine;
    nine.id = shufArray[8];
    nine.score = rand() %101;
    struct student ten;
    ten.id = shufArray[9];
    ten.score = rand() %101;

/* Put the students in the students array */
    students[0] = one;
    students[1] = two;
    students[2] = three;
    students[3] = four;
    students[4] = five;
    students[5] = six;
    students[6] = seven;
    students[7] = eight;
    students[8] = nine;
    students[9] = ten;
}

void output(struct student* students){
/*Output information about the ten students */
    for(int i = 0; i < 10; i++){
        printf("ID: %i    Score: %i \n", students[i].id, students[i].score);
    }
}

void summary(struct student* students){
/*Compute  min, max and avg scores of the ten students*/
    int min = students[0].score;
    int max = students[0].score;
    int avg = students[0].score;
    for(int i = 1; i < 10; i++){
        if(students[i].score > max)
            max = students[i].score;
        if(students[i].score < min)
            min = students[i].score;
        avg = avg + students[i].score;
    }
    avg = avg/10;
/* Print the min, max and avg scores */
    printf("Min: %i   Max: %i   Avg: %i \n", min, max, avg);
}

void deallocate(struct student* stud){
/*Deallocate memory from stud*/
    if(stud != NULL)
        free(stud);
}

int main(){
/*Define the pointer and array*/
    struct student* stud = NULL;
    struct student myArray[10];
    stud = myArray;
/*Call allocate*/
    stud = allocate();
/*Call generate*/
    generate(stud);
/*Call output*/
    output(stud);
/*Call summary*/
    summary(stud);
/*Call deallocate*/
    deallocate(stud);
    return 0;
}
