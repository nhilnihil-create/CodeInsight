#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
int dp[4000][4000],g[4000],head[4000];
int n,k,ans;
struct edge
{
	int to,next;
}e[4000];
bool v[4000];
vector<int> graph[4000];
void push(int k,int x,int y)
{
	e[k].to=y;e[k].next=head[x];head[x]=k;
}
void dfs(int x)
{
	int p=head[x];
	dp[x][0]=1;
	for (int j=1;j<=k+1;j++)
	{
		dp[x][j]=0;
	}
	v[x]=1;
	//while (p)
	for(int second : graph[x])
	{
		//if (!v[e[p].to])
		if(!v[second])
		{
		//dfs(e[p].to);
		dfs(second);
		
		g[0]=dp[x][0];
		for (int j=1;j<=k+1;j++) g[j]=min(g[j-1],dp[x][j]);
		for (int j=1;j<=k+1;j++) dp[x][j]=n;
		for (int j=1;j<=min(k+1,dp[x][0]);j++)
			for (int w=0;w<=min(k,dp[second][0]);w++)
				if (j-1+w<=k) dp[x][max(j,w+1)]=min(dp[x][max(j,w+1)],g[j]+dp[second][w]);
		dp[x][0]+=dp[second][0];
		}
		//p=e[p].next;
	}
	for (int j=1;j<=k+1;j++) dp[x][j]=min(dp[x][j],dp[x][j-1]);
	ans=min(ans,n-dp[x][0]+dp[x][k+1]);
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		//push(2*i-1,x,y);push(2*i,y,x);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	memset(v,0,sizeof(v));
	ans=n;
	dfs(1);
	printf("%d\n",ans);
	return 0;
}