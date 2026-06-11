#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> g[2100];
bool check[2100] = {};
int num = 0,n,m;

int dfs(int x,int k)
{
	if (k < 0) return 0;
	num++;
	if (g[x].size() == 0)	return 1;
	int maxdeep = 0;
	for (int i = 0;i<g[x].size();i++)
	if (check[g[x][i]] == 0)
	{
		check[g[x][i]] = 1;
		maxdeep = max(maxdeep,dfs(g[x][i],min(k - 1,m - maxdeep - 1)));
	}
	return maxdeep + 1;	
}

int main()
{
	cin>>n>>m;
	for (int i = 1,u,v;i<=n-1;i++)
	{
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans = 2147483647;
	for (int i = 1;i<=n;i++) 
	{
		check[i] = 1;
		dfs(i,m);
		if (ans > n - num) ans = n - num;
		num = 0;
		memset(check,0,sizeof(check));
	}
	cout<<ans;
	return 0;
}