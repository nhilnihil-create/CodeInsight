#include <bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int n,k,sum,ans;
int u[N],v[N],d[N];
int cnt,head[N];
struct edge{int next,to;}e[N<<1];

inline void add(int u,int v)
{
	cnt++;
	e[cnt].next=head[u];
	e[cnt].to=v;
	head[u]=cnt;	
}

void dfs(int u,int fa)
{
	for (register int i=head[u]; i; i=e[i].next)
	if (e[i].to!=fa)
	{
		d[e[i].to]=d[u]+1;
		dfs(e[i].to,u);
	}
}

int main(){
	scanf("%d%d",&n,&k);
	for (register int i=1; i<n; ++i) scanf("%d%d",&u[i],&v[i]),add(u[i],v[i]),add(v[i],u[i]);
	ans=n;
	if (k%2==0)
	{
		for (register int i=1; i<=n; ++i)
		{
			memset(d,0,sizeof(d));
			d[i]=0;
			dfs(i,0);
			sum=0;
			for (register int j=1; j<=n; ++j) sum+=(d[j]>k/2);
			ans=min(ans,sum);
		}
	}
	else
	{
		for (register int i=1; i<n; ++i)
		{
			memset(d,0,sizeof(d));
			d[u[i]]=0; d[v[i]]=0;
			dfs(u[i],v[i]); dfs(v[i],u[i]);
			sum=0;
			for (register int j=1; j<=n; ++j) sum+=(d[j]>k/2);
			ans=min(ans,sum);
		}	
	}
	printf("%d\n",ans);
return 0;
}