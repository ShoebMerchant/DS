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

struct stack {
    int info;
    struct stack *next;
};

void InitStack(struct stack **);
void push(struct stack **, int);
void pop(struct stack **);

int main(int argc, char *argv[])
{
    struct stack *top;
    InitStack(&top);
    push(&top, 10);
    push(&top, 20);
    printf("%d\n", top->info);
    pop(&top);
    printf("%d\n", top->info);
    return 0;
}

void InitStack(struct stack ** t) {
    *t=NULL;
}

void push(struct stack **t, int value) {
    struct stack *p;
    p=(struct stack *)malloc(sizeof(struct stack));
    p->info = value;
    p->next = NULL;
    if(*t==NULL) {
        *t = p;
        return;
    }
    p->next = *t;
    *t = p;
}

void pop(struct stack **t) {
    if(*t==NULL) {
        return;
    }
    if((*t)->next == NULL) {
        *t=NULL;
        return;
    }
    (*t) = (*t)->next;
    return;
}