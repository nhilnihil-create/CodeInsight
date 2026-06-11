#include<iostream>
#include<cstdio>
using namespace std;
#define inf 1000000007
int m,f[1000003],a;
int main()
{
    scanf("%d",&m);f[m]=m;
    f[m-1]=(long long)m*m%inf;
    for(int i=m-2;i>=1;--i)
    {
        a=(a+f[i+3])%inf;f[i]=f[i+1];
        f[i]=(f[i]+(long long)(m-1)*(m-1)%inf)%inf;
        f[i]=(f[i]+a)%inf;f[i]=(f[i]+i+1)%inf;
    }
    printf("%d\n",f[1]);
    return 0;
}