/**
 * It is a LIFO data structure
 * Last-In First-Out
 * It is a dynamic data structure
 * Insertion operation is called as push
 * Deletion operation is called as pop
 * It is a one ended list. And that end end is called
 * as Top. Push and Pop happens from the end called as Top.
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * Dynamic implementation of Stack
 * We are going to implement stack using SLL.
 * If Stack is empty, then top == NULL
 */

typedef struct Stack {
    int info;
    struct Stack *next;
}Stack;

void InitStack(Stack **);
void push(Stack **, int);
void pop(Stack **);
void display(Stack *);

int main(int argc, char *argv[])
{
    Stack *top;
    InitStack(&top);
    for(int i=0; i<6; i++)
        push(&top, 5*i);
    display(top);
    return 0;
}

void InitStack(Stack ** t) {
    *t=NULL;
}

void push(Stack **top_node, int value) {
    Stack *p =(Stack *)malloc(sizeof(Stack));
    p->info = value;
    p->next = NULL;
    if(*top_node==NULL) {
        *top_node = p;
        return;
    }
    p->next = (*top_node);
    *top_node = p;
}

void pop(Stack **top_node) {
    if(*top_node==NULL) {
        return;
    }
    if((*top_node)->next == NULL) {
        *top_node=NULL;
        return;
    }
    Stack *to_delete = (*top_node);
    (*top_node) = (*top_node)->next;
    free(to_delete);
    return;
}

void display(Stack *top_node) {
    while(top_node != NULL) {
        printf("%d | ", top_node->info);
        pop(&top_node);
    }
}