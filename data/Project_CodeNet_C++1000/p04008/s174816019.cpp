#include <bits/stdc++.h>

using namespace std;
const int MAXN=1e5+10;
vector<int> G[MAXN];
int n,k,dat[MAXN],dp[MAXN],res=0;

void dfs(int x)//Òª´ÓÒ¶×Ó½Úµã¿ªÊ¼ÍÆ£¡ 
{
	for(int i=0;i<G[x].size();i++)
		if(G[x][i]!=dat[x]) dfs(G[x][i]);
	if(++dp[x]>=k&&dat[x]!=1) res++,dp[x]=0;
	dp[dat[x]]=max(dp[dat[x]],dp[x]);
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&dat[i]);
	if(dat[1]!=1) res++,dat[1]=1;
	for(int i=2;i<=n;i++) G[dat[i]].push_back(i);
	
	dfs(1);printf("%d",res);
	return 0;
}