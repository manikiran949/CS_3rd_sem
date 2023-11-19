// sieve of eratosthenes.
#include<stdio.h>
void sieve(int n){
    int prime[n+1];
    for(int i=0;i<=n;i++) prime[i]=1;
    for(int p=2;p*p<=n;p++){
        if(prime[p]){
            for(int i=p*p;i<=n;i+=p) prime[i]=0;
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i]) printf("%d ",i);
    }
    printf("\n");
}
int main(){
    int n;
    scanf("%d",&n);
    sieve(n);
    return 0;
}
