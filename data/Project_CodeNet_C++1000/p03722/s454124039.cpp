#include <bits/stdc++.h>

using namespace std;

int n,m;

template <typename T>
struct edge {
	int from, to;
	T cost;

	edge(int from, int to, T cost) :from(from), to(to), cost(cost) {}
};

template <typename T>
vector<T> bellman_ford(int s, int V, vector<edge<T> >& G) {
	const T INF = numeric_limits<T>::max();
	vector<T> cost(V, INF);
	cost[s] = 0;
	for (int i = 0; i < 2 * V; ++i) {
		for (edge<T> e : G) {
			if (cost[e.from] == INF) continue;
			if (cost[e.to] > cost[e.from] + e.cost) {
				cost[e.to] = cost[e.from] + e.cost;
				if (i >= V - 1 && e.to == n - 1) return vector<T>();
			}
		}
	}
	return cost;
}

int main() {
	cin >> n >> m;
	vector<edge<long long> > G;
	for(int i=0;i<m;++i) {
		int a,b,c; cin >> a >> b >> c;
		--a, --b;
		G.push_back({a,b,-c});
	}
	auto ans=bellman_ford(0,n,G);
	if(ans.empty()) cout << "inf" << endl;
	else cout << -ans[n-1] << endl;
	
	return 0;
}