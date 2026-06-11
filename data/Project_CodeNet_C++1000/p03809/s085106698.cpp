#include<cstdio>
#define MAXN 100006
#include<algorithm>
#include<vector>
using namespace std;
vector<int> road[MAXN];
long long d[MAXN],a[MAXN];
int n,u,v,du[MAXN];
void DFS(int x,int father)
{
	if(du[x]==1)
	{
		d[x]=a[x];
		return;
	}
	long long sum=0,maxone=0;
	for(int i=0;i<(int)road[x].size();i++)
	{
		int nex=road[x][i];
		if(nex==father) continue;
		DFS(nex,x);
		sum+=d[nex];
		maxone=max(maxone,d[nex]);
	}
	if(a[x]>sum||a[x]*2<sum)
	{
		printf("NO");
		exit(0);
	}
	long long p=a[x]*2-sum;
	if(maxone-p>sum-maxone)
	{
		printf("NO");
		exit(0);
	}
	d[x]=p;
}
int main()
{
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		road[u].push_back(v);
		road[v].push_back(u);
		du[u]++;
		du[v]++;
	}
	for(int i=1;i<=n;i++)
		if(du[i]!=1)
		{
			DFS(i,0);
			if(d[i]) printf("NO");
			else printf("YES");
			return 0;
		}
	if(a[1]==a[2]) printf("YES");
	else printf("NO");
}