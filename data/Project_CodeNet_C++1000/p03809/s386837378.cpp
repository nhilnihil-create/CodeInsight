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
ll cnt[maxn];
vi e[maxn];
bool flag=true;
void dfs(int x,int y)
{
    if(!flag)return;
    ll p=0;
    for(int z:e[x])
    {
        if(z==y)continue;
        dfs(z,x);
        if(cnt[z]>a[x])
        {
            flag=false;
            return;
        }
        p+=cnt[z];
    }
    if((int)e[x].size()==1)
    {
        cnt[x]=a[x];
    }
    else
    {
        cnt[x]=(ll)2*a[x]-p;
        if(cnt[x]<0||cnt[x]>a[x])
        {
            flag=false;
            return;
        }
    }
}
int main()
{
    int i,j;
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]);
    rep(i,1,n-1)scanf("%d%d",&j,&k),e[j].pb(k),e[k].pb(j);
    if(n==2)
    {
        puts(a[1]==a[2]?"YES":"NO");
        return 0;
    }
    rep(i,1,n)
    {
        if((int)e[i].size()>1)
        {
            dfs(i,-1);
            if(!flag)puts("NO");
            else if(cnt[i]!=0)puts("NO");
            else puts("YES");
            return 0;
        }
    }
    return 0;
}