#include <bits/stdc++.h>
#include <unordered_map>

const double PI = acos(-1);

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
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define MOD 1000000007
#define INF 1000000000
#define LLINF 1e18

#define MAX_V 200005
struct edge {
	int to;
	int cost;
};
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s) {
	priority_queue<P, vector<P>, greater<P> > que;
	fill(d, d + MAX_V, INF);
	d[s] = 0;
	que.push(P(0, s));

	while (!que.empty()) {
		P p = que.top();
		que.pop();
		int v = p.second;
		if (d[v] < p.first) continue;

		for (int i = 0; i < G[v].size(); ++i) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}

void solve_abc_c() {
	ll n, m;
	ll k;
	ll h, w;
	//ll x;
	//ll a;
	string s;
	string s_ans;
	ll l_ans = 0;
	double d_ans = 0;

	cin >> n >> m;

	ll a, b;
	rep(i, m) {
		cin >> a >> b;
		edge e;
		e.cost = 1;

		e.to = b;
		G[a].push_back(e);
		e.to = a;
		G[b].push_back(e);
	}

	dijkstra(1);
	if (d[n] == 2) {
		s_ans = "POSSIBLE";
	}
	else {
		s_ans = "IMPOSSIBLE";
	}

	cout << s_ans << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed;
	cout << setprecision(15);

	solve_abc_c();

	return 0;
}
