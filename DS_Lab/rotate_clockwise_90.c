// rotate a matrix 90 degrees clockwise.
#include<stdio.h>
int main(){
    int n=3;
    int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) printf("%d ",a[n-j-1][i]);
        printf("\n");
    }
    return 0;
}
