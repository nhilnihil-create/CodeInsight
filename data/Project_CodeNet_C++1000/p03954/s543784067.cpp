#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 200010
using namespace std;
int n,l,r,mid;
int a[MAXN];
inline bool check_large(int x,int y)
{
    if(a[x]>mid&&a[y]>mid) return true;
    return false;
}
inline bool check_small(int x,int y)
{
    if(a[x]<=mid&&a[y]<=mid) return true;
    return false;
}
inline bool solve()
{
    for(int i=0;i<n-1;i++) 
    {
        if(check_large(n+i,n+i+1)||check_large(n-i,n-i-1)) return true;
        if(check_small(n+i,n+i+1)||check_small(n-i,n-i-1)) return false;
    }
    if(a[1]<=mid) return false;
    else return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n*2-1;i++) scanf("%d",&a[i]);
    l=1,r=2*n-1;
    while(l<r)
    {
        mid=(l+r)>>1;
        if(solve()==true) l=mid+1;
        else r=mid; 
    }
    printf("%d\n",l);
    return 0;
}