#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define rep(i,s,t) for (register int i=s;i<=t;i++)
#define drep(i,s,t) for (register int i=s;i>=t;i--)
#define N 100000
using namespace std;
int n,m,a[N+5],blo[N+5],L[N+5],R[N+5],s,bs,to[N+5],t[N+5],nex[N+5];
int query(int l,int r)
{
    int ans=0;
    while (blo[l]<blo[r])
        ans+=t[l],l=nex[l];
    while (l<r)
        ans++,l=to[l];
    return ans;
}
int main()
{
    scanf("%d",&n);
    bs=sqrt(n);
    rep(i,1,n)
    {
        scanf("%d",&a[i]);
        blo[i]=(i-1)/bs+1;
        if (!L[blo[i]])
            L[blo[i]]=i;
        R[blo[i]]=i;
    }
    scanf("%d",&s);
    rep(i,1,n)
    {
        if (upper_bound(a+1,a+n+1,a[i]+s)!=a+n+1)
            to[i]=(upper_bound(a+1,a+n+1,a[i]+s)-a-1);
        else
            to[i]=n;
    }
    drep(i,n,1)
    {
        if (to[i]>=R[blo[i]])
            t[i]=1,nex[i]=to[i];
        else
            if (blo[to[i]]==blo[i])
                t[i]=t[to[i]]+1,nex[i]=nex[to[i]];
            else
                t[i]=1,nex[i]=to[i];
    }
    scanf("%d",&m);
    int l,r;
    rep(i,1,m)
    {
        scanf("%d%d",&l,&r);
        if (l>r)
            swap(l,r);
        printf("%d\n",query(l,r));
    }
    return 0;
}