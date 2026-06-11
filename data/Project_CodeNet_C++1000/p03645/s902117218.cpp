#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
#define INF 1e6
using ll=long long;
using namespace std;


vector<int> cost;
void bfs(vector<vector<int>> g)
{
	cost[0]=0;
	queue<int> que;
	que.push(0);
	while(!que.empty())
	{
		int p=que.front();que.pop();
		for(int v : g[p])
		{
			if(cost[v]!=INF) continue;
			cost[v]=cost[p]+1;
			que.push(v);
		}
	}
}
int main()
{
	int N,M;
	cin>>N>>M;
	vector<vector<int>> g(N,vector<int>());
	rep(i,M)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);	
	}
	cost.resize(N,INF);	
	bfs(g);
	if(cost[N-1]==2)
	{
		cout<<"POSSIBLE"<<endl;
	}
	else
	{
		cout<<"IMPOSSIBLE"<<endl;
	}
	return 0;
}
