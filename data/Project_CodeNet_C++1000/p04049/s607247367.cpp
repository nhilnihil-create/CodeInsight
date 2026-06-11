#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int>tab[2011];
int cnt[2011][2];//0表示mdep,1表示mdep+1
int n,k; 
void dfs(int fa,int now,int dep,int mdep)
{
	int sz=tab[now].size();
	cnt[now][0]=cnt[now][1]=0;
	for(int i=0;i<sz;++i)
	{
		if(tab[now][i]!=fa)
		{
			dfs(now,tab[now][i],dep+1,mdep);
			cnt[now][0]+=cnt[tab[now][i]][0];
			cnt[now][1]+=cnt[tab[now][i]][1];
		}
	}
	if(dep>mdep)cnt[now][0]++;
	if(dep>mdep+1)cnt[now][1]++;
}
int solve(int x)
{
	dfs(x,x,0,k/2);
	if(k%2==1)
	{
		int sz=tab[x].size();
		int minans=999999999;
		for(int i=0;i<sz;++i)
		{
			minans=min(minans,cnt[x][0]-cnt[tab[x][i]][0]+cnt[tab[x][i]][1]);
		}
		return minans;
	}else
	{
		return cnt[x][0];
	}
	
} 
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		tab[a].push_back(b);
		tab[b].push_back(a);
	}
	int ans=99999999;
	for(int i=1;i<=n;++i)
	{
		ans=min(ans,solve(i)); 
	}
	printf("%d",ans);
	return 0; 
}