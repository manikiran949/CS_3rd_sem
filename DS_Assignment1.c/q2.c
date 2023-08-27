/*
  Mani Kiran , 2212056
  
  C program to multiply very large numbers.
  if length of 1st number =m , length of second number =n, 
  Time complexity = O(m*n)
  space complexity = O(m+n).
*/
#include<stdio.h>
#include<string.h>
void multiply(char *num1, char *num2)
{
	int sz1=strlen(num1),sz2=strlen(num2),v1 = 0,v2 = 0;
	if(sz1== 0 || sz2==0) printf("0\n");
	char ans[sz1+sz2];
    for(int i=0;i<sz1+sz2;i++) ans[i]='0';
	for(int i=sz1-1;i>=0;i--){
		int carry = 0,n1=num1[i]-'0';
		v2=0;		
		for(int j=sz2-1;j>=0;j--){
			int n2=num2[j]-'0',sum=n1*n2+(ans[v1+v2]-'0')+carry;
			carry=sum/10;
			ans[v1+v2]=(sum%10)+'0';
			v2++;
		}
		if(carry>0){
            int x=(ans[v1 + v2]-'0')+carry;
            ans[v1+v2]=x+'0';
        }
		v1++;
	}
	int i=sz1+sz2-1,first=0;
	while(i>=0 && ans[i]=='0') i--;
	if(i==-1) printf("0");
    for(int i=sz1+sz2-1;i>=0;i--) if(ans[i]!='0'){
         first=i;
         break;
    }
	for(int i=first;i>=0;i--) printf("%c",ans[i]);
}
int main(){
    char s1[1024],s2[1024];
    scanf("%s %s",s1,s2);
    multiply(s1,s2);
	return 0;
}
