#include<bits/stdc++.h>
using namespace std;
int a[222222];
int n,l,r,ans,mid;
inline int big(int x,int y,int z){ return a[x]>z&&a[y]>z; }
inline int small(int x,int y,int z){ return a[x]<=z&&a[y]<=z; }
inline bool Trial(int k)
{
    for(register int i=0;i<n-1;++i)
    {
        if(big(n-i,n-i-1,k)||big(n+i,n+i+1,k)) return false;
        if(small(n-i,n-i-1,k)||small(n+i,n+i+1,k)) return true;
    }
    return small(1,1,k);
}
int main()
{
    scanf("%d",&n);
    for(register int i=1;i<(n<<1);++i) scanf("%d",&a[i]);
    l=1;r=n*2-1;
    while(l<r)
    {
        mid=(l+r)/2;
        if(Trial(mid)) r=mid;
        else l=mid+1;
    }
    ans=r;
    printf("%d\n",ans);
    return 0;
}