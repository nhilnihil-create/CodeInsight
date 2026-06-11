/*QAQ三连：以前的题都补了吗，今天的题都做了吗，不会的算法都会了吗*/
/*金桔退役三连：退役选手不学不会不练*/
#include <bits/stdc++.h>
#define LDQ 1000000007
#define QAQ 0x3f3f3f3f
#define PI 3.14159265358979323846
using namespace std;
long long a[200001],b[200001],c[200001],d[200001],e[200001];
long long find(long long t[],long long x)
{
    if(t[x]==x)
    {
        return x;
    }
    else
    {
        return t[x]=find(t,t[x]);
    }
}
int main()
{
    long long x,y,i,n,k,l;
    scanf("%lld %lld %lld",&n,&k,&l);
    for(i=1;n>=i;i++)
    {
        a[i]=i;
        b[i]=i;
    }
    for(i=1;k>=i;i++)
    {
        scanf("%lld %lld",&x,&y);
        x=find(a,x);
        y=find(a,y);
        a[y]=x;
    }
    for(i=1;l>=i;i++)
    {
        scanf("%lld %lld",&x,&y);
        x=find(b,x);
        y=find(b,y);
        b[y]=x;
    }
    for(i=1;n>=i;i++)
    {
        c[i]=d[i]=find(a,i)+(n+1)*find(b,i);
    }
    sort(d+1,d+n+1);
    for(i=1;n>=i;i++)
    {
        x=lower_bound(d+1,d+n+1,c[i])-d;
        e[x]++;
    }
    for(i=1;n>=i;i++)
    {
        x=lower_bound(d+1,d+n+1,c[i])-d;
        if(i!=1)
        {
            printf(" ");
        }
        printf("%lld",e[x]);
    }
    return 0;
}
