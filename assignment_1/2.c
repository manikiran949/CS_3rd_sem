// C program to convert a number from decimal to roman.
#include<stdio.h>
void roman(int num){
    if(num==1) printf("I");
    else if(num==4) printf("IV");
    else if(num==5) printf("V");
    else if(num==9) printf("IX");
    else if(num==10) printf("X");
    else if(num==40) printf("XL");
    else if(num==50) printf("L");
    else if(num==90) printf("XC");
    else if(num==100) printf("C");
    else if(num==400) printf("CD");
    else if(num==500) printf("D");
    else if(num==900) printf("CM");
    else if(num==1000) printf("M");
    return;
}
void to_roman(int number){
    int val[13]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
    int index=12;
    printf("Roman numeral is : ");
    while(number>0){
        int div=number/val[index];
        number%=val[index];
        while(div--){
            roman(val[index]);
        }
        index--;
    }
    printf("\n");
    return ;
}
int main(){
    printf("Enter a number between 1 and 3999 : ");
    int number;
    scanf("%d",&number);
    to_roman(number);
    return 0;
}
