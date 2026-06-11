#include <bits/stdc++.h>
#define N 100001
using namespace std;
long long sum[N],a[N],b[N],vt[N],n,i,u,v,kq[N];
long long bs(long long L,long long R)
{
    long long l=1,r=n,vl,vr;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(b[mid]>=L) r=mid; else l=mid+1;
    }
    vl=l;
    l=1; r=n;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(b[mid]<=R) l=mid; else r=mid-1;
    }
    vr=l;
    return sum[vr]-sum[vl-1]-L*(vr-vl+1)+(R-L)*(n-vr);
}
int main()
{
   // freopen("ntu.inp","r",stdin);
   // freopen("ntu.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++) { cin>>a[i]; b[i]=a[i]; }
    sort(b+1,b+n+1);
    for(i=1;i<=n;i++) sum[i]=sum[i-1]+b[i];
    vt[0]=0;
    for(i=1;i<=n;i++)
        if(a[i]>a[vt[i-1]]) vt[i]=i; else vt[i]=vt[i-1];
    u=vt[n];
    while(u>0)
    {
        v=vt[u-1];
        kq[u]=bs(a[v],a[u]);
        u=v;
    }
    for(i=1;i<=n;i++) cout<<kq[i]<<'\n';
}
