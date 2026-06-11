//Heaplax
//别让自己后悔
#include<bits/stdc++.h>
#define N 100001
#define int long long
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
int n,a[N],f[N],d[N];
int cnt,head[N],nxt[N+N],to[N+N];
void dp(int u,int fa)
{
	if(d[u]==1)
	{
		f[u]=a[u];
		return;
	}
	int sum=0,mx=0;
	for(int i=head[u],v;i;i=nxt[i])
		if((v=to[i]) != fa)
		{
			dp(v,u);
			sum+=f[v];
			mx=max(mx,f[v]);
		}
	f[u]=2*a[u]-sum;
	// LOG(u);
	// LOG(f[u]);
	if(a[u]>sum || f[u]<0 || mx-f[u]>sum-mx)
	{
		puts("NO");
		exit(0);
	}
}
/*
x+2*(a[i]-x) = sum
x=2*a[i]-sum
*/
main()
{
	re(n);
	for(int i=1;i<=n;++i)re(a[i]);
	if(n==2)
	{
		puts(a[1]==a[2]?"YES":"NO");
		return 0;
	}
	for(int i=1,u,v;i<n;++i)
	{
		re(u),re(v);
		++d[u],++d[v];
		add_edge(u,v);
		add_edge(v,u);
	}
	int rt;
	for(int i=1;i<=n;++i)
		if(d[i]>=2)
			rt=i;
	// cerr<<rt<<endl;
	dp(rt,0);
	// cerr<<233<<endl;
	puts(f[rt]?"NO":"YES");
}
