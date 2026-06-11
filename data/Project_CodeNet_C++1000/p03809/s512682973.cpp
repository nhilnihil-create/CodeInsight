#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<iostream>
#include<cstdio>
using namespace std;
#define N 300005
#define INF 0x3f3f3f3f
#define LL long long
int rd()
{
	LL x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f*x;
}
int n,rt;
int a[N],f[N]/*某个点可以向上延伸的路径数*/;
vector<int>G[N];
void dfs(int u,int fa)
{
	if(G[u].size()==1)//叶节点
	{
		f[u]=a[u];
		return ;
	}
	int mx=0 /*fv最大值*/,sum=0 /*fv之和*/;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa) continue;
		dfs(v,u);
		sum+=f[v],mx=max(mx,f[v]);
	}
	f[u]=2*a[u]-sum;
	/*
	如果有f[u]条向上 那么剩下(a[u]-f[u])条路径都是以u为lca的
	lca式路径一条可以解决子树里2个 满足 f[u]+2*(a[u]-f[u])=sum 
	解得 f[u]=2*a[u]-sum 
	*/
	if(f[u]<0||a[u]>sum||(mx-f[u]>min(sum-mx,sum/2)))
	{
		puts("NO");
		exit(0);
	}
	/*
	有一些无解的情况
	1.2*a[u]<sum(f[u]<0) 全部是lca式路径都不能满足子树内 u先空了
	2.a[u]>sum 路径全部向上没法把u的石头拿掉 那么u的石头永远也不会被拿掉
	3.mx-f[u]>min(sum-mx,sum/2)
	lca式路径最多有min(sum-mx,sum/2)
	这里是mx太大 让他全部向上贡献 lca式路径都还要单着 mx的无法石头无法全部拿掉 
	*/
} 
int main()
{
	n=rd();
	for(int i=1;i<=n;i++)
		a[i]=rd();
	if(n==2)
	{
		if(a[1]==a[2]) puts("YES");
		else puts("NO");
		return 0;
	} 
	for(int i=1;i<=n-1;i++)
	{
		int u=rd(),v=rd();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		if(G[i].size()>1)
			rt=i;//根节点的度数要大于1 不然他自己的石头没法拿掉 
	dfs(rt,-1);
	if(f[rt]) puts("NO");
	else puts("YES");
    return 0;
}
