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
	for(int i=qs.size()-1;i>=0;i--)
	{
		//cout<<qs[i].fi<<' '<<qs[i].se.fi<<' '<<qs[i].se.se<<endl;
		memset(vis,0,sizeof(vis));
		int v=qs[i].fi,colo=qs[i].se.se,dist=qs[i].se.fi;
		queue <pii> q;
		q.push({v,0});
		while(!q.empty())
		{
			int pos=q.front().fi,dist1=q.front().se;
			//cout<<pos<<' '<<colo<<' '<<dist<<' '<<dist1<<endl;
			q.pop();
			if(vis[pos]) continue;
			if(most[pos]>=dist-dist1) continue;
			vis[pos]=true;
			most[pos]=dist-dist1;
			if(co[pos]==0) co[pos]=colo;
			if(dist1==dist) continue;
			rep(j,g[pos].size()) q.push({g[pos][j],dist1+1});
		}
	}
	repn(i,n) printf("%d\n",co[i]);
	rt0;
}