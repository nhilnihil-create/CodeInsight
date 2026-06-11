#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
int nxt[N<<1],to[N<<1],head[N],cnt;
void add(int u,int v)
{
	nxt[++cnt]=head[u];
	to[cnt]=v;
	head[u]=cnt;
}
int n;
int ans[N],tot;
int siz[N];
bool dfs(int u,int pre)
{
	siz[u]=1;
	if(u==n){ans[++tot]=u;return true;}
	bool can=false;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
        if(v==pre)continue;
        if(dfs(v,u)) can=true;
        siz[u]+=siz[v];
 	}
 	if(can) ans[++tot]=u;
	return can;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	int res=0;
	for(int i=tot;i>tot/2;i--)
	res+=siz[ans[i]]-siz[ans[i-1]];
	puts(res*2>n?"Fennec":"Snuke");
	return 0;
}
