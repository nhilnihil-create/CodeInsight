#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define INF 1000000000

#define MAX_V 100001
struct edge {
	ll to;
	ll cost;
};
vector<edge> G[MAX_V];
ll d[MAX_V];

void dijkstra(int s) {
	priority_queue<P, vector<P>, greater<P> > que;
	fill(d, d + MAX_V, -1);
	d[s] = 0;
	que.push(P(0, s));

	while (!que.empty()) {
		P p = que.top();
		que.pop();
		int v = p.second;
		if (d[v] < p.first) continue;

		for (int i = 0; i < G[v].size(); ++i) {
			edge e = G[v][i];
			if (d[e.to] == -1 || d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}

void solve_abc_d() {
	ll n;
	cin >> n;

	ll a, b, c;
	edge e;
	rep(i, n - 1) {
		cin >> a >> b >> c;
		e.to = b;
		e.cost = c;
		G[a].push_back(e);
		e.to = a;
		e.cost = c;
		G[b].push_back(e);
	};

	ll q, k;
	cin >> q >> k;

	dijkstra(k);

	ll x, y;
	vector<ll> ans;
	rep(i, q) {
		cin >> x >> y;
		ans.push_back(d[x] + d[y]);
	}

	rep(i, ans.size()) {
		cout << ans[i] << "\n";
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve_abc_d();

	return 0;
}
