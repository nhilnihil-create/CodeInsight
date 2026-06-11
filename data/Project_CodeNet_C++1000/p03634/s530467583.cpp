#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int (i) = 1; (i) <= (n); (i++))
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
#define printd(x) printf("%.12f\n", ans);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

using Graph = vector<vector<pair<ll, ll>>>;
using Pi = pair<ll, ll>;

Graph g(100005);
const ll MOD = 100000000000000000;

//準備...Graph g;
//入力...g[Node].push_back(make_pair(nextNode, weight));

vector<ll> djkstra(Graph &g, ll s) {
	vector<ll> dist(g.size(), MOD);
	dist[s] = 0;
	priority_queue<Pi, vector<Pi>, greater<Pi>> que;
	que.emplace(dist[s], s);
	while ( !que.empty() ) {
		ll cost; ll u; tie(cost, u) = que.top(); que.pop();
		if (dist[u] < cost) continue;
		for (auto &x : g[u]) {
			ll v; ll nc; tie(v, nc) = x;
			if (chmin(dist[v], dist[u] + nc)) que.emplace(dist[v], v);
		}
	}

	return dist;
}

int main(void) {
	int n;
	cin >> n;
	rep (i, n - 1) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		g[a].eb(b, c);
		g[b].eb(a, c);
	}

	int q, k;
	cin >> q >> k;
	k--;
	vector<ll> dist = djkstra(g, k);

	vector<ll> ans;
	rep (i, q) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		ans.pb(dist[x] + dist[y]);
	}

	rep (i, q) cout << ans[i] << '\n';
	return 0;	
}