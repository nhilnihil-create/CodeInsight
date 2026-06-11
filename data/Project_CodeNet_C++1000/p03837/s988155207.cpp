#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

struct edge { int to, cost; };
int n, m;
vector<edge> g[105];
bool used[105][105];
int d[105];

void dijkstra(int s) {
	priority_queue<P, vector<P>, greater<P>> pq;
	fill(d, d + n, inf);
	pq.emplace(0, s);
	d[s] = 0;
	while (pq.size()) {
		P p = pq.top(); pq.pop();
		int v = p.second;
		if (d[v] < p.first) continue;
		for (auto& c : g[v]) {
			edge e = c;
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				pq.emplace(d[e.to], e.to);
			}
		}
	}

	rep(i, n) {
		for (auto& c : g[i]) {
			edge e = c;
			if (d[i] + e.cost == d[e.to]) {
				used[i][e.to] = true;
				used[e.to][i] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		g[a].push_back({ b, c });
		g[b].push_back({ a, c });
	}
	rep(i, n) dijkstra(i);
	int ans = m;
	rep(i, n - 1) {
		for (int j = i + 1; j < n; ++j) {
			if (used[i][j]) ans--;
		}
	}
	cout << ans << endl;
	return 0;
}
