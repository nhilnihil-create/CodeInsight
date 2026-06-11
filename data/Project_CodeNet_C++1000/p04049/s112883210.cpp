#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,k;
vector<int>G[2222];
int uk,uk1;
void dfs(int u,int p,int c)
{
	if(c<=k/2)uk++;
	else if(c==(k+1)/2)uk1++;
	for(int i=0;i<G[u].size();i++)
	{
		if(G[u][i]==p)continue;
		dfs(G[u][i],u,c+1);
	}
}
main()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int a,b;cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int ans=n;
	for(int i=1;i<=n;i++)
	{
		uk=1;
		uk1=0;
		int ma=0;
		for(int j=0;j<G[i].size();j++)
		{
			int pre=uk1;
			dfs(G[i][j],i,1);
			ma=max(ma,uk1-pre);
		}
		ans=min(ans,n-uk-ma);
	}
	cout<<ans<<endl;
}