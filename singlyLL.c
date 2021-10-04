#include <stdio.h>

/**
 * Read more about using
 * typedef with structure in C
 * here: https://www.tutorialspoint.com/cprogramming/c_typedef.htm
 * */
// Structure defination must be global
typedef struct Node {
    int data;
    // address of the next node
    Node *next;
}Node;

int main(int argc, char *argv[])
{
    // Head Pointer
    Node *head = NULL;
    return 0;
}
