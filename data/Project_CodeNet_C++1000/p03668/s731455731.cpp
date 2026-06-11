#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;
int n,i,sg[200005];
vector<int> adj[200005];
void dfs(int x,int fa)
{
	int i;
	for(i=0;i<adj[x].size();i++)if(adj[x][i]!=fa)
	{
		dfs(adj[x][i],x);
		sg[x]^=(sg[adj[x][i]]+1);
	}
}
int main()
{
	cin>>n;
	rep(i,n-1)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1,0);
	if(sg[1]) puts("Alice");else puts("Bob");
	return 0;
}