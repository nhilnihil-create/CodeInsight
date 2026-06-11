#include <bits/stdc++.h>
#define res register int
using namespace std;

inline int read()
{
	char ch=getchar();
	int x=0,f=0;
	while(ch<'0'||ch>'9')
	{
		f|=ch=='-';
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f?-x:x;
}
struct eric
{
	int to,next;
}edge[400005];
int head[200005],size,ans;
int n,fa[200005],m,maxp[200005];
inline void add(int x,int y)
{
	edge[++size].to=y;
	edge[size].next=head[x];
	head[x]=size;
}
inline void dfs(int pos,int fa)
{
	maxp[pos]=0;
	for(int i=head[pos];i;i=edge[i].next)
	{
		int v=edge[i].to;
		dfs(v,pos);
		maxp[pos]=max(maxp[pos],maxp[v]+1);
	}
	if(maxp[pos]>=m-1&&pos>1&&fa>1)
	++ans,maxp[pos]=-1;
}
int main(void)
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		fa[i]=read();
	}
	if(fa[1]!=1)
	{
		ans++;
		fa[1]=1;
	}
	for(int i=2;i<=n;i++)
	add(fa[i],i);
	dfs(1,1);
	printf("%d\n",ans);
}