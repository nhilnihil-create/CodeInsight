//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

//ei1333さんのGitHubから https://ei1333.github.io/luzhiled/

//グラフ用テンプレ
//edge := 重み付き辺
//Edges := 重み付き辺集合
//WeightedGraph := 重み付きグラフ
//UnWeightedGraph := 重みなしグラフ
//Matrix := 距離行列
template< typename T >
struct edge {
	int src, to;
	T cost;
	edge(int to, T cost) : src(-1), to(to), cost(cost) {}
	edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
	
	edge &operator=(const int &x) {
		to = x;
		return *this;
	}
	operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;
//テンプレここまで

//Dijkstra : E log(V)
template< typename T >
vector< T > dijkstra(WeightedGraph< T > &g, int s) {
	const auto MINF = numeric_limits< T >::max();
	vector< T > dist(g.size(), MINF);

	using Pi = pair< T, int >;
	priority_queue< Pi, vector< Pi >, greater< Pi > > que;
	dist[s] = 0;
	que.emplace(dist[s], s);
	while(!que.empty()) {
		T cost;
		int idx;
		tie(cost, idx) = que.top();
		que.pop();
		if(dist[idx] < cost) continue;
		for(auto &e : g[idx]) {
			auto next_cost = cost + e.cost;
			if(dist[e.to] <= next_cost) continue;
			dist[e.to] = next_cost;
			que.emplace(dist[e.to], e.to);
		}
	}
	return dist;
}
//

int main() {
	int ans = 0;
	int tmp;
	int n;
	int a, b, c;
	cin >> n;
	int q, k;
	WeightedGraph< ll > G(n+1);
	REP(i, n-1){
		cin >> a >> b >> c;
		G[a].emplace_back(b, c);
		G[b].emplace_back(a, c);
	}
	cin >> q >> k;
	auto dis = dijkstra(G, k);
	REP(i, q){
		cin >> a >> b;
		cout << dis[a] + dis[b] << endl;
	}
}