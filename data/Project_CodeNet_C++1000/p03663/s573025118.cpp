#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;

char s[10];

int main(){
    int i;
    long long x=1;
    for(i=1;i<=11;i++,x*=10){
        printf("? %lld\n",x);fflush(stdout);
        scanf("%s",s+1);
        if(s[1]=='N')break;
    }if(i>11){
        for(i=1,x=10;i<=11;i++,x*=10){
            printf("? %lld\n",x-1);fflush(stdout);
            scanf("%s",s+1);
            if(s[1]=='Y')break;
        }printf("! %lld\n",x/10);return 0;
    }
    long long l=x-1,r=x*10-1;
    while(l+1<r){
        long long mid=(l+r)>>1;
        printf("? %lld\n",mid);
        fflush(stdout);
        scanf("%s",s+1);
        if(s[1]=='N')l=mid;
        else r=mid;
    }printf("! %lld\n",r/10);
    fflush(stdout);
    return 0;
}