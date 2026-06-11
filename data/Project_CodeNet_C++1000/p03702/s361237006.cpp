#include <bits/stdc++.h>
using namespace std;

int n;
long long a,b;

long long h[100005];
long long r[100006];

bool check(long long x)
{
    for(int i=1;i<=n;i++)
        r[i]=max(h[i]-b*x,0ll);
    for(int i=1;i<=n;i++)
    {
        x-=(r[i]+a-b-1)/(a-b);
    }
    if(x<0)return false;
    return true;
}

long long erfen(long long l,long long r)
{
    if(l==r)
        return l;
    int mid=(l+r)/2;
    if(check(mid))return erfen(l,mid);
    else return erfen(mid+1,r);
}

int main()
{
    scanf("%d%lld%lld",&n,&a,&b);
    for(int i=1;i<=n;i++)
        scanf("%lld",&h[i]);
    printf("%lld",erfen(0,1e9));
    return 0;
}
