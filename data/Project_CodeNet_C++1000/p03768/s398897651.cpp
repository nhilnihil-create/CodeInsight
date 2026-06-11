#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=100005,MAXM=200005;
int n,m,q;
int cl[MAXN],co[MAXN];
struct edge
{
	int v,nxt;
	edge(){}
	edge(int vv,int nn)
	{
		v=vv,nxt=nn;
	}
}E[MAXM];
int w[MAXN],ncnt=0;
void addedge(int u,int v)
{
	E[++ncnt]=edge(v,w[u]);
	w[u]=ncnt;
	E[++ncnt]=edge(u,w[v]);
	w[v]=ncnt;
}
struct node
{
	int u,t,id;
	node(){}
	node(int uu,int tt,int ii)
	{
		u=uu,t=tt,id=ii;
	}
	bool operator<(const node &a)const
	{
		if(a.t==t)
			return a.id>id;
		return a.t>t;
	}
};
struct Que
{
	int v,d,c;
}que[MAXN];
priority_queue<node>Q;
int main()
{
	//freopen("splatter.in","r",stdin);
	//freopen("splatter.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		addedge(u,v);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int v,d,c;
		scanf("%d %d %d",&v,&d,&c);
		Q.push(node(v,d,i));
		co[i]=c;
	}
	while(!Q.empty())
	{
		node x=Q.top();
		Q.pop();
		if(cl[x.u]>=x.id)
			continue;
		cl[x.u]=x.id;
		if(x.t==0)
			continue;
		for(int i=w[x.u];i;i=E[i].nxt)
		{
			int v=E[i].v;
			if(cl[v]>=x.id)
				continue;
			Q.push(node(v,x.t-1,x.id));
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",co[cl[i]]);
	}
	fclose(stdin);
	fclose(stdout);
}