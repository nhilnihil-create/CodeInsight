#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
ll s[100010];
ll n,a,b;

bool judge(int x)
{
    ll sum=0;
    ll s1=x*b;
    ll s2=a-b;
    for(int i=0;i<n;i++)
    {
        if(s[i]>s1)
        {
            if(((s[i]-s1)%s2)!=0)
                sum+=(s[i]-s1)/s2+1;
            else
                sum+=(s[i]-s1)/s2;
        }
    }
    if(sum<=x)
        return true;
    else
        return false;
}

int main()
{
    while(~scanf("%lld %lld %lld",&n,&a,&b))
    {
        for(int i=0;i<n;i++)
            scanf("%lld",&s[i]);
        sort(s,s+n);
        ll l=1,r=s[n-1]/b+1;
        while(l<=r)
        {
            ll x=(l+r)>>1;
            if(judge(x))
                r=x-1;
            else
                l=x+1;
        }
        printf("%lld\n",l);
    }
    return 0;
}
