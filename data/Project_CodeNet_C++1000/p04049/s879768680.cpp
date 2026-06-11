#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[5000];
int head[2005],tot=0,n,k,ans,tmp;
void add(int a,int b)
{
	tot++;
	e[tot].v=b;
	e[tot].nxt=head[a];
	head[a]=tot;
}
void dfs(int x,int fa,int dep)
{
	if (dep>k/2) tmp++;
	for (int i=head[x];i!=-1;i=e[i].nxt) if (e[i].v!=fa) dfs(e[i].v,x,dep+1);
}
int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	if (k&1)
	{
		ans=n+1;
		for (int i=1;i<=tot;i+=2)
		{
			tmp=0;
			dfs(e[i].v,e[i+1].v,0);
			dfs(e[i+1].v,e[i].v,0);
			ans=min(ans,tmp);
		}
	}
	else
	{
		ans=n+1;
		for (int i=1;i<=n;i++)
		{
			tmp=0;
			dfs(i,0,0);
			ans=min(ans,tmp);
		}
	}
	printf("%d\n",ans);
}