#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+10;

int n,a[maxn],deg[maxn];
int tote,FIR[maxn],TO[maxn],NEXT[maxn];
bool vis[maxn],leaf[maxn];
queue<int> q;
vector<int> son[maxn];

void addedge(int u,int v)
{
	TO[++tote]=v;
	NEXT[tote]=FIR[u];
	FIR[u]=tote;
}

int main()
{
#ifdef h10
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int i,u,v;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
		deg[u]++; deg[v]++;
	}
	for (i=1;i<=n;i++)
		if (deg[i]==1) leaf[i]=1,q.push(i);
	while (!q.empty())
	{
		u=q.front(); q.pop();
		vis[u]=1;
		if (!leaf[u])
		{
			int sum=0,mx=0;
			for (i=0;i<(int)son[u].size();i++)
				sum+=son[u][i],mx=max(mx,son[u][i]);
			int A=sum-a[u],B=a[u]-A;
			if (A<0||B<0) {puts("NO"); return 0;}
			if (sum-mx<A) {puts("NO"); return 0;}
			a[u]=B;
		}
		if (!deg[u]) break;
		for (int p=FIR[u];p;p=NEXT[p])
		{
			int v=TO[p];
			if (vis[v]) continue;
			deg[v]--;
			if (deg[v]==1) q.push(v);
			if (leaf[v])
			{
				int times=min(a[u],a[v]);
				a[u]-=times; a[v]-=times;
			}
			else son[v].push_back(a[u]),a[u]=0;
		}
	}
	for (i=1;i<=n;i++)
		if (a[i]) {puts("NO"); return 0;}
	puts("YES");
}
