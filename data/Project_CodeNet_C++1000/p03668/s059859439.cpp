//Heaplax
#include<bits/stdc++.h>
#define N 100005
#define LL long long
#define LOG(x) cerr<<#x<<" = "<<x<<endl
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;
}
using namespace std;
int n,sg[N];
int cnt,head[N],nxt[N+N],to[N+N];
void dfs(int u,int fa=0)
{
	for(int i=head[u],v;i;i=nxt[i])
		if((v=to[i]) != fa)
		{
			dfs(v,u);
			sg[u]^=(sg[v]+1);
		}
}
int main()
{
	re(n);
	for(int i=1,u,v;i<n;++i)
	{
		re(u),re(v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1);
	puts(sg[1]?"Alice":"Bob");
}
