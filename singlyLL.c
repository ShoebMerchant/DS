#include <stdio.h>
#include <stdlib.h>
/**
 * Read more about using
 * typedef with structure in C
 * here: https://www.tutorialspoint.com/cprogramming/c_typedef.htm
 * */
// Structure defination must be global
typedef struct Node {
    int data;
    // address of the next node
    struct Node *next;
}Node;

// Function definitions
void insertAtHead(Node **, int);
void insertAtTail(Node **, int);
void display(Node *);
void deleteNode(Node **, int key);
void deleteHead(Node **);

int main(int argc, char *argv[])
{
    // Head Node
    Node *head = NULL;
    insertAtHead(&head, 2);
    insertAtHead(&head, 1);
    for (int i = 0; i < 5; i++)
    {
        insertAtTail(&head, i);
    }
    display(head);
    deleteNode(&head,2);
    deleteNode(&head, 1);
    display(head);
    deleteHead(&head);
    display(head);
    return 0;
}

/**
 * Function to add a node to 
 * the head of the Linked list
 */
void insertAtHead(Node** head_ref, int val){
    // 1. Allocate node
    Node *n = (Node *)malloc(sizeof(Node));

    // 2. set the value to the new node
    n->data = val;

    // 3. Make next of new node as head
    n -> next = (*head_ref);

    // 4. move the head to point to the new node
    (*head_ref) = n;
}

/**
 * Function to add a node to 
 * the tail/end of the Linked list
 */
void insertAtTail(Node **head_ref, int val){
    // 1. Allocate node
    Node *newNode = (Node*) malloc(sizeof(Node));

    // 2. Create new node to iterate through while loop
    Node *tempNode = *head_ref;

    // 3. set the value to the new node
    newNode->data = val;

    /**
     * 4. This new node is going to be the last node, 
     * so make next of it as NULL
     */
    newNode->next = NULL;

    /**
     * 5. If the Linked List is empty
     * then the new node is the head node
     */
    if (*head_ref == NULL) {
        insertAtHead(&*head_ref, val);
        return;
    }

    // 6. Else traverse till the last node
    while(tempNode->next != NULL){
        tempNode = tempNode->next;
    }

    /* 7. Change the next of last node */
    tempNode->next = newNode;
}

/**
 * Function to display the
 * data of the Linked List
 */
void display(Node *head){
    /**
     * No need to create a tempNode
     * as we recieve head pointers by value
     * not by reference
     */
    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

/**
 * Given a reference (pointer to pointer) 
 * to the head of a list and a key, 
 * deletes the first occurrence 
 * of key in linked list
 */ 
void deleteNode(Node ** head_ref, int key) {
    // Store head node
    Node *temp = *head_ref, *prev;

    // If head node itself holds the key to 
    // be deleted
    if (temp != NULL && temp->data == key) {
        deleteHead(&*head_ref);
        return;
    }

    /**
     * Search for the key to be deleted, keep track of the
     * previous node as we need to change 'prev->next'
     */
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
        return;
    
    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp);// Free memory
}

/**
 * Given a reference (pointer to pointer) 
 * to the head of a list, 
 * deletes the head Node
 */
void deleteHead(Node **head_ref) {
    if (*head_ref == NULL)return;
    Node *to_delete = *head_ref;
    *head_ref = to_delete->next;
    free(to_delete);
    return;
}