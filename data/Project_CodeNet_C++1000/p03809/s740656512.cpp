#include <bits/stdc++.h>
using namespace std;
#define N 110000
int n,tot,root;
int a[N],head[N],nex[N<<1],to[N<<1];
int du[N],rem[N];
void add(int x,int y)
{
	tot++;
	nex[tot]=head[x];head[x]=tot;
	to[tot]=y;
}
void quit(){puts("NO");exit(0);}
void dfs(int x,int y)
{
	if(du[x]==1)
	{
		rem[x]=a[x];
		return;
	}
	int mx=0,sum=0;
	for(int i=head[x];i;i=nex[i])
		if(to[i]!=y)
		{
			dfs(to[i],x);
			sum+=rem[to[i]];
			mx=max(mx,rem[to[i]]);
		}
	int v1=sum-a[x],v2=a[x]-v1;
	if(v1<0||v2<0)quit();
	if(sum-mx<v1)quit();
	rem[x]=v2;
}
int main()
{
	//freopen("tt.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1,x,y;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
		du[x]++;du[y]++;
	}
	if(n==2)return puts(a[1]==a[2] ? "YES" : "NO"),0;
	root=1;
	while(du[root]==1)root++;
	dfs(root,0);
	if(rem[root])quit();
	puts("YES");
	return 0;
}
