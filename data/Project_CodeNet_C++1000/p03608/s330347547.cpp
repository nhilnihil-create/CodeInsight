#include <bits/stdc++.h>
#define ALL(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX;
using edge = std::vector<long long>;

bool warshall_floyd(
	long long V,
	long long E,
	std::vector<edge>& edges,
	std::vector<std::vector<long long>>& dist
) {
	for (long long i = 0; i < V; i++) dist[i][i] = 0;
	for (auto i : edges) dist[i[1]][i[2]] = i[0];
	for (long long k = 0; k < V; k++) {
		for (long long i = 0; i < V; i++) {
			if (dist[i][k] == LLONG_MAX) continue;
			for (long long j = 0; j < V; j++) {
				if (dist[k][j] == LLONG_MAX) continue;
				dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	return false;
}

int main() {
	ll n, m, r;
	cin >> n >> m >> r;
	vector<ll> v(r);
	for (ll i = 0; i < r; i++) {
		cin >> v[i];
		v[i]--;
	}
	vector<edge> edges(0);
	for (ll i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		edges.push_back({c, a, b});
		edges.push_back({c, b, a});
	}
	m *= 2;
	vector<vector<ll>> dist(n, vector<ll>(n, INF));
	warshall_floyd(n, m, edges, dist);
	vector<ll> idx(r);
	for (ll i = 0; i < r; i++) idx[i] = i + 1;
	ll ans = INF;
	do {
		ll subans = 0;
		for (ll i = 0; i < r - 1; i++) {
			subans += dist[v[idx[i] - 1]][v[idx[i + 1] - 1]];
		}
		ans = min(ans, subans);
	} while (next_permutation(ALL(idx)));
	cout << ans << endl;
}