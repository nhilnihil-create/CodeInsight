#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define N 200005
int dis1[N],dis2[N];
int n;
vector<int>g[N];
void dfs(int cur, int pre, int len, int dist[])
{
	int now;
	dist[cur]=len;
	for(int i=0;i<g[cur].size();++i)  
	{
		now=g[cur][i];
		if(now!=pre)
			dfs(now,cur,len+1,dist);
	}
}
int main()
{
	int i,x,y;
	scanf("%d",&n);
	for(i=0;i<n-1;++i)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,-1,0,dis1);
	dfs(n,-1,0,dis2);
	int ans=0;
	for(i=2;i<n;++i)
	{
		if(dis1[i]<=dis2[i])
		ans++;
		else
		ans--;
	}
	if(ans>0)
	cout<<"Fennec";
	else
	cout<<"Snuke";
	return 0;
}