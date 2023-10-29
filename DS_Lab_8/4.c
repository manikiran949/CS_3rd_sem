/*
   Write a program to implement the following functions of a circular linked list.
   (a) Insert an item
   (b) Delete an item
   Time complexity -O(N), N is no of nodes in the circular linked list.
   Space Complexity - O(N).
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
    } 
    else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Inserted: %d\n", item);
}
void delete(int item) {
    if (head == NULL) {
        printf("List is empty. Deletion failed.\n");
        return;
    }
    struct Node* current = head;
    struct Node* prev = NULL;
    while (1) {
        if (current->data == item) {
            if (current == head && current->next == head) {
                head = NULL;
            } else if (current == head) {
                struct Node* lastNode = head;
                while (lastNode->next != head) {
                    lastNode = lastNode->next;
                }
                head = head->next;
                lastNode->next = head;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Deleted: %d\n", item);
            return;
        }
        if (current->next == head) {
            printf("Item %d not found in the list. Deletion failed.\n", item);
            return;
        }
        prev = current;
        current = current->next;
    }
}
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do{
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
int main() {
    int data_to_insert[] = {10, 20, 30, 40, 50};
    int data_to_delete[] = {20, 40};
    for (int i = 0; i < sizeof(data_to_insert) / sizeof(data_to_insert[0]); i++) {
        insert(data_to_insert[i]);
    }
    for (int i = 0; i < sizeof(data_to_delete) / sizeof(data_to_delete[0]); i++) {
        delete(data_to_delete[i]);
    }
    printf("Circular Linked List after insertion and deletion:\n");
    display();
    return 0;
}

/*
Output : 

Inserted: 10
Inserted: 20
Inserted: 30
Inserted: 40
Inserted: 50
Deleted: 20
Deleted: 40
Circular Linked List after insertion and deletion:
10 -> 30 -> 50 ->
*/
