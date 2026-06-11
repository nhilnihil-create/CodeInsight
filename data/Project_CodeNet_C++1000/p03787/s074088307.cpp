#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=100005;

int n,m,cnt,last[N],dep[N],s;
bool vis[N],flag;
struct edge{int to,next;}e[N*4];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

void dfs(int x,int fa)
{
	vis[x]=1;s++;
	for (int i=last[x];i;i=e[i].next)
		if (vis[e[i].to]&&e[i].to!=fa) flag|=dep[x]==dep[e[i].to];
		else if(!vis[e[i].to]) dep[e[i].to]=dep[x]^1,dfs(e[i].to,x);
}

int main()
{
	n=read();m=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		addedge(x,y);
	}
	LL ans=0;int t1=0,t2=0,t3=0;
	for (int i=1;i<=n;i++)
	{
		if (vis[i]) continue;
		flag=0;s=0;
		dfs(i,0);
		if (s==1) ans+=n*2-1,t3++;
		else if (!flag) ans+=2,t1++;
		else ans++,t2++;
	}
	ans-=(LL)t3*(t3-1);
	ans+=(LL)t1*(t1-1)*2+(LL)t2*(t2-1)+(LL)t1*t2*2;
	printf("%lld",ans);
	return 0;
}