#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;

const int N = 1001;
const ll MAX = (1LL<<61);

ll dist[N];

int main () {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		dist[i] = MAX;
	}

	vector<pair<int,int>> edges(m);
	vector<ll> weights(m);
	for (int i = 0; i < m; i++) {
		ll u, v, w; cin >> u >> v >> w;
		u--; v--;
		edges[i] = {u,v};
		weights[i] = -w;
	}

	dist[0] = 0;

	for (int relax = 0; relax < n-1; relax++) {
		for (int i = 0; i < m; i++) {
			pair<int,int> e = edges[i];
			if (dist[e.first] == MAX) {
				continue;
			}
			if (dist[e.first] + weights[i] < dist[e.second]) {
				dist[e.second] = dist[e.first] + weights[i];
			}
		}
	}

	ll ans = dist[n-1];

	for (int i = 0; i < m; i++) {
		pair<int,int> e = edges[i];
		if (dist[e.first] == MAX) {
			continue;
		}
		if (dist[e.first] + weights[i] < dist[e.second]) {
			dist[e.second] = dist[e.first] + weights[i];
		}
	}

	if (ans > dist[n-1]) {
		cout << "inf" << endl;
	} else {
		cout << -dist[n-1] << endl;
	}
 
	return 0;
}