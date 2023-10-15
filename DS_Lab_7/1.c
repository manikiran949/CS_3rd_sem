// 1
 
/*
  implement stack using structure for the following function.
    a) isEmpty()
    b) isFull()
    c) Push()
    d) Pop()
    e) Peek()
*/
 #include<stdio.h>
 #include<stdlib.h>
 struct Stack{
    int top;
    unsigned int capacity;
    int *array;
 };
 typedef struct Stack stack;
 
 stack *createStack(int c){
    stack *s=(stack *)malloc(sizeof(stack));
    s->top=-1;
    s->capacity=c;
    s->array=(int *)malloc(c*sizeof(int));
    return s;
 }
 int isEmpty(stack *s){
    return (s->top==-1);
 }
 int isFull(stack *s){
    return (s->top==s->capacity-1);
 }
 void push(stack *s,int n){
    if(isFull(s)){
       printf("Stack is full\n");
       return;
    }
    s->top++;
    s->array[s->top]=n;
    return;
 }
 void pop(stack *s){
    if(isEmpty(s)){
       printf("Stack is empty\n");
       return;
    }
    s->top--;
 }
 int peek(stack *s){
   if(isEmpty(s)){
       printf("Stack is empty\n");
       return -1;
   }
   return s->array[s->top];
 }
 void show(stack *s){
    for(int i=0;i<=s->top;i++) printf("%d ",s->array[i]);
    printf("\n");
 }
 int main(){
    stack *s=createStack(5);
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
    show(s);
    printf("is stack full ? %d\n",isFull(s));
    pop(s);
    show(s);
    printf("top element of stack is : %d\n",peek(s));
    printf("is stack empty ? %d\n",isEmpty(s));
    pop(s);
    pop(s);
    pop(s);
    printf("is stack full ? %d\n",isFull(s));
    pop(s);
    printf("is stack empty ? %d\n",isEmpty(s));
   return 0;
 }
