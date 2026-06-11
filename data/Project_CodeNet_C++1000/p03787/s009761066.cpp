#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<vector>
#include<ctime>
#define ll long long
#define pr(x) cerr<<#x<<"="<<x<<endl
using namespace std;
#define N 2010000
struct node
{
	ll to,next;
}e[N*3];
ll size,o,p,vis[N],tag[N],g[N],f,n,m,i,du[N],I,P,Q;
void add(ll o,ll p)
{
	e[++size].to=p;
	e[size].next=g[o];
	g[o]=size;
}
void dfs(ll x)
{
	vis[x]=1;
	for (ll k=g[x];k;k=e[k].next)
	{
		ll y=e[k].to;
		{
			if (vis[y]==0)
			{
				tag[y]=tag[x]^1;
				dfs(y);
			}
			else
			{
				if (tag[x]==tag[y]) f=0;
			}
		}
	}
}
int main()
{
	scanf("%lld %lld",&n,&m);
	for (i=1;i<=m;i++)
	{
		scanf("%lld %lld",&o,&p);
		add(o,p);
		add(p,o);
		du[o]++;du[p]++;
	}
	for (i=1;i<=n;i++)
	{
		if (vis[i]==1) continue;
		if (du[i]==0)
		{
			I++;
			continue;
		}
		f=1;
		dfs(i);
		if (f==1) Q++;
		else P++;
	}
	//pr(I);
	//pr(P);
	//pr(Q);
	ll ans=2*I*n-I*I+P*P+2*P*Q+2*Q*Q;
	printf("%lld\n",ans);
	return 0;
}