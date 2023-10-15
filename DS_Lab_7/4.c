// 4
 
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char stack[1000];
int top=-1;
void push(char c){
   top++;
   stack[top]=c;
}
void pop(){
  top--;
}
char peek(){
  return stack[top];
}
int empty(){
  return top==-1;
}
int matched(char b,char a){
   return ((a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']'));
}
int main(){
    char *par="[{()((()))}]";
    int n=strlen(par);
    int tmp=1;
    for(int i=0;i<n;i++){
      if(par[i]=='(' || par[i]=='{' || par[i]=='[' ) push(par[i]);
      else{
         char x=peek();
         if(matched(par[i],x)) pop();
         else tmp=0;
      }
    }
    if(tmp && empty()) printf("Valid parenthesis\n");
    else printf("Invalid Parenthesis\n");
  return 0;
}
 
