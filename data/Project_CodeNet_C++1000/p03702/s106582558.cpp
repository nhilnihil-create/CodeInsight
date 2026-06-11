#include <bits/stdc++.h>
using namespace std;
long long n,a,b;
const int maxn=1e5+5;
long long p[maxn];
bool check(long long x)
{
    long long sum=0;
    for(int i=n; i>=1; i--)
    {
        long long heal=p[i];
        heal=heal-x*b;
        if(heal<=0)
        {
            continue;
        }
        sum=sum+heal/(a-b);
        if(heal%(a-b)!=0)
        {
            sum++;
        }
        if(sum>x)
            return false;
    }
    return true;
}
int main()
{
    scanf("%lld%lld%lld",&n,&a,&b);
    long long l=1,r=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%lld",&p[i]);
        r=r+p[i]/a+1;
    }
    sort(p+1,p+1+n);
    long long ans;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if(check(mid))
        {
            r=mid-1;
            ans=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    printf("%lld",ans);
    return 0;
}
