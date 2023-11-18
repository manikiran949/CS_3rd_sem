// nth fibonacci number using hashing method. It is storing of subproblems [similar to dp].
#include<stdio.h>
int memo[100];
int fib(int n){
    if(n<=1) return n;
    if(memo[n]!=-1) return memo[n];
    memo[n]=fib(n-1)+fib(n-2);
    return memo[n];
}
int main(){
    for(int i=0;i<100;i++){
        memo[i]=-1;
    }
    int n;
    scanf("%d",&n);
    printf("%d\n",fib(n));
    return 0;
}
