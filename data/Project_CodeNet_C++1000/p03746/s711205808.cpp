//Heaplax
//别让自己后悔
#include<bits/stdc++.h>
#define N 100001
#define M 200001
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
deque<int> que;
bool vis[N];
int n,m;
int cnt,head[N],nxt[M],to[M];
int main()
{
	re(n),re(m);
	for(int u,v,i=1;i<=m;++i)
	{
		re(u),re(v);
		add_edge(u,v);
		add_edge(v,u);
	}

	int u=1;
	while(1)
	{
		vis[u]=1;
		que.push_back(u);
		int v=0;
		for(int i=head[u];i;i=nxt[i])
			if(!vis[to[i]])
			{
				v=to[i];
				break;
			}
		if(!v)break;
		u=v;
	}
	u=1;
	while(1)
	{
		vis[u]=1;
		int v=0;
		for(int i=head[u];i;i=nxt[i])
			if(!vis[to[i]])
			{
				v=to[i];
				break;
			}
		if(!v)break;
		que.push_front(v);
		u=v;
	}
	printf("%d\n",que.size());
	for(int i:que)
		printf("%d ",i);
}
