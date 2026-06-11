#include <bits/stdc++.h>
using namespace std;
#define N 110000
int n,tot;
int head[N],nex[N<<1],to[N<<1];
int sg[N];
void add(int x,int y)
{
	tot++;
	nex[tot]=head[x];head[x]=tot;
	to[tot]=y;
}
void dfs(int x,int y)
{
	for(int i=head[x];i;i=nex[i])
		if(to[i]!=y)
		{
			dfs(to[i],x);
			sg[x]^=sg[to[i]]+1;		
		}
}
int main()
{
	//freopen("tt.in","r",stdin);
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	dfs(1,0);
	puts(sg[1] ? "Alice" : "Bob");
	return 0;
}
