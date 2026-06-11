#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,k;
int head[N],ver[N],nxt[N],tot;
int a[N];
int dep[N];
long long ans;
void add(int x,int y)
{
	ver[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
void dfs(int x,int fa)
{
	dep[x]=0;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i];
		if(y!=fa)
		{
			dfs(y,x);
			dep[x]=max(dep[x],dep[y]+1);
		}
	}
	if(dep[x]==k-1&&fa!=1)
	{
		ans++;
		dep[x]=-1;
	}
}
int main()
{
	int n;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{		
		scanf("%d",&a[i]);
		if(i!=1)
		add(a[i],i);
	}
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		if(a[i]!=1)
		{
			ans++;
		}
		printf("%lld",ans);
		return 0;
	}
	dfs(1,1);
	if(a[1]!=1)
	ans++;
	printf("%lld",ans);
	return 0;
}