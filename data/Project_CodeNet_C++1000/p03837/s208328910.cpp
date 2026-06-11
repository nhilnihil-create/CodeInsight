#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

struct warshall_floyd {
	static void solve(vector<vector<ll>>& d) {
		int n = d.size();
		rep(k, n) {
			rep(i, n) {
				rep(j, n) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	}
};

struct edge {
	int from, to;
	ll cost;
};

int main() {
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> graph(n, vector<ll>(n, INF));
	vector<edge> es;
	rep(i, m) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		a--; b--;
		es.push_back({ a, b, c });
		graph[a][b] = c;
		graph[b][a] = c;
	}
	warshall_floyd::solve(graph);
	ll sum = 0;
	rep(i, m) {
		auto e = es[i];
		if (graph[e.from][e.to] < e.cost) {
			sum++;
		}
	}
	cout << sum << endl;
	return 0;
}
