/*
   Write a program to find the middle item of a circular linked list.
   time complexity - O(N)
   space complexity - O(N)
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}
int findMiddle() {
    if (head == NULL) {
        printf("List is empty. No middle element.\n");
        return -1;
    }
    struct Node* slowPtr = head;
    struct Node* fastPtr = head;
    while (fastPtr != NULL && fastPtr->next != NULL && fastPtr->next->next != head) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    return slowPtr->data;
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int data_to_insert[] = {10, 20, 30, 40, 50, 60};
    for (int i = 0; i < sizeof(data_to_insert) / sizeof(data_to_insert[0]); i++) {
        insert(data_to_insert[i]);
    }
    printf("Circular Linked List:\n");
    display();
    int middle = findMiddle();
    if (middle != -1) {
        printf("Middle element: %d\n", middle);
    }
    return 0;
}

/*
Output :

Circular Linked List: 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> 
Middle element: 30
*/
