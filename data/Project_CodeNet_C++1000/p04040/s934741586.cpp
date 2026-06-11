#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define p 1000000007
using namespace std;

long long fac[200010],inv[200010],n,m,aa,bb,ans;

long long kasumi(long long a,long long b)
{
    long long ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*a)%p;
        }
        a=(a*a)%p;
        b>>=1;
    }
    return ans;
}

long long cc(int a,int b)
{
    if(a==b||b==0)
    {
        return 1;
    }
    return ((fac[a]*inv[b])%p*inv[a-b]%p);
}

long long get_(int x1,int y1,int x2,int y2)
{
    return cc(x2-x1+y2-y1,x2-x1);
}

int main()
{
    fac[1]=1;
    for(int i=2;i<=200000;i++)
    {
        fac[i]=(fac[i-1]*i)%p;
    }
    inv[200000]=kasumi(fac[200000],p-2);
    for(int i=199999;i>=1;i--)
    {
        inv[i]=(inv[i+1]*(i+1))%p;
    }
    scanf("%d%d%d%d",&n,&m,&aa,&bb);

    for(int i=1;i<=n-aa;i++)
    {
        ans+=(get_(1,1,i,bb)*get_(i,bb+1,n,m))%p;
        ans%=p;
    }

    printf("%lld\n",ans);
    return 0;
}