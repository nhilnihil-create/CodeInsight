#include<bits/stdc++.h>
using namespace std;
const int N=2005;
vector<int>e[N];
int dep[N]={-1},n,k,sum,b1,b2,ans=2000;
void dfs(int u,int f)
{
	dep[u]=dep[f]+1;
	if(dep[u]>k/2)
		sum++;
	for(int i=0;i<e[u].size();i++)
		if(e[u][i]!=f)
			dfs(e[u][i],u);
}
void dfs2(int u,int f)
{
	dep[u]=dep[f]+1;
	if(dep[u]>k/2)
		sum++;
	for(int i=0;i<e[u].size();i++)
		if(e[u][i]!=f&&e[u][i]!=b1&&e[u][i]!=b2)
			dfs2(e[u][i],u);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	if(k%2==0)
	{
		for(int i=1;i<=n;i++)
		{
			sum=0;
			dfs(i,0);
			ans=min(ans,sum);
		}
		printf("%d\n",ans);
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<e[i].size();j++)
			{
				sum=0;
				b1=i;
				b2=e[i][j];
				dfs2(b1,0);
				dfs2(b2,0);
				ans=min(ans,sum);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
