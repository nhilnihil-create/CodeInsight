#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=100005;

int n,m,cnt,last[N],dep[N],a[N],fa[N],ans,bz[N][20],bin[20],c[N],tim,dfn[N],mx[N];
struct edge{int to,next;}e[N];

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
}

void dfs(int x)
{
	dep[x]=dep[fa[x]]+1;dfn[x]=++tim;
	bz[x][0]=fa[x];
	for (int i=1;i<=16;i++) bz[x][i]=bz[bz[x][i-1]][i-1];
	for (int i=last[x];i;i=e[i].next)
		dfs(e[i].to);
	mx[x]=tim;
}

bool cmp(int x,int y)
{
	return dep[x]>dep[y];
}

int get(int x)
{
	for (int i=16;i>=0;i--)
		if ((m-1)&bin[i]) x=bz[x][i];
	return x;
}

void ins(int x,int y)
{
	while (x<=n) c[x]+=y,x+=x&(-x);
}

int find(int x)
{
	int ans=0;
	while (x) ans+=c[x],x-=x&(-x);
	return ans;
}

int main()
{
	bin[0]=1;
	for (int i=1;i<=16;i++) bin[i]=bin[i-1]*2;
	n=read();m=read();
	for (int i=1;i<=n;i++)
	{
		int x=read();
		if (i==1) ans+=x!=1;
		else addedge(x,i),fa[i]=x;
	}
	dfs(1);
	for (int i=1;i<=n;i++) a[i]=i;
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++)
	{
		int x=a[i];
		if (dep[x]<=m+1||find(dfn[x])) continue;
		int y=get(x);
		ins(dfn[y],1);ins(mx[y]+1,-1);
		ans++;
	}
	printf("%d",ans);
	return 0;
}