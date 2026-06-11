#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define MAXN 2000
using namespace std;
vector<int> G[MAXN+5];
int N,K,tot=0;
void DFS(int u,int fa,int depn)
{
	if(depn>K)
		return;
	tot++;//可以计算深度小于等于K/2的，然后用总数来减，比较好想。
	for(int i=0;i<(int)G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)
			continue;
		DFS(v,u,depn+1);
	}
}
int main()
{
	scanf("%d %d",&N,&K);
	int u,v,typ;
	for(int i=1;i<N;i++)
	{
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(K%2==0)	typ=1;
	else		typ=0;
	int ans=N;
	K/=2;
	if(typ==1)//分情况讨论
	{
		for(int i=1;i<=N;i++)
		{
			tot=0;
			DFS(i,-1,0);//把一个点放在深度0.
			ans=min(ans,N-tot);
		}
	}
	else if(typ==0)
	{
		for(u=1;u<=N;u++)
			for(int j=0;j<(int)G[u].size();j++)
			{
				v=G[u][j];
				tot=0;
				DFS(v,u,0);//把一条边的两个点都放在深度0.
				DFS(u,v,0);
				ans=min(ans,N-tot);
			}
	}
	printf("%d\n",ans);
	return 0;
}