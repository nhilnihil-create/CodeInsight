#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
#define ll long long
#define inf int(1e9+7)
#define pb push_back
#define mp make_pair
int n,k;
vector<int>g[2005];
int dfs(int x,int p,int deepth,int mx)
{
	int s=1;
	if(deepth!=mx)
		for(int y=0;y<g[x].size();y++)
		{
			if(g[x][y]==p)
				continue;
			s+=dfs(g[x][y],x,deepth+1,mx);
		}
	return s;
}
int main()
{
	cin>>n>>k;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	int ans=0;
	if(k%2==0)
		for(int v=1;v<=n;v++)
			ans=max(ans,dfs(v,-1,0,k/2));
	else
		for(int v=1;v<=n;v++)
			for(int u=0;u<g[v].size();u++)
				ans=max(ans,dfs(v,g[v][u],0,k/2)+dfs(g[v][u],v,0,k/2));
	cout<<n-ans;
	return 0;
}