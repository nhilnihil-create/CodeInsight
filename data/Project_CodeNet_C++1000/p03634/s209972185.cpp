#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


vector<ll> dist;
void bfs(vector<vector<pair<int,ll>>> g,int r)
{
	queue<int> que;
	que.push(r);
	dist[r]=0;
	while(!que.empty())
	{
		int p=que.front();
		que.pop();
		for(pair<int,ll> v : g[p])
		{
			if(dist[v.first]!=-1) continue;
			dist[v.first]=dist[p]+v.second;	
			que.push(v.first);
		}
	}
}
int main()
{
	int N;
	cin>>N;
	dist.resize(N,-1);
	vector<vector<pair<int,ll>>> g(N,vector<pair<int,ll>>());
	rep(i,N-1)
	{
		int a,b,c;
		cin>>a>>b>>c;
		a--;
		b--;
		g[a].push_back(make_pair(b,c));
		g[b].push_back(make_pair(a,c));
	}
	int Q,K;
	cin>>Q>>K;
	K--;
	bfs(g,K);
	rep(i,Q)
	{
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		cout<<dist[x]+dist[y]<<endl;
	}
	return 0;
}
