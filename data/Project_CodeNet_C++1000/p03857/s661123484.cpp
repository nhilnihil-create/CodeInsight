#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
#define MAXN 200006
using namespace std;
int n,K,L,fa[3][MAXN],u,v,sum[MAXN];
vector<int> road[MAXN];
map<int,int> ma;
int root(int x,int op)
{
	if(fa[op][x]==x) return x;
	fa[op][x]=root(fa[op][x],op);
	return fa[op][x];
}
int main()
{
	scanf("%d%d%d",&n,&K,&L);
	for(int i=1;i<=n;i++)
	{
		fa[0][i]=i;
		fa[1][i]=i;
	}
	for(int i=1;i<=K;i++)
	{
		scanf("%d%d",&u,&v);
		fa[0][root(u,0)]=root(v,0);
	}
	for(int i=1;i<=L;i++)
	{
		scanf("%d%d",&u,&v);
		fa[1][root(u,1)]=root(v,1);
	}
	for(int i=1;i<=n;i++)
		road[root(i,0)].push_back(i);
	for(int i=1;i<=n;i++)
	{
		ma.clear();
		for(int j=0;j<(int)road[i].size();j++)
			ma[root(road[i][j],1)]++;
		for(int j=0;j<(int)road[i].size();j++)
			sum[road[i][j]]+=ma[root(road[i][j],1)];
	}
	for(int i=1;i<=n;i++)
		printf("%d ",sum[i]);
}