#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
#define endl '\n'
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
const ll inf = 1e18;
ll n, m, r;
vector<ll>adj[207];
vector<bool>vis(207, false);
vector<ll>v;
vector<vector<ll>>dis(207, vector<ll>(207, inf));
void flyodwarshasll() {
	for (ll k = 0; k < n; k++) {
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < n; j++) {
				if (dis[i][j] >= dis[i][k] + dis[k][j])
					dis[i][j] = dis[i][k] + dis[k][j];
			}
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++)dis[i][i] = 0;
	for (ll i = 0; i < r; i++) {
		ll x;
		cin >> x;
		--x;
		v.pb(x);
	}
	for (ll i = 0; i < m; i++) {
		ll u, v, c;
		cin >> u >> v >> c;
		--u, --v;
		dis[u][v] = c;
		dis[v][u] = c;
	}
	flyodwarshasll();
	sort(v.begin(), v.end());
	ll nax = 1e18;
	do {
		ll ans = 0;
		for (ll i = 0; i < ll(v.size() - 1); i++) {
			ll to = v[i];
			ll from = v[i + 1];
			ans += dis[to][from];
		}
		nax = min(ans, nax);
	} while (next_permutation(v.begin(), v.end()));
	cout << nax << endl;
}