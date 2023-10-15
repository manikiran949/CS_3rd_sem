#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack {
    int top;
    unsigned capacity;
    int *array;
};

typedef struct Stack stack;

stack *createStack(int capacity) {
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = -1;
    s->capacity = capacity;
    s->array = (int *)malloc(s->capacity * sizeof(int));
    return s;
}

int isFull(stack *s) {
    return (s->top == s->capacity - 1);
}

int isEmpty(stack *s) {
    return (s->top == -1);
}

void push(stack *s, int data) {
    if (isFull(s)) {
        printf("Queue is full. Cannot enQueue.\n");
        return;
    }
    s->array[++s->top] = data;
}

int pop(stack *s) {
    if (isEmpty(s)) {
        printf("Queue is empty. Cannot deQueue.\n");
        return -1; 
    }
    return s->array[s->top--];
}

struct Queue {
    stack *stack1;
    stack *stack2;
};

typedef struct Queue queue;

queue *createQueue(int capacity) {
    queue *q = (queue *)malloc(sizeof(queue));
    q->stack1 = createStack(capacity);
    q->stack2 = createStack(capacity);
    return q;
}

void enQueue(queue *q, int data) {
    while (!isEmpty(q->stack1)) {
        push(q->stack2, pop(q->stack1));
    }
    push(q->stack1, data);
    while (!isEmpty(q->stack2)) {
        push(q->stack1, pop(q->stack2));
    }
}

int deQueue(queue *q) {
    if (isEmpty(q->stack1)) {
        printf("Queue is empty. Cannot deQueue.\n");
        return -1;
    }
    return pop(q->stack1);
}

int main() {
    queue *q = createQueue(5);

    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);
    enQueue(q, 40);
    deQueue(q);
    deQueue(q);
    deQueue(q);
    // printf("DeQueued: %d\n", deQueue(q)); 
    // printf("DeQueued: %d\n", deQueue(q)); 
    // printf("DeQueued: %d\n", deQueue(q)); 
    printf("DeQueued: %d\n", deQueue(q)); 

    return 0;
}
