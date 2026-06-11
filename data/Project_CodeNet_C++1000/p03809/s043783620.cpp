#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100010
#define LL long long
LL a[MAXN];
int Adj[MAXN],V[MAXN*2],nxt[MAXN*2],c,du[MAXN],n;
void AddEdge(int u,int v)
{
	c++;V[c]=v,nxt[c]=Adj[u];Adj[u]=c;
}
LL s[MAXN];
void dfs(int u,int p)
{
	if(du[u]==1)
	{
		s[u]=a[u];
		return;
	}
	LL sum=0;
	for(int i=Adj[u];i;i=nxt[i])
		if(V[i]!=p)
		{
			dfs(V[i],u);
			sum+=s[V[i]];
		}
	if(sum<a[u]||sum>a[u]*2)
	{
		printf("NO\n");
		exit(0);
	}
	if(sum==a[u])
	{
		s[u]=sum;
		return;
	}
	s[u]=2*a[u]-sum;
	LL left=sum-a[u],ls=0,al=0;
	for(int i=Adj[u];i&&left;i=nxt[i])
		if(V[i]!=p)
		{
			LL k=s[V[i]];
			LL del=min(min(k,ls),left);
			k-=del,left-=del,ls-=del;
			if(k>1&&al&&left)
			{
				LL p=k/2;
				LL ed=min(min(p,al),left);
				left-=ed;
				k-=ed*2;
				al+=ed;
			}
			ls+=k;
			al+=del;
		}
	if(left)
	{
		printf("NO\n");
		exit(0);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	int u,v;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		du[u]++,du[v]++;
		AddEdge(u,v);
		AddEdge(v,u);
	}
	if(n==2)
	{
		if(a[1]==a[2])
			printf("YES\n");
		else printf("NO\n");
		return 0;
	}
	int rt=1;
	for(int i=1;i<=n;i++)
		if(du[i]>1)
		{
			rt=i;
			break;
		}
	dfs(rt,0);
	if(s[rt]) printf("NO\n");
	else printf("YES\n");
}
