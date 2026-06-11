#include <iostream>
#include <cstring>
#include <cstdio>
#define M 100010

using namespace std;

long long num[M];
long long n,a,b;

bool cheak(long long x)
{
    long long cn=a-b;
    long long gl=0;
    for(int i=0; i<n; i++)
    {
        long long re=num[i]-b*x;
        if(re<=0)
            continue;
        else
        {
            gl+=re/cn;
            gl+=(re%cn!=0);
            if(gl>x)
                return false;
        }
    }
    if(gl>x)
        return false;
    return true;
}
int main()
{
    long long l=0,r=1e9;
    long long ans=r;
    scanf("%lld%lld%lld",&n,&a,&b);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&num[i]);
    }
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if(cheak(mid))
        {
            r=mid-1;
            ans=min(mid,ans);
        }
        else
            l=mid+1;
    }
    printf("%lld\n",ans);
    return 0;
}
