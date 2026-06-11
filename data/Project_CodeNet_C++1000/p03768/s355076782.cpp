#include<cstdio>
#include<vector>
#include<algorithm>
#define MAXN 100006
using namespace std;
int ans[MAXN],u,v,c[MAXN],d[MAXN],p[MAXN],maxone[MAXN],n,m,q;
vector<int> road[MAXN];
void DFS(int x,int fa,int step,int c)
{
	if(maxone[x]>=step) return;
	if(!ans[x]) ans[x]=c;
	maxone[x]=step;
	for(int i=0;i<(int)road[x].size();i++)
	{
		int nex=road[x][i];
		if(nex==fa) continue;
		DFS(nex,x,step-1,c);
	}
}
int main()
{
	//freopen("splatter.in","r",stdin);
	//freopen("splatter.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		road[u].push_back(v);
		road[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		maxone[i]=-1;
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
		scanf("%d%d%d",&p[i],&d[i],&c[i]);
	for(int i=q;i>=1;i--)
		DFS(p[i],0,d[i],c[i]);
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
}