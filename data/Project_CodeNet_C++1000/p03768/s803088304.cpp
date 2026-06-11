//************************
//*  Date: 2018.11.30    *
//*  Problem:            *
//*  Author: xuziyuan    * 
//************************
 
#include <bits/stdc++.h>
 
#define rt0 return 0
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define replet(c) for(char c='a';c<='z';c++)
#define LL long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair
#define sqr(a) ((a)*(a))
 
using namespace std;
 
const LL MOD=1e9+7;
 
int n,m,q;
vector <int> g[100010];
int colo[100010],most[100010];
vector <pair<pii,int> > pa;
bool vis[100010];
 
int main()
{
	memset(most,-1,sizeof(most));
	cin>>n>>m;
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
		pa.pb({{x,y},z});
	}
	for(int i=pa.size()-1;i>=0;i--)
	{
		int x=pa[i].fi.fi,y=pa[i].fi.se,z=pa[i].se;
		queue <pii> q;
		q.push({x,0});
		memset(vis,0,sizeof(vis));
		while(!q.empty())
		{
			int pos=q.front().fi,all=q.front().se;
			q.pop();
			if(y-all<=most[pos]) continue;
			most[pos]=y-all;
			if(all>y) continue;
			if(vis[pos]) continue;
			//if(x==1) cout<<pos<<endl;
			vis[pos]=true;
			if(colo[pos]==0) colo[pos]=z;
			rep(i,g[pos].size()) q.push({g[pos][i],all+1});
		}
	}
	repn(i,n) printf("%d\n",colo[i]);
	rt0;
}