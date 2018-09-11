/* CS261- Assignment 1 - Q.2*/
/* Name: Wyatt Griffith
 * Date: 07/08/18
 * Solution description: main calls foo using three random numbers between 0-10
 *                       foo swaps the addresses of two ints and decrements a third by 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c){
/*Swap the addresses stored in the pointer variables a and b*/
    printf("foo Values Before: \n a: %d b: %d c: %d \n", *a, *b, c);
    printf("foo Addresses Before: \n a: %p b: %p c: %p \n", a, b, &c);
    int* temp;
    temp = a;
    a = b;
    b = temp;
/*Decrement the value of integer variable c*/
    c--;
/*Return c*/
    printf("foo Values After: \n a: %d b: %d c: %d \n", *a, *b, c);
    printf("foo Addresses After: \n a: %p b: %p c: %p \n", a, b, &c);
    return c;
}

int main(){
/*Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    int x = rand() %11;
    int y = rand() %11;
    int z = rand() %11;
    int* px = &x;
    int* py = &y;
/*Print the values of x, y and z*/
    printf("Main Values Before: \n x: %d y: %d z: %d \n", x, y, z);
    printf("Main Addresses Before: \n x: %p y: %p z: %p \n", &x, &y, &z);
/*Call foo() appropriately, passing x,y,z as parameters*/
    int res = foo( px, py, z);
/*Print the values of x, y and z*/
    printf("Main Values After: \n x: %d y: %d z: %d \n", x, y, z);
    printf("Main Addresses After: \nx: %p ya: %p z: %p \n", &x, &y, &z);
/*Print the value returned by foo*/
    printf("Result: %d", res);
    return 0;
}

/* QUESTION 1:   Is the return value different than the value of integer z? Why or why not?
*          No, z gets decremented and then is returned - what I thought would happen
*          Yes it is, integer z does not actually get decremented outside of foo - what happened
*
*  QUESTION 2:  Are the values of integers x and y different before and after calling the function foo(..)? Why or why not?
*          Yes, since we swapped the addresses of a and b we swapped the addresses of x and y
*                                   and thus the values at those addresses - what I thought would happen
*           No, we only swapped the addresses of a and b not x and y so they are the same - what happened
*
* NOTE: Not sure if my code isn't working or if I had a bad idea of how scope works in C, thats why there
*       are extra prints in foo to show you that the addresses and values change but only within foo.
*       IDK if that was the lesson or if I'm doing something wrong
*/
