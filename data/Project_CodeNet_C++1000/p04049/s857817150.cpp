#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
const int maxn=2010;
pair<int,int>e[maxn];
vector<int> edge[maxn];
bool vis[maxn];
int cnt;
void dfs(int n,int k)
{
	vis[n]=1;
	cnt++;
	if(k==0)return ;
	for(int i=0;i<edge[n].size();i++)
	{
		if(!vis[edge[n][i]])dfs(edge[n][i],k-1);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		e[i].first=a;
		e[i].second=b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	int ans=n;
	if(k&1)
	{
		for(int i=1;i<=n-1;i++)
		{
			cnt=0;
			memset(vis,0,sizeof(vis));
			vis[e[i].second]=1;
			dfs(e[i].first,k/2);
			dfs(e[i].second,k/2);
			int temp=n-cnt;
			ans=min(ans,temp);
		}
	}
	else {
		for(int i=1;i<=n;i++)
		{
			cnt=0;
			memset(vis,0,sizeof(vis));
			dfs(i,k/2);	
			int temp=n-cnt;
			ans=min(temp,ans);
		}
	}
	cout<<ans<<endl;
}