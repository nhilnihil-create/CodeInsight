#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
struct graph
{
	int v[200010];
	int t[200010];
	int h[100010];
	int n;
	graph()
	{
		memset(h,0,sizeof h);
		n=0;
	}
	void add(int x,int y)
	{
		n++;
		v[n]=y;
		t[n]=h[x];
		h[x]=n;
	}
};
graph g;
void fail()
{
	printf("NO\n");
	exit(0);
}
int d[100010];
ll f[100010];
int a[100010];
void dfs(int x,int fa)
{
	int c=0;
	int i;
	ll s=0;
	ll mx=0;
	for(i=g.h[x];i;i=g.t[i])
		if(g.v[i]!=fa)
		{
			dfs(g.v[i],x);
			c++;
			s+=f[g.v[i]];
			mx=max(mx,f[g.v[i]]);
		}
	if(!c)
	{
		f[x]=a[x];
		return;
	}
	ll db=s-a[x];
	if(db<0)
		fail();
	ll e;
	if(2*mx<=s)
		e=s/2;
	else
		e=s-mx;
	if(db<=e)
		f[x]=s-2*db;
	else
		fail();
	if(f[x]<0)
		fail();
}
int main()
{
#ifdef DEBUG
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	int n;
	scanf("%d",&n);
	int i,x,y;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n<=2)
	{
		if(a[1]==a[2])
			printf("YES\n");
		else
			printf("NO\n");
		return 0;
	}
	for(i=1;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
		g.add(x,y);
		g.add(y,x);
		d[x]++;
		d[y]++;
	}
	int rt;
	for(i=1;i<=n;i++)
		if(d[i]>=2)
			rt=i;
	dfs(rt,0);
	if(f[rt])
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}