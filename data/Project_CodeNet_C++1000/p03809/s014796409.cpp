#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=100005;

int n,cnt,last[N],deg[N];
struct edge{int to,next;}e[N*2];
LL f[N],a[N];

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

bool dfs(int x,int fa)
{
	if (deg[x]==1) {f[x]=a[x];return 1;}
	LL mx=0;
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa) continue;
		if (!dfs(e[i].to,x)) return 0;
		f[x]+=f[e[i].to];
		mx=max(mx,f[e[i].to]);
	}
	if (f[x]<a[x]||f[x]-mx<f[x]-a[x]) return 0;
	f[x]-=(f[x]-a[x])*2;
	if (f[x]<0) return 0;
	else return 1;
}

int main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	if (n==2) {puts(a[1]==a[2]?"YES":"NO");return 0;}
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		deg[x]++;deg[y]++;
		addedge(x,y);
	}
	int rt;
	for (int i=1;i<=n;i++) if (deg[i]>1) {rt=i;break;}
	if (!dfs(rt,0)) puts("NO");
	else if (!f[rt]) puts("YES");
	else puts("NO");
	return 0;
}