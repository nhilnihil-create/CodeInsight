#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010

int n,a[MAXN],d[MAXN];
vector<int> edge[MAXN];

long long dfs(int u,int fa)
{
	if(d[u]==1)return a[u];
	long long sum=2*a[u];
	for(auto v : edge[u])
	{
		if(v==fa)continue;
		long long res=dfs(v,u);
		if(res>a[u]){puts("NO");exit(0);}
		sum-=res;
	}
	if(sum<0 || sum>a[u]){puts("NO");exit(0);}
	return sum;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	if(n==1)
	{
		puts(a[1]?"NO":"YES");
		exit(0);
	}
	if(n==2)
	{
		puts(a[1]==a[2]?"YES":"NO");
		exit(0);
	}
	for(int i=1;i<n;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
		++d[u];
		++d[v];
	}
	for(int i=1;i<=n;++i)
	{
		if(d[i]>1)
		{
			puts(dfs(i,0)?"NO":"YES");
			exit(0);
		}
	}
}