#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int n,x,i,c,mod;
long long s;
int main(){
    scanf("%d",&n);
    s=1;
    mod=1000000007;
    for(i=0;i<n;i++){
        scanf("%d",&x);
        c++;
        if(c*2-1>x){
            s=s*c%mod;
            c--;
        }
    }
    for(i=c;i>1;i--) s=s*i%mod;
    printf("%d\n",(int)s);
}
