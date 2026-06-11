#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define db long double
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;

const int N = 2e5 + 123;
int n, m, used[N], h[N], cnt;
int sz[N], C[2][N], cycle[N];
vi adj[N];

int t[2], tn;
pii tc;

void add(int x) {
	if (!cycle[x]) {
		for (int j = 0; j < 2; j++) {
			t[j] += C[j][x];
		}
		tn++;
	}	else {
		tc.F += sz[x];
		tc.S++;
	}
}

void del(int x) {
	if (!cycle[x]) {
		for (int j = 0; j < 2; j++) {
			t[j] -= C[j][x];
		}
		tn--;
	}	else {
		tc.F -= sz[x];
		tc.S--;
	}
}

void dfs(int v, int p) {
	used[v] = 1;
	C[h[v]][cnt]++;
	sz[cnt]++;
	for (int to : adj[v]) {
		if (to == p) {
			continue;
		}
		if (used[to] == 1) {
			if (h[to] ^ h[v] ^ 1) {
				cycle[cnt] = 1;
			}
		}
		if (used[to] == 0) {
			h[to] = h[v] ^ 1;
			dfs(to, v);
		}
	}
	used[v] = 2;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			cnt++;
			dfs(i, -1);
			if (sz[cnt] == 1) {
				continue;
			}
			add(cnt);
		}
	}
	ll res = 0;
	for (int i = 1; i <= cnt; i++) {
		if (sz[i] == 1) {
			continue;
		}
		del(i);
		if (!cycle[i]) {
			res += (ll)C[0][i] * C[0][i] + (ll)C[1][i] * C[1][i] - 1;
			res += (ll)C[0][i] * C[1][i] + C[1][i] * C[0][i] - 1;
			
			res += (ll)C[0][i] * t[0] + (ll)C[1][i] * t[1] - tn;
			res += (ll)C[0][i] * t[1] + (ll)C[1][i] * t[0] - tn;
		}	else {
			res += (ll)sz[i] * tc.F - tc.S;
			res += (ll)sz[i] * (t[0] + t[1]) - tn;
			res += (ll)(t[0] + t[1]) * sz[i] - tn;
			res += (ll)sz[i] * sz[i] - 1;
		}
		add(i);
	}
	res = (ll)n * n - res;
	cout << res;
}
