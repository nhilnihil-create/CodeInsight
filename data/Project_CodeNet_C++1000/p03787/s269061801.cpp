#include<bits/stdc++.h>
#define N 400005
using namespace std;
int n,m,x,y,to[N],fst[N],nxt[N],a,b,c,flag,vis[N],col[N],l;
void link(int x,int y)
{
	to[++l]=y;nxt[l]=fst[x];fst[x]=l;
	to[++l]=x;nxt[l]=fst[y];fst[y]=l;
}
void dfs(int x,int y)
{
	if (vis[x])
	{
		if (col[x]!=y) flag=1;
		return;
	}
	vis[x]=1;col[x]=y;
	for (int i=fst[x];i;i=nxt[i])
		dfs(to[i],y^1);
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		link(x,y);
	}
	for (int i=1;i<=n;i++)
	{
		if (!vis[i])
		{
			if (fst[i])
			{
				flag=0;
				dfs(i,0);
				if (flag) b++;else c++;
			}
			else a++;
		}
	}
	printf("%lld\n",2LL*a*n-1LL*a*a+1LL*b*b+2LL*c*c+2LL*b*c);
}