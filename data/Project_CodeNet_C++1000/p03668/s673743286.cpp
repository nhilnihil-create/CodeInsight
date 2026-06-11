#include<bits/stdc++.h>
#define llong long long
using namespace std;

const int N = 1e5;
struct Edge
{
	int v,nxt;
} e[(N<<1)+3];
int fe[N+3];
int sg[N+3];
int n,en;

void addedge(int u,int v)
{
	en++; e[en].v = v;
	e[en].nxt = fe[u]; fe[u] = en;
}

void dfs(int u,int prv)
{
	for(int i=fe[u]; i; i=e[i].nxt)
	{
		int v = e[i].v;
		if(v==prv) continue;
		dfs(v,u);
		sg[u] ^= sg[v];
	}
	if(u!=1) sg[u]++;
}

int main()
{
	scanf("%d",&n);
	for(int i=1; i<n; i++)
	{
		int u,v; scanf("%d%d",&u,&v);
		addedge(u,v); addedge(v,u);
	}
	dfs(1,0);
	if(sg[1]) puts("Alice");
	else puts("Bob");
	return 0;
}