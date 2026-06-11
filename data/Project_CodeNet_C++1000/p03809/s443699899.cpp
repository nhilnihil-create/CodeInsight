#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define MAXN 100000
using namespace std;
typedef long long LL;
vector<int> G[MAXN+5];
int N,d[MAXN+5];
LL a[MAXN+5],maxval[MAXN+5];
bool DFS(int u,int fa)
{
	LL sum=0;
	bool Enter=false;
	for(int i=0;i<(int)G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa)
			continue;
		Enter=true;
		if(DFS(v,u)==false)
			return false;
		sum+=a[v];
		maxval[u]=max(maxval[u],a[v]);
	}
	if(Enter==false)
	{
		maxval[u]=a[u];
		return true;
	}
	if(2LL*a[u]<sum||a[u]>sum||a[u]<maxval[u])
		return false;
	a[u]=2*a[u]-sum;
	return true;
}
int main()
{
//	freopen("tree.in","r",stdin);
//	freopen("tree.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%lld",&a[i]);
	int u,v;
	for(int i=1;i<N;i++)
	{
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
		d[u]++,d[v]++;
	}
	if(N==2)
	{
		if(a[1]!=a[2])
			printf("NO\n");
		else
			printf("YES\n");
		return 0;
	}
	int rt;
	for(int i=1;i<=N;i++)
		if(d[i]>=2)
		{
			rt=i;
			break;
		}
	if(DFS(rt,-1)==false||a[rt]!=0)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}