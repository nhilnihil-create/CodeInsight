#include <bits/stdc++.h>
using namespace std;

long long f(long long a[],long long x)
{
    if(x==a[x]);
    else a[x]=f(a,a[x]);
    return a[x];
}
long long a[200010];
long long b[200010];
long long c[200010];
long long d[200010];
int e[200010];
int main()
{

    long long n,m,k;
    long long x,y,i;
    scanf("%lld%lld%lld",&n,&m,&k);
    for(i=1; i<=n; i++)
    {
        a[i]=i;
        b[i]=i;
    }
    while(m--)
    {
        scanf("%lld%lld",&x,&y);
        x=f(a,x);
        y=f(a,y);
        a[x]=y;
    }
    while(k--)
    {
        scanf("%lld%lld",&x,&y);
        x=f(b,x);
        y=f(b,y);
        b[x]=y;
    }
    for(i=1; i<=n; i++)
    {
        c[i]=f(a,i)+(n+1)*f(b,i);
        d[i]=c[i];
    }
    sort(d+1,d+n+1);
    memset(e,0,sizeof(e));
    for(i=1; i<=n; i++)
    {
        y=lower_bound(d+1,d+n+1,c[i])-d;
        e[y]++;
    }
    for(i=1; i<=n; i++)
    {
        y=lower_bound(d+1,d+n+1,c[i])-d;
        if(i==n)printf("%d\n",e[y]);
        else printf("%d ",e[y]);
    }
    return 0;
}
