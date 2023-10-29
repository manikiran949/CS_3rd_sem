/*
   Write a program to sort the stack items using another stack.
   time complexity - O(n).
   space complexity - O(1).
*/
#include <stdio.h>
int stack1[6];
int stack2[6];
const int sz=6;
int top1=-1,top2=-1;
void push1(int n){
    if(top1==sz){
        printf("stack is full\n");
        return;
    }
    top1++;
    stack1[top1]=n;
}
void push2(int n){
    if(top2==sz){
        printf("stack is full\n");
        return;
    }
    top2++;
    stack2[top2]=n;
}
void pop1(){
    if(top1==-1){
        printf("stack 1 is empty\n");
        return;
    }
    top1--;
}
void pop2(){
    if(top2==-1){
        printf("stack 2 is empty\n");
        return;
    }
    top2--;
}
int peek1(){
    if(top1==-1){
        printf("stack 1 is empty\n");
        return -1;
    }
    return stack1[top1];
}
int peek2(){
    if(top2==-1){
        printf("stack 2 is empty\n");
        return -1;
    }
    return stack2[top2];
}
int isEmpty1(){
    if(top1==-1) return 1;
    else return 0;
}
int isEmpty2(){
    if(top2==-1) return 1;
    else return 0;
}
int main() {
   push1(34);
   push1(3);
   push1(31);
   push1(98);
   push1(92);
   push1(23);
   while(!isEmpty1()){
       int x=peek1();
       pop1();
       while(!isEmpty2() && x>peek2()){
           push1(peek2());
           pop2();
       }
       push2(x);
   }
   for(int i=top2;i>=0;i--) printf("%d ",stack2[i]);
   printf("\n");
    return 0;
}

/*
  Output:
  3 23 31 34 92 98
*/

























