// 6

#include <stdio.h>
#include <stdlib.h>
struct stack {
    int top1, top2;
    int cap;
    int *array;
};
typedef struct stack stack;
stack *createstack(int cap) {
    stack *ts = (stack *)malloc(sizeof(stack));
    ts->cap = cap;
    ts->top1 = -1;
    ts->top2 = cap;
    ts->array = (int *)malloc(ts->cap * sizeof(int));
    return ts;
}
int isFull(stack *ts, int no) {
    if (no == 1) return (ts->top1 == ts->top2 - 1);
	else if (no == 2) return (ts->top2 == ts->top1 + 1);
    return 0;
}
int isEmpty(stack *ts, int no) {
    if (no == 1) return (ts->top1 == -1);
	else if (no == 2) return (ts->top2 == ts->cap);
    return 0;
}
void push(stack *ts, int no, int data) {
    if (isFull(ts, no)) {
        printf("Stack %d is full.\n", no);
        return;
    }
    if (no == 1) ts->array[++ts->top1] = data;
	else if (no == 2) ts->array[--ts->top2] = data;
}
int pop(stack *ts, int no) {
    if (isEmpty(ts, no)) {
        printf("Stack %d is empty.\n", no);
        return -1;
    }
    int data;
    if (no == 1) data = ts->array[ts->top1--];
	else if (no == 2) data = ts->array[ts->top2++];
    return data;
}
int peek(stack *ts, int no) {
    if (isEmpty(ts, no)) {
        printf("Stack %d is empty.\n", no);
        return -1;
    }
    if (no == 1) return ts->array[ts->top1];
	else if (no == 2) return ts->array[ts->top2];
    return -1; 
}
int main() {
    int cap = 10;
    stack *ts = createstack(cap);
    push(ts, 1, 1);
    push(ts, 1, 2);
    push(ts, 2, 11);
    push(ts, 1, 3);
    push(ts, 2, 12);
    printf("Peek from Stack 1: %d\n", peek(ts, 1));
    printf("Peek from Stack 2: %d\n", peek(ts, 2));
    pop(ts, 1);
    pop(ts, 2);
    printf("Peek from Stack 1: %d\n", peek(ts, 1));
    printf("Peek from Stack 2: %d\n", peek(ts, 2));
    return 0;
}
