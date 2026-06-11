#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<queue>
#include<vector>
#include<stack>
#include<set>
#define pa pair<int,int>
#define INF 0x3f3f3f3f
#define inf 0x3f
#define fi first
#define se second
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

inline int read()
{
	int f=1,sum=0;
	char c=getchar();
	while (c<'0' || c>'9')
	{
		if (c=='-')	f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum*f;
}
const int MAXN=200010;
struct edge
{
	int next,to;
};
edge e[MAXN];
int head[MAXN],cnt;
void addedge(int u,int v)
{
	e[++cnt].next=head[u];
	e[cnt].to=v;
	head[u]=cnt;
}
int ans,k,to[MAXN],dep[MAXN];
bool visit[MAXN];
void dfs(int x)
{
	visit[x]=1;
	dep[x]=1;
	for (int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if (visit[v]) continue;
		dfs(v);
		dep[x]=max(dep[x],dep[v]+1);
	}
	if (dep[x]==k && to[x]>1) ans++,dep[x]=0;
}
int main()
{
	int n;
	scanf("%d%d",&n,&k);
	to[1]=read();
	if (to[1]>1) ans++;
	to[1]=1;
	for (int i=2;i<=n;i++)
		to[i]=read(),addedge(to[i],i);
	dfs(1);
	cout<<ans;
	return 0;
}
