#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <set>
#include <bitset>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>
#define rep(i,m,n) for(i=m;i<=n;i++)
#define mod 1000000007
#define inf 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pi acos(-1.0)
#define pii pair<int,int>
#define sys system("pause")
const int maxn=1e5+10;
const int N=2e5+10;
using namespace std;
int id(int l,int r){return l+r|l!=r;}
ll gcd(ll p,ll q){return q==0?p:gcd(q,p%q);}
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p%mod;p=p*p%mod;q>>=1;}return f;}
int n,m,k,t,a[maxn],b[maxn],op[maxn],cnt;
int main()
{
    int i,j;
    ll p;
    scanf("%lld",&p);
    p++;
    while(p>=2)
    {
        if(p&1)op[++cnt]=1,p--;
        else op[++cnt]=2,p/=2;
    }
    printf("%d\n",2*cnt);
    int l=1,r=cnt;
    rep(i,1,cnt)
    {
        if(op[i]==1)a[l++]=cnt-i+1;
        else a[r--]=cnt-i+1;
    }
    rep(i,1,cnt)b[i]=a[i];
    sort(b+1,b+cnt+1);
    rep(i,1,cnt)printf("%d ",a[i]);
    rep(i,1,cnt)printf("%d%c",b[i],i==cnt?'\n':' ');
    return 0;
}
