#include <bits/stdc++.h>
using namespace std;
struct edge
{
	int v,nxt;
} vs[300000];
int sign[100010][15],q;
int n,m,st[100010],ee,col[100010];
inline void addedge(int u,int v)
{
	vs[++ee].v=v ;
	vs[ee].nxt=st[u];
	st[u]=ee;
}
void calc(int u,int d,int c)
{
	if(sign[u][d]) return ;
	sign[u][d]=1;
	if(d==0)
	{
		col[u]=c;
		return;
	}
	calc(u,d-1,c);
	for(int i=st[u]; i; i=vs[i].nxt)
		calc(vs[i].v,d-1,c);
}
void work(int cnt)
{
	if(cnt==0) return ;
	int u,d,c;
	scanf("%d%d%d",&u,&d,&c);
	work(cnt-1);
	calc(u,d,c);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	scanf("%d",&q);
	work(q);
	for(int i=1; i<=n; i++) printf("%d\n",col[i]);
	return 0 ;
}
