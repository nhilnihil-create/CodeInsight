#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int>g[2222];
int main()
{
	cin>>n>>k;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	vector<vector<int> >mt(n,vector<int>(n,1e9));
	for(int i=0;i<n;i++)
	{
		vector<int>&r=mt[i];
		queue<int>q;
		r[i]=0;
		q.push(i);
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(int j=0;j<g[u].size();j++)
			{
				int v=g[u][j];
				if(r[v]<1e9)
				{
					continue;
				}
				r[v]=r[u]+1;
				q.push(v);
			}
		}
	}
	int ans=1e9;
	if(k%2)
	{
		for(int u=0;u<n;u++)
		{
			for(int j=0;j<g[u].size();j++)
			{
				int v=g[u][j],cnt=0;
				for(int i=0;i<n;i++)
				{
					if(mt[u][i]+mt[v][i]<=k)
					{
						cnt++;
					}
				}
				ans=min(ans,n-cnt);
			}
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			int cnt=0;
			for(int j=0;j<n;j++)
			{
				if(mt[i][j]<=k/2)
				{
					cnt++;
				}
			}
			ans=min(ans,n-cnt);
		}
	}
	cout<<ans<<endl;
	return 0;
}