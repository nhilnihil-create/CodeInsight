#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
using namespace std;
#define eps 1e-7
#define maxi 100005
long long  h[maxi];
long long  n,a,b;
long long in=10000000000;
bool C(long long  x)
{
    long long t=x;
    long z;
    for(long long i=0; i<n; i++)
    {
        z=h[i]-x*b;
        if(z<=0) continue;
        long long y;
        y=ceil(z*1.0/(a-b));
        t-=y;
    }
    if(t>=0) return true;
    return false;
}
void solve()
{
    sort(h,h+n);
    long long  lb=0,ub=in;
    while(ub-lb>1)
    {
        long long mid=(lb+ub)/2;
        if(C(mid)) ub=mid;
        else  lb=mid;
    }
    cout<<ub<<endl;
}
int main()
{
    while(cin>>n>>a>>b)
    {
        for(int i=0; i<n; i++)  scanf("%d",&h[i]);
        solve();
    }
    return 0;
}

