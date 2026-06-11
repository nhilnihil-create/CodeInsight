#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,dp[maxn],head[maxn],cnt;
struct edge{int to,next;
}e[maxn<<1];
vector<int>vec[maxn];
bool cmp(const int &a,const int &b)
{
	return dp[a]>dp[b];
}
void add(int x,int y)
{
	e[cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt++;
}
void dfs(int u,int pre)
{
	for(int i=head[u];i;i=e[i].next)
	{
		if(e[i].to==pre)continue;
		dfs(e[i].to,u);
	}
	if(vec[u].size())
	{
	  int now=1;
		sort(vec[u].begin(),vec[u].end(),cmp);
		for(int i=0;i<vec[u].size();++i)
		{
			dp[u]=max(dp[u],dp[vec[u][i]]+now);now++;
		}
	}
}
int main()
{
	cnt=1;
	scanf("%d",&n);
	for(int i=2;i<=n;++i)
	{
		int x;scanf("%d",&x);
		add(x,i);add(i,x);vec[x].push_back(i);
	}
	dfs(1,0);
	printf("%d\n",dp[1]);
}
