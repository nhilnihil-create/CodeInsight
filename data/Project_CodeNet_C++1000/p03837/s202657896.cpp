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

int n, m;
struct edge { int to, cost; };
vector<edge> g[105];
int d[205];
vector<tuple<int, int, int>> rec(1005);
map<P, bool> mp;

void dijkstra(int v) {
	priority_queue<P, vector<P>, greater<P>> pq;
	fill(d, d + n, inf);
	pq.emplace(0, v);
	d[v] = 0;
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
	rep(i, m) {
		int a = get<0>(rec[i]), b = get<1>(rec[i]), c = get<2>(rec[i]);
		if (d[a] == d[b] + c || d[b] == d[a] + c) {
			mp[P(a, b)] = true;
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
		rec[i] = tie(a, b, c);
	}
	rep(i, n) dijkstra(i);
	int ans = 0;
	rep(i, m) if (!mp[P(get<0>(rec[i]), get<1>(rec[i]))]) ans++;
	printf("%d\n", ans);
	return 0;
}
