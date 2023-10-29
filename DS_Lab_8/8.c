/*
  Write a program to rotate a doubly linked list k times.
  time complexity - O(N).
  space complexity - O(N).
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertLast(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void rotateRight(struct Node** head, int k) {
    if (*head == NULL) {
        return;
    }

    struct Node* current = *head;
    int count = 0;

    while (current != NULL && count < k) {
        current = current->next;
        count++;
    }
    if (current == NULL) {
        return;
    }

    struct Node* kthNode = current;

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = *head;
    (*head)->prev = current;
    *head = kthNode->next;
    (*head)->prev = NULL;

    kthNode->next = NULL;
}

int main() {
    struct Node* head = NULL;

    insertLast(&head, 10);
    insertLast(&head, 20);
    insertLast(&head, 30);
    insertLast(&head, 40);
    insertLast(&head, 50);

    printf("Original Doubly Linked List:\n");
    display(head);

    int k = 2;
    rotateRight(&head, k);

    printf("Doubly Linked List after rotating %d times to the right:\n", k);
    display(head);

    return 0;
}

/*
Output:
  
Original Doubly Linked List: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
Doubly Linked List after rotating 2 times to the right: 40 -> 50 -> 10 -> 20 -> 30 -> NULL

*/
