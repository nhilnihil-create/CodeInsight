#include<bits/stdc++.h>
using namespace std;
const int maxn=101000;

struct edge{
	int to,nxt;
}e[maxn<<1];
int head[maxn],tot,n,m,q,dis[maxn],col[maxn];
void add(int x,int y)
{
	e[++tot].to=y;
	e[tot].nxt=head[x];
	head[x]=tot;
}

struct opte{
	int p,d,c;
}opt[maxn];

void dfs(int x,int d,int c)
{
	if(dis[x]>=d)return ;//剪枝 
	dis[x]=d;
	if(!col[x])col[x]=c;//最后一次的颜色 
	if(!d)return ;
	for(int i=head[x];i;i=e[i].nxt)
	{
		int y=e[i].to;
		dfs(y,d-1,c);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	memset(dis,-1,sizeof(dis));
	scanf("%d",&q);
	for(int i=1;i<=q;i++)scanf("%d%d%d",&opt[i].p,&opt[i].d,&opt[i].c);
	for(int i=q;i>=1;i--)
		dfs(opt[i].p,opt[i].d,opt[i].c);
	for(int i=1;i<=n;i++)cout<<col[i]<<"\n";
}
