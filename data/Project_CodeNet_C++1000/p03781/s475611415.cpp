#include<cstdio>
int main(){
    int x,t,d=0;
    scanf("%d",&x);
    for(t=1;d<x;t++)d+=t;
    printf("%d",t-1);
    return 0;
}