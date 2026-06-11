#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
typedef long long LL;
static long long INF = (1LL<<62);

using Graph = vector<vector<int>>;
using LLPair = pair<LL, LL>;
using WeightedGraph = vector<vector<LLPair>>;
using PriorityQ = priority_queue<LLPair, vector<LLPair>, greater<LLPair>>;

void dijkstra(WeightedGraph &WG, vector<LL> &D, LL s){
	for(int i=0; i<D.size(); i++){
		D[i] = INF;
	}
	D[s] = 0;

	PriorityQ pq;
	pq.push(make_pair(0, s));
	while(!pq.empty()){
		LL pos = pq.top().second; pq.pop();
		for(auto nv : WG[pos]){
			LL to = nv.first; 
			LL cost = nv.second;
			if(D[to] > D[pos] + cost){
				D[to] = D[pos] + cost; 
				pq.push(make_pair(D[to], to));
			}
		}
	}
	return;
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N;

	WeightedGraph WG(N);
	for(int i=0; i<N-1; i++){
		int a, b, c; cin >> a >> b >> c;
		a--; b--;
		WG[a].push_back(make_pair(b, c));
		WG[b].push_back(make_pair(a, c));
	}

	int Q, K; cin >> Q >> K; K--;
	vector<LL> dist(N);
	dijkstra(WG, dist, K);
	for(int i=0; i<Q; i++){
		int x, y; cin >> x >> y;
		x--; y--;
		LL d = dist[x] + dist[y];
		printf("%lld\n", d);
	}
	return 0;
}