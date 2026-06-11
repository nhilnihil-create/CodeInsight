#include<bits/stdc++.h>
#define pb push_back
#define ll long long 
#define pii pair<int,int>
#define MP make_pair
#define F first
#define S second
using namespace std;
const int mx=2010;
int dis[mx];
bool mrk[mx];
vector <int> adj[mx];
vector <pii> vec;
void dfs(int v)
{
	mrk[v]=1;
	long unsigned int t=adj[v].size();
	for(long unsigned int i=0;i<t;i++)
	{
		int u=adj[v][i];
		if(!mrk[u])
		{
			dis[u]=dis[v]+1;
			dfs(u);
		}
	}
}
void dfs1(int v)
{
	mrk[v]=1;
	long unsigned int t=adj[v].size();
	for(long unsigned int i=0;i<t;i++)
	{
		int u=adj[v][i];
		if(!mrk[u])
		{
			dis[u]=min(dis[u],dis[v]+1);
			dfs(u);
		}
	}	
}
int main()
{
	int n,k,ans=3000;
	cin>>n>>k;
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		--u;
		--v;
		adj[v].pb(u);
		adj[u].pb(v);
		vec.pb(MP(u,v));
	}
	if(k%2==0)
	{
		for(int i=0;i<n;i++)
		{
			dis[i]=0;
			dfs(i);
			int cnt=0;
			for(int j=0;j<n;j++)
			{
				if(dis[j]>(k/2))
				{
					cnt++;
				}
				mrk[j]=0;
			}
			ans=min(ans,cnt);
		}
		cout<<ans;	
		return 0;	
	}
	for(int i=0;i<n-1;i++)
	{
		int cnt=0;
		dis[vec[i].F]=0;
		dfs(vec[i].F);
		for(int j=0;j<n;j++)
		{
			mrk[j]=0;
		}
		dis[vec[i].S]=0;
		dfs1(vec[i].S);
		for(int j=0;j<n;j++)
		{
			if(dis[j]>(k/2))
			{
				cnt++;
			}
			mrk[j]=0;
		}
		ans=min(ans,cnt);
	}
	cout<<ans;
}
