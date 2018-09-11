/* CS261- Assignment 1 - Q. 0*/
/* Name: Wyatt Griffith
 * Date: 07/09/18
 * Solution description: main calls fooA and fooB using a random number between 0-10
 *                       fooA increments an integer by 5 and prints information
 *                       fooB decrements a pointer to an integer by 1 and prints information
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fooA(int* iptr){
/*Print the value and address of the integer pointed to by iptr*/
    printf("A Value: %d \n", *iptr);
    printf("Address: %p \n", iptr);
/*Increment the value of the integer pointed to by iptr by 5*/
    *iptr += 5;
/*Print the address of iptr itself*/
    printf("Pointer Address: %p \n", &iptr);
}

void fooB(int* jptr){
/*Print the value and address of the integer pointed to by jptr*/
    printf("B Value: %d \n", *jptr);
    printf("Address: %p \n", jptr);
/*Decrement jptr by 1*/
    jptr -= 1;
/*Print the address of jptr itself*/
    printf("Pointer Address: %p \n", &jptr);
}


int main(){
/*Declare an integer x and initialize it randomly to a value in [0,10]*/
    int x = rand() %11;
/*Print the value and address of x*/
    printf("X Value: %d \n", x);
    printf("Address: %p \n", &x);
/*Call fooA() with the address of x*/
    fooA(&x);
/*Print the value of x*/
    printf("X Value: %d \n", x);
/*Call fooB() with the address of x*/
    fooB(&x);
/*Print the value and address of x*/
    printf("X Value: %d \n", x);
    printf("Address: %p \n", &x);
    return 0;
}
/* I put the questions here because it looked better when I did it in Q2
* QUESTION 1: Is the value of x different than the value that was printed at first? Why or why not?
*       Yes the value of x is different, in fooA we incremented it by 5
* QUESTION 2: Are the value and address of x different than the value and address that were printed before the call to fooB(..)? Why or why not?
*       No the value of x is the same, in fooB we did nothing to x
*       Yes the address of x is different, in fooB we changed the address by changing jptr
*/
