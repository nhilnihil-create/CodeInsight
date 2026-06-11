#include<bits/stdc++.h>
#define N 2010
using namespace std;
int n,k;
int ans[N][N],res;
int dep1,dep2,dep[N];
int cnt,s[N];
struct node
{
	int num,next;
}mp[N<<1];
void init(int x,int y)
{
	mp[++cnt].next=s[x];
	mp[cnt].num=y;
	s[x]=cnt;
}
void dfs(int x,int f)
{
	ans[x][1]=1;
	for(int i=s[x];i;i=mp[i].next)
	{
		int y=mp[i].num;
		if(y==f)continue;
		dfs(y,x);
	}
	int son=0;
	dep1=dep2=0;
	int j,maxp=0;
	for(int i=s[x];i;i=mp[i].next)
	{
		int y=mp[i].num;
		if(y==f)continue;
		++son;
		for(j=1;ans[y][j]&&j<k;j++)
			dep[j+1]+=ans[y][j];
		if(j>dep1)dep2=dep1,dep1=j,maxp=y;
		else if(j>dep2)dep2=j;
		--j;
		for(int r=j+1;r<k;r++)
			dep[r+1]+=ans[y][j];
	}
	int l=min(dep1,k);
	for(j=2;j<=l;j++)
	{
		if(son==1||j*2<=k+1)
			ans[x][j]=dep[j];
		else if(k-j>=dep2)
			ans[x][j]=ans[maxp][j-1]+dep[k-j+1]-ans[maxp][k-j];
		else for(int i=s[x];i;i=mp[i].next)
			{
				int y=mp[i].num;
				if(y==f)continue;
				if(ans[y][j-1])
					ans[x][j]=max(ans[x][j],ans[y][j-1]+dep[k-j+1]-ans[y][k-j]);
			}
		res=max(res,ans[x][j]);
	}
	for(int j=2;j<=k;j++)
		dep[j]=1;
}
int main()
{
	scanf("%d%d",&n,&k);
	++k;
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		init(x,y);
		init(y,x);
	}
	for(int i=1;i<=k;i++)
		dep[i]=1;
	dfs(1,1);
	printf("%d",n-res);
}