#include <bits/stdc++.h>
#define int long long
using namespace std;

struct edge{
	int to,cost;
};
using graph=vector<vector<edge>>;
graph G;
vector<int> dist;

signed main(){
	int N; cin>>N;
	G.assign(N,vector<edge>(0));

	for(int i=0;i<N-1;i++){
		int a,b,c; cin>>a>>b>>c; a--; b--;
		edge tmp; tmp.to=b; tmp.cost=c;
		G[a].push_back(tmp); tmp.to=a;
		G[b].push_back(tmp);
	}
	dist.assign(N,-1);
	int Q,K; cin>>Q>>K; K--;
	dist[K]=0;
	queue<int> que;
	que.push(K);
	while(!que.empty()){
		int now=que.front();
		que.pop();
		for(auto e : G[now]){
			if(dist[e.to]!=-1)continue;
			dist[e.to]=dist[now]+e.cost;
			que.push(e.to);
		}
	}

	for(int i=0;i<Q;i++){
		int x,y; cin>>x>>y; x--; y--;
		cout<<dist[x]+dist[y]<<endl;
	}

	return 0;

}