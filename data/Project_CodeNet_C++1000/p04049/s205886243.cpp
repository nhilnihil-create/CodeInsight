#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
const int M=2005;
vector<int> g[M];
int n,k;
int dfs(int u,int fa,int d,int md)
{
	if(d>md) return 0;
	int ans=1;
	for(int v:g[u])
	{
		if(v==fa) continue;
		ans+=dfs(v,u,d+1,md);
	}
	return ans;
}

int main()
{
	scanf("%d%d",&n,&k);
	int u,v;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans=n;
	for(int i=1;i<=n;i++)
	{
		int nans=1,diff=0;
		for(int v:g[i])
		{
			int a=dfs(v,i,1,k/2);
			int b=dfs(v,i,1,(k+1)/2);
			diff=max(diff,b-a);
			nans+=a;
		}
		nans+=diff;
		ans=min(ans,n-nans);
	}
	printf("%d\n",ans);
	return 0;
}