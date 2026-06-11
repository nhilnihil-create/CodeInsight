#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
bitset<50>bit;
/*
bit.reset(); bit=n; bit.count();
*/
#define _for(i,a,b) for( int i=(a); i<(b); ++i)
#define rof(i,a,b)  for( int i=b-1;i>=a;i--)
#define rep(i,a,b)  for( int i=(a); i<=(b); ++i)
#define per(i,a,b)  for( int i=(b); i>=a; --i)
#define sd(n) scanf("%d",&n)
#define sdd(n,m) scanf("%d %d",&n,&m)
#define sddd(n,m,k) scanf("%d %d %d",&n,&m,&k)
#define pd(n)    printf("%d\n",n)
#define pd_(n)   printf("%d ",n)
#define pdd(n,m) printf("%d %d",n,m)
#define pddd(n,m,k) printf("%d %d %d",n,m,k)
#define pld(n) printf("%lld\n",n)
#define pldd(n,m) printf("%lld %lld\n",n,m)
#define sld(n)   scanf("%lld",&n)
#define sldd(n,m) scanf("%lld %lld",&n,&m)
#define slddd(n,m,k) scanf("%lld %lld %lld",&n,&m,&k)
#define sf(n)    scanf("%lf",&n)
#define sff(n,m) scanf("lf",&n,&m)
#define sfff(n,m,k) scanf("%lf %lf %lf",&n,&m,&k)
#define ss(str)  scanf("%s",str)
#define mm(a,n)  memset(a, n, sizeof(a))
#define debug(x) cout << #x << ": " << x << endl
#define pb push_back
#define fi first
#define se second
#define mod(x) ((x)%MOD)
typedef long long ll;
typedef pair<int,int> PII;
typedef unsigned long long ull;
typedef long double ld;
const int N=1e5+7;
const int MOD = 1e9 + 7;
//const double eps = 1e-9;
const double PI=atan(1.0)*4;
const int maxn=3e5+5;
int h[N];
int n,a,b;
bool check(ll mid)
{
    ll temp=mid*b;
    ll sub=a-b;
    ll sum=0;
    for(int i=n;i>0;i--)
    {
        if(h[i]>temp)
        {
            if((h[i]-temp)%sub)
                sum+=(h[i]-temp)/sub+1;
            else
                sum+=(h[i]-temp)/sub;
        }
    }
    if(sum<=mid)
        return true;
    return false;
}
int main()
{
    sddd(n,a,b);
    ll l,r;
    for(int i=1;i<=n;i++)
        {
            sd(h[i]);
            r+=h[i]/b+1;
        }
    sort(h+1,h+1+n);
    l=1;
    while(l<r)
    {
        ll mid=(l+r)>>1;
        if(check(mid))
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    pld(l);
    return 0;
}
