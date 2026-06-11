#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2010;
struct node
{
	int x,y;
}e[MAXN];
int head[MAXN],ver[MAXN<<1],nxt[MAXN<<1],deep[MAXN];
int n,k,tot;
void add(int x,int y)
{
	ver[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
void dfs(int x,int f,int dp)
{
	deep[x]=dp;
	for (int i=head[x];i;i=nxt[i])
	{
		int y=ver[i];
		if (y==f) continue;
		dfs(y,x,dp+1);
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&e[i].x,&e[i].y);
		add(e[i].x,e[i].y);
		add(e[i].y,e[i].x);
	}
	int ans=0x3f3f3f3f;
	if (k&1)
	{
		for (int i=1;i<n;i++)
		{
			int cnt=0;
			dfs(e[i].x,e[i].y,0);
			dfs(e[i].y,e[i].x,0);
			for (int j=1;j<=n;j++) if (deep[j]>(k-1)/2) cnt++;
			ans=min(ans,cnt);
		}
	}
	else 
	{
		for (int i=1;i<=n;i++)
		{
			int cnt=0;
			dfs(i,0,0);
			for (int j=1;j<=n;j++)
			if (deep[j]>k/2) cnt++;
			ans=min(ans,cnt);
		}
	}
	printf("%d\n",ans);
	return 0;
}