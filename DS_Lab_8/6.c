/*
    Detect whether a linked list contains a loop (cycle) or not.
     Time complexity - O(N).
     Space complexity - O(1)
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to detect a loop (cycle) in a linked list
int detectLoop(struct Node* head) {
    struct Node* slowPtr = head;
    struct Node* fastPtr = head;

    while (fastPtr != NULL && fastPtr->next != NULL) {
        slowPtr = slowPtr->next;      // Move slow pointer by one step
        fastPtr = fastPtr->next->next; // Move fast pointer by two steps

        if (slowPtr == fastPtr) {
            // If they meet, there is a loop in the linked list
            return 1; // Loop detected
        }
    }

    // If the loop exits, there is no loop in the linked list
    return 0; // No loop detected
}

// Helper function to create a new node and append it to the end of the list
void append(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main() {
    struct Node* head = NULL;
    // Creating a linked list with a loop
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);

    // Creating a loop by connecting the last node to the second node
    head->next->next->next->next->next = head->next;

    // Detecting a loop in the linked list
    if (detectLoop(head)) {
        printf("Linked list contains a loop.\n");
    } else {
        printf("Linked list does not contain a loop.\n");
    }

    return 0;
}

/*
 Output : Linked list contains a loop.
*/
