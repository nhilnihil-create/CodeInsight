#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define LL long long
using namespace std;
int main()
{
    LL k,n=50;
    scanf("%lld",&k);
    printf("50\n");
    LL cnt=k/50,res=k%50;
    for(int i=0;i<50;i++)
    {
        if(i<res) printf("%lld",i+cnt+n-res+1);
        else printf("%lld",i+cnt-res);
        if(i!=49) printf(" ");
    }
    return 0;
}