#include<bits/stdc++.h>
using namespace std;
#define nn 65536*4
#define ll long long
vector<int> v[nn];
int ans;int n,diam;
int del[nn];
int dist[nn];
int bfs(int x,int lb)
{
	memset(dist,0x3f,sizeof(dist));
	queue<int> q;q.push(x);dist[x]=0;
	while(q.size())
	{
		int x=q.front();q.pop();
		for(int i=0;i<v[x].size();i++)
		{
			if(dist[v[x][i]]>dist[x]+1)
				dist[v[x][i]]=dist[x]+1,q.push(v[x][i]);
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++) if(dist[i]<=lb) cnt++;
	return cnt;
}
int bfs(int x,int y,int lb)
{
	memset(dist,0x3f,sizeof(dist));
	queue<int> q;q.push(x);q.push(y);dist[x]=dist[y]=0;
	while(q.size())
	{
		int x=q.front();q.pop();
		for(int i=0;i<v[x].size();i++)
		{
			if(dist[v[x][i]]>dist[x]+1)
				dist[v[x][i]]=dist[x]+1,q.push(v[x][i]);
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++) if(dist[i]<=lb) cnt++;
	return cnt;
}
int main()
{
	cin>>n>>diam;
	for(int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		v[x].push_back(y);v[y].push_back(x);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,bfs(i,diam/2));
		for(int j=0;j<v[i].size();j++)
			ans=max(ans,bfs(i,v[i][j],(diam-1)/2));
	}
	cout<<n-ans;
	return 0;  
}