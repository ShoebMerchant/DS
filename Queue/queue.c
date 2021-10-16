/**
 * Two Ended list
 * front and rear ENDS
 * FIFO (First in First Out) DS
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Dynamic Implementation of Queue:
 */
typedef struct Queue {
    int info; 
    struct Queue *next;
} Queue;

void InitQueue(Queue **, Queue **);
void Insert(Queue **, Queue **, int);

int main(int argc, char *argv[])
{
    /**
     * Front will always point to the front node of SLL
     * Rear will always point to the last node of SLL
     */ 
    Queue *front, *rear;

    // Queue initialization
    InitQueue(&front, &rear);

    // Insertion at rear
    Insert(&front, &rear, 10);

    // testing
    printf("%d\n", front->info);
    return 0;
}

void InitQueue(Queue **front_ref, Queue **rear_ref) {
    (*front_ref) = (*rear_ref) = NULL;
}

/**
 * Given two reference (pointer to pointer)
 * front and rear and a value, add to 
 * the end of the queue
 */ 
void Insert(Queue **front_ref, 
            Queue **rear_ref, int value) {

    // Allocate memory for the Queue element
    Queue *new = (Queue *)malloc(sizeof(Queue));

    // Set the value
    new->info = value;

    // Rear->next should be NULL
    new->next = NULL;

    /**
     * If the Queue is empty then both 
     * front and rear pointers will be
     * pointing to the same Queue element
     */ 
    if((*front_ref) == NULL && (*rear_ref) == NULL) {
        *front_ref = *rear_ref = new;
        return;
    } 

    // Add the new element to the
    // end of the queue
    (*rear_ref)->next = new;

    // Fix the position of rear pointer
    // to the end of the queue
    (*rear_ref) = (*rear_ref)->next;
}