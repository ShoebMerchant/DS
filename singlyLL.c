#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

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
void deleteNode(Node **, int);
void deleteHead(Node **);
void deleteTail(Node **);
bool searchList(Node *, int);
void revList(Node **);
Node* revListRecursive(Node **);
void reversePrint(Node *);

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
    searchList(head, 3) ? 
        printf("Key Found\n") 
        : printf("Key not found\n");
    revList(&head);
    display(head);
    Node *newHead = revListRecursive(&head);
    display(newHead);
    reversePrint(newHead);
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
    // Check if head is not null
    if (*head_ref == NULL)return;

    // Create a pointer to the head
    Node *to_delete = *head_ref;

    // make head point to the next of head
    *head_ref = to_delete->next;

    // Good practice
    to_delete->next = NULL;

    // delete the previous head
    free(to_delete);

    return;
}

/**
 * Given a reference (pointer to pointer) 
 * to the head of a list, 
 * deletes the tail Node
 */
void deleteTail(Node **head_ref) {
    // Check if head is not null
    if (*head_ref == NULL)return;

    // Create a pointer to the head
    Node *to_delete = *head_ref;

    // While loop to the second last Node
    while(to_delete->next->next != NULL)
        to_delete = to_delete->next;

    // delete the last Node
    free(to_delete->next);

    // The last node must point to NULL
    to_delete->next = NULL;

    return;
}

/**
 * Given a pointer to the
 * head of a list, search the list
 * for a given key
 */ 
bool searchList(Node *head, int key) {
    /**
     * No need to create a tempNode
     * as we recieve head pointers by value
     * not by reference
     */
    while (head != NULL) {
        
        // Check if the key is found
        if (head->data == key) {
            return true;
        }
        // Otherwise move on to the next node
        head = head->next;
    }

    // If we didn't find the key
    return false;
}

/**
 * Reverse a Linked List given 
 * a reference (pointer to pointer)
 * to the head of a list
 */ 
void revList(Node **head_ref) {
    
    /**
     * The current pointer initially
     * reference the head pointer and
     * moves to the next pointer in
     * every iteration. prev and next
     * pointer also shows similar behavior.
     * 
     * As the head pointer after the list
     * is reversed, must point to Null
     * prev is initialized as Null pointer
     */ 
    Node *curr = *head_ref,
        *prev = NULL,
        *next;
    
    // If curr is null, then we have reached
    // the end of the Linked List
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    // Repositioning the head
    *head_ref = prev;

    // successfully reversed
    return;
}

/**
 * Function to recursively reverse a linked list
 * and return a new pointer to the new Head of the 
 * reversed Linked List
 * 
 * to view a rough example
 * of recursive calls : shorturl.at/fgCHY
 */
Node *revListRecursive(Node **head_ref) {

    // If we have reached the end of the Linked List
    // Or the head is NULL
    if((*head_ref) == NULL || (*head_ref)->next == NULL) {
        return (*head_ref);
    }

    // New Head to the end of the Linked List
    Node* newHead = revListRecursive(&(*head_ref)->next);
 
    (*head_ref)->next->next = (*head_ref);

    // So that the previous head->next points at next
    (*head_ref)->next = NULL;

    // Head of our reversed list
    return newHead;
}

/**
 * To Print a LL in reverse
 * using recursion
 */
void reversePrint(Node * head) {
    // Base case we have reached 
    // the end of the Linked List
    if(!head) return;

    // Recursive function call
    reversePrint(head->next);

    // Printing the data
    printf("%d -> ", head->data);
}
