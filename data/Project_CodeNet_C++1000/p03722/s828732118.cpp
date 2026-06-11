#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1e18;

struct Edge
{
	int from, to;
	long long cost;
};

struct BellmanFord
{
	int V, E;
	int s;
	const vector<Edge> &edges;
	vector<long long> dist;
	vector<int> previous;
	bool negative_loop;
	vector<bool> negative;

	BellmanFord(int V, int start, const vector<Edge> &edges) : V(V), s(start), edges(edges) {
		E = edges.size();
	}

	void calc() {
		dist.assign(V, INF);
		dist[s] = 0;
		previous.assign(V, -1);
		negative.assign(V, false);
		negative_loop = true;
		for (int i = 0; i < V; i++) {
			bool update = false;
			for (Edge e : edges) {
				if (dist[e.from] >= INF) continue;
				if (dist[e.to] > dist[e.from] + e.cost) {
					dist[e.to] = dist[e.from] + e.cost;
					previous[e.to] = e.from;
					update = true;
				}
			}
			if (!update) {
				negative_loop = false;
				return;
			}
		}
		for (int i = 0; i < V; i++) {
			for (Edge e : edges) {
				if (dist[e.from] >= INF) continue;
				if (dist[e.to] > dist[e.from] + e.cost) {
					dist[e.to] = dist[e.from] + e.cost;
					negative[e.to] = true;
				}
				if (negative[e.from]) negative[e.to] = true;
			}
		}
	}

	bool calc_shortest_path() {
		dist.assign(V, INF);
		dist[s] = 0;
		previous.assign(V, -1);
		negative_loop = true;
		for (int i = 0; i < V; i++) {
			bool update = false;
			for (Edge e : edges) {
				if (dist[e.from] >= INF) continue;
				if (dist[e.to] > dist[e.from] + e.cost) {
					dist[e.to] = dist[e.from] + e.cost;
					previous[e.to] = e.from;
					update = true;
				}
			}
			if (!update) {
				negative_loop = false;
				break;
			}
		}
		return negative_loop;
	}

	bool find_negative_loop() {
		dist.assign(V, 0);
		for (int i = 0; i < V; i++) {
			for (Edge e : edges) {
				if (dist[e.to] > dist[e.from] + e.cost) {
					dist[e.to] = dist[e.from] + e.cost;
					if (i == V-1) return true;
				}
			}
		}
		return false;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<Edge> es(m);
	for (int i = 0; i < m; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		a--; b--;
		es[i] = {a, b, -c};
	}
	BellmanFord bf(n, 0, es);
	bf.calc();
	if (bf.negative[n-1]) {
		cout << "inf" << endl;
		return 0;
	}
	long long ans = -bf.dist[n-1];
	cout << ans << endl;
	return 0;
}