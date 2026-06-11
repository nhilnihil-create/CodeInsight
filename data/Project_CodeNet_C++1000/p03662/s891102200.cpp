#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <bitset>
#include <cmath>
#include <set>

#define rep(i,s,n)for(int i = s;i<n;i++)
#define repe(i,s,n)for(int i = s;i<=n;i++)
#define rep_r(i,s,n)for(int i = n-1;i>=s;i--)
#define rep_re(i,s,n)for(int i = n;i>=s;i--)
using namespace std;
typedef long long ll;
static const ll MOD = 1e9 + 7;
static const ll INF = 1e25;
static const ll MAX_N = 100001;

ll V;
ll d_f[MAX_N];
ll d_s[MAX_N];
struct edge { ll to, cost; };
typedef pair<ll, ll> P;
vector<edge> G[MAX_N];
void dijkstra(ll *d, ll s) {
	fill(d + 1, d + V + 1, INF);
	d[s] = 0;

	priority_queue <P, vector<P>, greater<P>> que;
	que.push(P(0, s));
	while (!que.empty()) {
		P p = que.top(); que.pop();
		ll v = p.second;
		if (d[v] < p.first)continue;
		rep(i, 0, G[v].size()) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}

int main() {
	cin >> V;
	rep(i, 1, V) {
		ll s, t, d; cin >> s >> t;
		G[s].push_back(*(new edge{ t,1 }));
		G[t].push_back(*(new edge{ s,1 }));
	}

	dijkstra(d_f, 1);
	dijkstra(d_s, V);

	ll a = 0;
	ll b = 0;
	repe(i, 1, V) ((d_f[i] <= d_s[i]) ? a++ : b++);

	cout << ((a > b) ? "Fennec" : "Snuke");

	return 0;
}