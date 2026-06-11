#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<cstdio>
#define ll long long
#define maxn 500015
using namespace std;
struct node{
	int next,v,u,w;
}p[maxn];
int head[maxn],cnt,vis[maxn],n,k,maxx;
 
void add(int u,int v)
{
	p[cnt].v=v;
	p[cnt].next=head[u];
	head[u]=cnt++;
}
 
void dfs(int now,int fa,int step)
{
	maxx++;
	if(step==0)
	return ;
	for(int i=head[now];~i;i=p[i].next)
	{
		if(p[i].v==fa)
		continue;
		dfs(p[i].v,now,step-1);
	}
}
 
int main()
{
	int i,j,x,y;
	scanf("%d%d",&n,&k);
	for(i=0;i<=n;i++)
	head[i]=-1;
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	int ans=0;
	if(k%2)    //k为奇数，枚举边，跑k/2的点 
	{
		for(i=1;i<=n;i++)
		{
			for(j=head[i];~j;j=p[j].next)
			{
				maxx=0;
				int t=p[j].v;
				dfs(t,i,k/2);
				dfs(i,t,k/2);
				ans=max(maxx,ans);
			}
		}
	}
	else      //k为偶数，枚举点，跑k/2的点 
	{
		for(i=1;i<=n;i++)
		{
			maxx=0;
			dfs(i,0,k/2);
			ans=max(maxx,ans);
		}
	}
	printf("%d\n",n-ans);
}