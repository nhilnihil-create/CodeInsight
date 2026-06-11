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
long long hi[maxi];
long long  n,a,b;
long long in=10000000000;
bool C(long long  x)
{
    long long t=x;
    for(long long i=0; i<n; i++)
        hi[i]=h[i];
    for(long long i=0; i<n; i++)
    {
        hi[i]-=x*b;
        if(hi[i]<=0) continue;
        long long y;
        if(hi[i]%(a-b)==0)
            y=hi[i]/(a-b);
        else
            y=hi[i]/(a-b)+1;
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
