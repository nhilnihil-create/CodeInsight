#include<bits/stdc++.h>
using namespace std;
vector<int>g[2222];
int dfs(int v,int f,int k)
{
	if(k==0)
	{
		return 0;
	}
	int ans=1;
	for(int i=0;i<g[v].size();i++)
	{
		if(g[v][i]!=f)
		{
			ans+=dfs(g[v][i],v,k-1);
		}
	}
	return ans;
}
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int bd=0,tl=1;
		for(int j=0;j<g[i].size();j++)
		{
			int t1=dfs(g[i][j],i,k/2),t2=dfs(g[i][j],i,(k+1)/2);
			tl+=t1;
			bd=max(bd,t2-t1);
		}
		ans=max(ans,tl+bd);
	}
	cout<<n-ans<<endl;
	return 0;
}