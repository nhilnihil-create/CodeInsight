#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<int> mp[2001];
int tim[2001][2001];
vector<int> sidea,sideb;
void dfs(int x,int from,int root,int d)
{
	int i,t;
	tim[root][x]=d;
	for(i=0;i<mp[x].size();i++)
	{
		t=mp[x][i];
		if(t!=from)
			dfs(t,x,root,d+1);
	}
}
int main()
{
	int ans,now,a,b,i,j;
	cin>>n>>k;
	for(i=1;i<n;i++)
	{
		cin>>a>>b;
		mp[a].push_back(b);
		mp[b].push_back(a);
		sidea.push_back(a);
		sideb.push_back(b);
	}
	for(i=1;i<=n;i++)
		dfs(i,-1,i,0);
	ans=0;
	for(i=1;i<=n;i++)
	{
		now=0;
		for(j=1;j<=n;j++)
			if(2*tim[i][j]<=k)
				now++;
		ans=max(ans,now);
	}
	for(i=0;i<sidea.size();i++)
	{
		a=sidea[i];
		b=sideb[i];
		now=0;
		for(j=1;j<=n;j++)
			if(2*min(tim[j][a],tim[j][b])+1<=k)
				now++;
		ans=max(ans,now);
	}
	cout<<n-ans<<endl;
	return 0;
}