/*
  Mani Kiran, 2212056.

  Q) C program to add very large numbers.
  if length of 1st number =m , length of second number =n, (m>n)
  Time complexity- O(m), 
  Space complexity - O(m).
*/
#include<stdio.h>
#include<string.h>
int max(int x,int y){
    if(x>=y) return x;
    else return y;
}
void add(char *s1,char *s2){
    int n1=strlen(s1),n2=strlen(s2),first=0,n=max(n1,n2)+1,ind=n-1,carry=0;
    char x[n],y[n];
    for(int i=0;i<n;i++){
        x[i]='0';
        y[i]='0';
    }
    for(int i=n1-1;i>=0;i--){
        x[ind]=s1[i];
        ind--;
    }
    ind=n-1;
    for(int i=n2-1;i>=0;i--){
        y[ind]=s2[i];
        ind--;
    }
    char ans[n];
    for(int i=0;i<n;i++) ans[i]='0';
    for(int i=n-1;i>=0;i--){
        int sum=(x[i]-'0')+(y[i]-'0')+carry;
        ans[i]=(sum%10)+'0';
        carry=sum/10;
    }
    for(int i=n-1;i>=0;i--) if(ans[i]!='0') first=i;
    for(int i=first;i<n;i++) printf("%c",ans[i]);
    printf("\n");
}
int main(){
    char s1[1024],s2[1024];
    scanf("%s %s",s1,s2);
    add(s1,s2);
    return 0;
}
