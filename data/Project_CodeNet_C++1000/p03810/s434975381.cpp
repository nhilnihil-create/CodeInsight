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
using namespace std;
inline ll gcd(ll p,ll q){return q==0?p:gcd(q,p%q);}
inline ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}
inline void umax(ll &p,ll q){if(p<q)p=q;}
inline void umin(ll &p,ll q){if(p>q)p=q;}
inline ll read()
{
    ll x=0;int f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,k,t,a[maxn];
int dfs()
{
    int cnt1=0,cnt2=0,x,i;
    rep(i,1,n)
    {
        if(a[i]&1)cnt1++,x=i;
        else cnt2++;
    }
    if(cnt2&1)return 0;
    else
    {
        if(cnt1>1)return 1;
        else
        {
            if(--a[x]==0)return 1;
            int y=a[1];
            rep(i,2,n)y=gcd(y,a[i]);
            rep(i,1,n)a[i]/=y;
            return dfs()^1;
        }
    }
}
int main()
{
    int i,j;
    scanf("%d",&n);
    rep(i,1,n)a[i]=read();
    puts(dfs()==0?"First":"Second");
    return 0;
}
