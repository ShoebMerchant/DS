/**
 * Two Ended list
 * front and rear ENDS
 * FIFO (First in First Out) DS
 */

#include <stdio.h>

/**
 * Dynamic Implementation of Queue:
 * Front will always point to the front node of SLL
 * Rear will always point to the last node of SLL
 */
typedef struct Queue {
    int info; 
    struct Queue *next;
} Queue;

void InitQueue(Queue **, Queue **);
void Insert(Queue **, Queue **, int);

int main(int argc, char *argv[])
{
    Queue *front, *rear;
    InitQueue(&front, &rear);
    Insert(&front, &rear, 10);
    return 0;
}

void InitQueue(Queue **front_ref, Queue **rear_ref) {
    (*front_ref) = (*rear_ref) = NULL;
}

void Insert(Queue **front_ref, Queue **rear_ref, int value) {
    Queue *new = (Queue *)malloc(sizeof(Queue));
    new->info = value;
    new->next = NULL;
    if((*front_ref) == NULL && (*rear_ref) == NULL) {
        *front_ref = *rear_ref = new;
        return;
    } 
    (*rear_ref)->next = new;
    (*rear_ref) = (*rear_ref)->next;
}