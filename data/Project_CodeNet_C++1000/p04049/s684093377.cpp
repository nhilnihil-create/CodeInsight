#include<bits/stdc++.h>
#define rep(i,m,n) for(i=m;i<=n;i++)
#define vi vector<int>
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long
const int maxn=2e3+10;
const int dis[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
using namespace std;
using namespace __gnu_cxx;
ll gcd(ll p,ll q){return q==0?p:gcd(q,p%q);}
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}
int n,m,a[maxn][maxn],mi,cnt;
vi p[maxn];
pii q[maxn];
void dfs(int root,int pre,int now,int s)
{
    a[root][now]=s;
	for(ll i=0;i<p[now].size();i++) 
    {
		ll x=p[now][i];
        if(x!=pre)dfs(root,now,x,s+1);
    }
}
int main()
{
    int i,j,k,t;
    mi=inf;
    scanf("%d%d",&n,&k);
    rep(i,1,n-1){
        scanf("%d%d",&j,&t);
        p[j].pb(t),p[t].pb(j);
        q[i].fi=j,q[i].se=t;
    }
    rep(i,1,n)dfs(i,-1,i,0);
    rep(i,1,n)
    {
        cnt=0;
        rep(j,1,n)
            if(2*a[i][j]>k)cnt++;
        mi=min(mi,cnt);
    }
    rep(i,1,n-1)
    {
        cnt=0;
        rep(j,1,n)
            if(2*min(a[j][q[i].fi],a[j][q[i].se])+1>k)
                cnt++;
        mi=min(mi,cnt);
    }
    printf("%d\n",mi);
    //system ("pause");
    return 0;
}