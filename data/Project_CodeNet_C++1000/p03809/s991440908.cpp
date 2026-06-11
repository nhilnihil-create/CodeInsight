#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<bitset>

using namespace std;

int n;
vector<int> g[110000];
int v[110000];
int du[110000],root;
int sz[110000],f[110000];
void dfs(int x,int fa)
{
	int tmp=0,maxx=0;
	for (int i=0;i<g[x].size();i++)
		if (g[x][i]!=fa) 
		{
			dfs(g[x][i],x),sz[x]+=sz[g[x][i]];
			tmp+=sz[g[x][i]]-f[g[x][i]];
			f[x]+=f[g[x][i]];
			maxx=max(maxx,sz[g[x][i]]-f[g[x][i]]);
		}
	if (sz[x]==0) {sz[x]=v[x];return;}
	if (tmp-v[x]<0) {printf("NO\n");exit(0);}
	int delta=tmp-v[x];
	if (delta+delta>tmp||delta>tmp-maxx) {printf("NO\n");exit(0);}
	f[x]+=delta*2;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
		du[x]++,du[y]++;
	}
	if (n==2)
	{
		if (v[1]==v[2]) printf("YES\n");
		else printf("NO\n");
		return 0;
	}
	for (int i=1;i<=n;i++)
		if (du[i]!=1)
		{
			root=i;
			break;
		}
	int all=0;
	dfs(root,0);
	if (sz[root]!=f[root]) printf("NO\n");
	else printf("YES\n");
	return 0;
}