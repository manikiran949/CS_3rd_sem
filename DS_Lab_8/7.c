/*
    Write a program to implement the following functions of the doubly linked list
 (a) Insert at front
 (b) Insert at last
 (c) Insert after the given item
 (d) Insert before the given item
 (e) Delete an item from the front
 (f) Delete an item from the last
 (g) Delete a given item

 Time Complexity - O(N).
 Space complexity - O(N).
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
void insertFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
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
void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node is NULL. Insertion failed.\n");
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
}
void insertBefore(struct Node** head, struct Node* nextNode, int data) {
    if (nextNode == NULL) {
        printf("Next node is NULL. Insertion failed.\n");
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->prev = nextNode->prev;
    if (nextNode->prev != NULL) {
        nextNode->prev->next = newNode;
    } else {
        *head = newNode;
    }
    newNode->next = nextNode;
    nextNode->prev = newNode;
}
void deleteFront(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Deletion failed.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}
void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Deletion failed.\n");
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;
    }

    free(temp);
}
void deleteItem(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty. Deletion failed.\n");
        return;
    }

    struct Node* current = *head;
    while (current != NULL) {
        if (current->data == data) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                *head = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
    printf("Item not found in the list. Deletion failed.\n");
}
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertFront(&head, 10);
    insertFront(&head, 20);
    insertLast(&head, 30);
    insertAfter(head->next, 40);
    insertBefore(&head, head->next, 5);

    printf("Doubly Linked List after insertion:\n");
    display(head);

    deleteFront(&head);
    deleteLast(&head);
    deleteItem(&head, 40);

    printf("Doubly Linked List after deletion:\n");
    display(head);

    return 0;
}

/*
  Output : 
 Doubly Linked List after insertion: 20 -> 5 -> 10 -> 40 -> 30 -> NULL
 Doubly Linked List after deletion: 5 -> 10 -> NULL
*/
