 /********************************************************************
 * Name: Wyatt Griffith
 * Email: griffiwy@oregonstate.edu
 * Date: 07/23/18
 * Description: This file contains two structs, Link and circularList
 *      Link is a struct that points to other links and builds
 *      the circularList struct. circularList has methods for creating,
 *      destroying, printing, reversing, adding links to, removing
 *      links from, and accessing elements in the list
 *      It is a circular doubly linked list with one sentinel
 ********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

// Circular list with sentinel
struct CircularList{
	int size;
	struct Link* sentinel;
};

/********************************************************************
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 ********************************************************************/
static void init(struct CircularList* list){
	list->sentinel = (struct Link *) malloc(sizeof(struct Link));
	assert(list->sentinel != NULL);
	list->sentinel->next = list->sentinel;
	list->sentinel->prev = list->sentinel;
	list->size = 0;
}

/*********************************************************************
 * Creates a link with the given value and NULL next and prev pointers.
 ********************************************************************/
static struct Link* createLink(TYPE value){
	struct Link *newNode = (struct Link *) malloc(sizeof(struct Link));
	newNode->value = value;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

/*********************************************************************
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 ********************************************************************/
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value){
	struct Link *newNode = createLink(value);
	newNode->prev = link;
	newNode->next = link->next;
	link->next->prev = newNode;
	link->next = newNode;
	list->size++;
}

/*********************************************************************
 * Removes the given link from the list and
 * decrements the list's size.
 ********************************************************************/
static void removeLink(struct CircularList* list, struct Link* link){
	assert(!circularListIsEmpty(list));
	link->next->prev = link->prev;
	link->prev->next = link->next;
	list->size--;
}

/*********************************************************************
 * Allocates and initializes a list.
 ********************************************************************/
struct CircularList* circularListCreate(){
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/*********************************************************************
 * Deallocates every link in the list and frees the list pointer.
 ********************************************************************/
void circularListDestroy(struct CircularList* list){
	while (!circularListIsEmpty(list)){
		circularListRemoveFront(list);
	}
	free(list->sentinel);
	free(list);
}

/*********************************************************************
 * Adds a new link with the given value to the front of the deque.
 ********************************************************************/
void circularListAddFront(struct CircularList* list, TYPE value){
	addLinkAfter(list, list->sentinel, value);
}

/*********************************************************************
 * Adds a new link with the given value to the back of the deque.
 ********************************************************************/
void circularListAddBack(struct CircularList* list, TYPE value){
	addLinkAfter(list, list->sentinel->prev, value);
}

/*********************************************************************
 * Returns the value of the link at the front of the deque.
 ********************************************************************/
TYPE circularListFront(struct CircularList* list){
	return list->sentinel->next->value;
}

/*********************************************************************
 * Returns the value of the link at the back of the deque.
 ********************************************************************/
TYPE circularListBack(struct CircularList* list){
	return list->sentinel->prev->value;
}

/*********************************************************************
 * Removes the link at the front of the deque.
 ********************************************************************/
void circularListRemoveFront(struct CircularList* list){
	removeLink(list, list->sentinel->next);
}

/*********************************************************************
 * Removes the link at the back of the deque.
 ********************************************************************/
void circularListRemoveBack(struct CircularList* list){
	removeLink(list, list->sentinel->prev);
}

/*********************************************************************
 * Returns 1 if the deque is empty and 0 otherwise.
 ********************************************************************/
int circularListIsEmpty(struct CircularList* list){
	if(list->size == 0)
		return 1;
	else
		return 0;
}

/*********************************************************************
 * Prints the values of the links in the deque from front to back.
 ********************************************************************/
void circularListPrint(struct CircularList* list){
	assert(!circularListIsEmpty(list));
	struct Link *curr = list->sentinel->next;
	while(curr != list->sentinel){
		printf("%g \n", curr->value);
	curr = curr->next;
	}
}

/*********************************************************************
 * Reverses the deque.
 ********************************************************************/
void circularListReverse(struct CircularList* list){
 	struct Link *curr = list->sentinel->next;
	int toRemove = list->size-1;
	curr = curr->next;
	while(curr != list->sentinel){
		circularListAddFront(list, curr->value);
		curr = curr->next;
	}
	for(int i = 0; i<toRemove; i++){
		circularListRemoveBack(list);
	}
}
