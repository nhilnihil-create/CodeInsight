#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P   = pair<ll, ll>;
using mat = vector<vector<ll>>;

void IOS() { ios::sync_with_stdio(false), cin.tie(0); }

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

ll mod(ll a) {
	if (a > 0) return a % MOD;
	if (a % MOD == 0) return 0;
	ll x = -a / MOD + 1;
	a += x * MOD;
	return a % MOD;
}

template <typename T> void dump(T x) { cout << x << endl; }
void dumpf(double x, ll t) { cout << setprecision(t) << fixed << x << endl; }
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
	fill((T *)array, (T *)(array + N), val);
}
// ll dx[4]    = {1, 0, -1, 0};
// int dy[4]    = {0, 1, 0, -1};
// ll pas[5001][5002];
ll dp[114514][12] = {};
vector<ll> g[114514];
ll n, m;

void rec(int v, int d, int c) {
	if (dp[v][d] != 0) return;
	// cout << v << " " << d << endl;
	dp[v][d] = c;
	if (d == 0) return;
	for (int i = 0; i < g[v].size(); ++i) {
		int u = g[v][i];
		rec(u, d - 1, c);
	}
	rec(v, d - 1, c);
}

int main() {
	IOS();
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	ll q;
	cin >> q;
	vector<ll> v(q), d(q), c(q);
	for (int i = 0; i < q; ++i) { cin >> v[i] >> d[i] >> c[i]; }
	for (int i = q - 1; i >= 0; --i) { rec(v[i], d[i], c[i]); }
	for (int i = 1; i <= n; ++i) { dump(dp[i][0]); }
}