 /**********************************************************************
 * Name: Wyatt Griffith
 * Email: griffiwy@oregonstate.edu
 * Date: 07/23/18
 * Description: This file contains two structs, Link and LinkedList
 *      Link is  a struct that points to other Links that build 
 *      the LinkedList struct.LinkedList has functions for creating,
 *      destroying, adding to, removing from, and accessing elements 
 *      of the LinkedList. It is a doubly linked list with two sentinels
 **********************************************************************/

#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Double link
struct Link{
	TYPE value;
	struct Link* next;
	struct Link* prev;
};

// Double linked list with front and back sentinels
struct LinkedList{
	int size;
	struct Link* frontSentinel;
	struct Link* backSentinel;
};
/*******************************************************************
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinels' next and prev should point to eachother or NULL
 * as appropriate.
 *******************************************************************/
static void init(struct LinkedList* list) {
	list->size = 0;
	list->frontSentinel = (struct Link *) malloc(sizeof(struct Link));
	assert(list->frontSentinel != 0);
	list->backSentinel = (struct Link *) malloc(sizeof(struct Link));
	assert(list->backSentinel);
	list->frontSentinel->prev = NULL;
	list->frontSentinel->next = list->backSentinel;
	list->backSentinel->prev = list->frontSentinel;
	list->backSentinel->next = NULL;
}

/*******************************************************************
 * Adds a new link with the given value before the given link and
 * increments the list's size.
 *******************************************************************/
static void addLinkBefore(struct LinkedList* list, struct Link* link, TYPE value){
	struct Link *newNode= (struct Link *) malloc(sizeof(struct Link));
	assert(newNode != NULL);
	newNode->value = value;
	newNode->prev = link->prev;
	newNode->next = link;
	link->prev->next = newNode;
	link->prev = newNode;
	list->size++;
}

/*******************************************************************
 * Removes the given link from the list and
 * decrements the list's size.
 *******************************************************************/
static void removeLink(struct LinkedList* list, struct Link* link){
	assert(!linkedListIsEmpty(list));
	link->next->prev = link->prev;
	link->prev->next = link->next;
	list->size--;
}

/*******************************************************************
 * Allocates and initializes a list.
 *******************************************************************/
struct LinkedList* linkedListCreate(){
	struct LinkedList* newDeque = malloc(sizeof(struct LinkedList));
	init(newDeque);
	return newDeque;
}

/*******************************************************************
 * Deallocates every link in the list including the sentinels,
 * and frees the list itself.
 *******************************************************************/
void linkedListDestroy(struct LinkedList* list){
	while (!linkedListIsEmpty(list)){
		linkedListRemoveFront(list);
	}
	free(list->frontSentinel);
	free(list->backSentinel);
	free(list);
}

/*******************************************************************
 * Adds a new link with the given value to the front of the deque.
 *******************************************************************/
void linkedListAddFront(struct LinkedList* list, TYPE value){
	addLinkBefore(list, list->frontSentinel->next, value);
}

/*******************************************************************
 * Adds a new link with the given value to the back of the deque.
 *******************************************************************/
void linkedListAddBack(struct LinkedList* list, TYPE value){
	addLinkBefore(list, list->backSentinel, value);
}

/*******************************************************************
 * Returns the value of the link at the front of the deque.
 *******************************************************************/
TYPE linkedListFront(struct LinkedList* list){
	return list->frontSentinel->next->value;
}

/*******************************************************************
 * Returns the value of the link at the back of the deque.
 *******************************************************************/
TYPE linkedListBack(struct LinkedList* list){
	return list->backSentinel->prev->value;
}

/*******************************************************************
 * Removes the link at the front of the deque.
 *******************************************************************/
void linkedListRemoveFront(struct LinkedList* list){
	removeLink(list, list->frontSentinel->next);
}

/*******************************************************************
 * Removes the link at the back of the deque.
 *******************************************************************/
void linkedListRemoveBack(struct LinkedList* list){
	removeLink(list, list->backSentinel->prev);
}

/*******************************************************************
 * Returns 1 if the deque is empty and 0 otherwise.
 *******************************************************************/
int linkedListIsEmpty(struct LinkedList* list){
	if(list->size == 0)
		return 1;
	else
		return 0;
}

/*******************************************************************
 * Prints the values of the links in the deque from front to back.
 *******************************************************************/
void linkedListPrint(struct LinkedList* list){
	struct Link *curr = list->frontSentinel->next;
	while(curr != list->backSentinel){
		printf("%i \n", curr->value);
		curr = curr->next;
	}
}

/*******************************************************************
 * Adds a link with the given value to the bag.
 *******************************************************************/
void linkedListAdd(struct LinkedList* list, TYPE value){
	addLinkBefore(list, list->backSentinel, value);
}

/*******************************************************************
 * Returns 1 if a link with the value is in the bag and 0 otherwise.
 *******************************************************************/
int linkedListContains(struct LinkedList* list, TYPE value){
	struct Link *curr = list->frontSentinel;
	while(curr->next != NULL){
		if(curr->value == value)
			return 1;
		curr = curr->next;
	}
	return 0;
}

/*******************************************************************
 * Removes the first occurrence of a link with the given value.
 ******************************************************************/
void linkedListRemove(struct LinkedList* list, TYPE value){
	assert(!linkedListIsEmpty(list));
	struct Link *curr = list->frontSentinel;
	while(curr->next != NULL){
		if(curr->value == value){
			curr->next->prev = curr->prev;
			curr->prev->next = curr->next;
			list->size--;
			return;
		}
		curr = curr->next;
	}
}
