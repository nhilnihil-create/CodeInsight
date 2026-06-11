/***********************
*  Date: 2018.11.28    *
*  Problem:            *
*  Author: xuziyuan    * 
***********************/

#include <bits/stdc++.h>

#define rt0 return 0
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define replet(c) for(char c='a';c<='z';c++)
#define LL long long
#define pii pair <int,int>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair
#define sqr(a) ((a)*(a))

using namespace std;

const LL MOD=1e9+7;

int n,m,q,co[100010],most[100010];
vector <int> g[100010];
vector <pair<int,pii> > qs;
bool vis[100010];

void dfs(int pos,int now,int all,int colo)//dfs不能有vis数组 
{
	if(all-now<=most[pos]) return;
	most[pos]=all-now;
	if(co[pos]==0) co[pos]=colo;
	if(now==all) return;
	rep(i,g[pos].size()) dfs(g[pos][i],now+1,all,colo);
}

int main()
{
	cin>>n>>m;
	memset(most,-1,sizeof(most));
	rep(i,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].pb(y);
		g[y].pb(x);
	}
	cin>>q;
	rep(i,q)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		qs.pb({x,{y,z}});
	}
	reverse(qs.begin(),qs.end());
	rep(i,q)
	{
		dfs(qs[i].fi,0,qs[i].se.fi,qs[i].se.se);
	}
	repn(i,n) printf("%d\n",co[i]);
	rt0;
}