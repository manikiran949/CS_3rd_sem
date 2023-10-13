// using recursion.

#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *next;
} *head;
 
void initialize(){
    head = NULL;
}
void insert(int num) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data  = num;
    newNode->next = head;
    head = newNode;
    printf("Inserted Element : %d\n", num);
}
void reverse(struct node* nodePtr) {
    if (nodePtr == NULL)
       return;   
    if(nodePtr->next == NULL){
        head = nodePtr;
        return;   
    }
    reverse(nodePtr->next);
    nodePtr->next->next = nodePtr;  
    nodePtr->next = NULL;               
}
void printLinkedList(struct node *nodePtr) {
  while (nodePtr != NULL) {
     printf("%d", nodePtr->data);
     nodePtr = nodePtr->next;
     if(nodePtr != NULL)
         printf("-->");
  }
}
  
int main() {
    initialize();
    insert(1);  
    insert(2); 
    insert(3); 
    insert(4);
    insert(5);
     
    printf("\nLinked List\n");
    printLinkedList(head);
    reverse(head);
    printf("\nReversed Linked List\n");
    printLinkedList(head);
    return 0;
}





// iterative

#include <stdio.h>
#include <stdlib.h>
  
/* A structure of linked list node */
struct node {
  int data;
  struct node *next;
} *head;
 
void initialize(){
    head = NULL;
}
 
/* 
Given a Inserts a node in front of a singly linked list. 
*/
void insert(int num) {
    /* Create a new Linked List node */
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data  = num;
    /* Next pointer of new node will point to head node of linked list  */
    newNode->next = head;
    /* make new node as new head of linked list */
    head = newNode;
    printf("Inserted Element : %d\n", num);
}
 
/* Reverses a given Linked List, and return 
the head pointer of reversed linked list */
struct node* reverseLinkedList(struct node *head) {
    struct node *previous, *current, *next;
    previous = NULL;
    current = head;
 
    while (current != NULL) {
        next  = current->next;  
        current->next = previous;   
        previous = current;
        current = next;
    }
    return previous;
}
 
/*
Prints a linked list from head node till tail node 
*/
void printLinkedList(struct node *nodePtr) {
  while (nodePtr != NULL) {
     printf("%d", nodePtr->data);
     nodePtr = nodePtr->next;
     if(nodePtr != NULL)
         printf("-->");
  }
}
  
int main() {
    initialize();
    /* Creating a linked List*/
    insert(8);  
    insert(3); 
    insert(2); 
    insert(7);
    insert(9);
     
    printf("\nLinked List\n");
    printLinkedList(head);
     
    /* Reverse Linked List */
    head = reverseLinkedList(head);
    printf("\nReversed Linked List\n");
    printLinkedList(head);
     
    return 0;
}
