#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+10;

int n,tote,FIR[maxn],NEXT[maxn],TO[maxn];

void addedge(int u,int v)
{
	TO[++tote]=v;
	NEXT[tote]=FIR[u];
	FIR[u]=tote;
}

int dfs(int u,int F)
{
	int Ans=0;
	for (int p=FIR[u];p;p=NEXT[p])
	{
		int v=TO[p];
		if (v==F) continue;
		Ans^=dfs(v,u)+1;
	}
	return Ans;
}

int main()
{
#ifdef h10
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int i,u,v;
	scanf("%d",&n);
	for (i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	puts(dfs(1,0)?"Alice":"Bob");
}
