// finding nth fibonacci number in logn time using matrix exponentiation.

#include<stdio.h>
int fib(int n){
    int f[2][2]={{1,1},{1,0}};
    power(f,n-1);
    return f[0][0];
}
void power(int f[2][2],int n){
    if(n<=1) return;
    power(f,n/2);
    multiply(f,f);
    int m[2][2]={{1,1},{1,0}};
    if(n%2) multiply(f,m);
}
void multiply(int a[2][2],int b[2][2]){
    int x=a[0][0]*b[0][0]+a[0][1]*b[1][0];
    int y=a[0][0]*b[0][1]+a[0][1]*b[1][1];
    int z=a[1][0]*b[0][0]+a[1][1]*b[1][0];
    int w=a[1][0]*b[0][1]+a[1][1]*b[1][1];
    a[0][0]=x; 
    a[0][1]=y;
    a[1][0]=z;
    a[1][1]=w;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",fib(n));
    return 0;
}
