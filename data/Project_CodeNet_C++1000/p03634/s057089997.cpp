#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef pair<ll, ll> P;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
vi dy = { 0,0,1,-1 };
vi dx = { 1,-1,0,0 };
constexpr auto INF = INT_MAX/2;
constexpr auto MOD = 1000000007;

int main() {
	ll n;
	cin >> n;
	vector<vector<P>> path(n, vector<P>(0));

	rep(i, n - 1) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--;b--;
		path[a].push_back(make_pair(b,c));
		path[b].push_back(make_pair(a,c));
	}

	ll q, k;
	cin >> q >> k; k--;
	vector<ll> x(q), y(q);
	rep(i, q) { cin >> x[i] >> y[i]; x[i]--;y[i]--; }

	vector<ll> dist(n,5000000000000000);
	dist[k] = 0;

	priority_queue<P> que;
	que.push(make_pair(0, k));

	while (!que.empty()) {

		ll sv = que.top().second; que.pop();

		rep(i, path[sv].size()) {
			ll gv = path[sv][i].first;
			ll d = path[sv][i].second;

			if (dist[gv] < dist[sv] + d)continue;

			dist[gv] = dist[sv] + d;
			que.push(make_pair(dist[gv], gv));
		}
	}

	rep(i, q) cout << dist[x[i]] + dist[y[i]] << endl;

}