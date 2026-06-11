#include<bits/stdc++.h>
using namespace std;
int n=100005;
vector<pair<int,int>>adj[100005];
long long dist[100005];
bool processed[100005];
long long inf = 10000000000000009;
void dijkstra(int s)
{
	priority_queue<pair<long long,int>> q;
	q.push({0,s});
	while(!q.empty())
	{
		int a = q.top().second; q.pop();
		if(processed[a])
			continue;
		processed[a]=true;
		for(auto u : adj[a])
		{
			int b = u.first; long long w=u.second;
			if(dist[a]+w < dist[b]){
			dist[b]=dist[a]+w;
			q.push({-dist[b],b});
			}
		}
	}

}

int main()
{
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int a,b;long long c;
		cin>>a>>b>>c;
		a--;b--;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	int q,k;
	cin>>q>>k;
	k--;
	for(int i=0;i<n;i++){
		dist[i]=inf;
		processed[i]=false;
	}
	dist[k]=0;
	dijkstra(k);

	while(q-->0)
	{
		int x,y;
		cin>>x>>y;
		x--;y--;
		cout<<dist[x]+dist[y]<<"\n";
	}

}