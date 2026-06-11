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
vector<ll> g[114514], depth[114514];
ll dp[114514] = {};

ll rec(ll x) {
	ll ans = 0;
	for (int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		depth[x].push_back(rec(y));
	}
	sort(depth[x].begin(), depth[x].end(), greater<ll>());
	for (int i = 0; i < depth[x].size(); ++i) {
		ans = max(depth[x][i] + i, ans);
	}

	return ans + 1;
}

int main() {
	IOS();
	ll n;
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		int a;
		cin >> a;
		g[a].push_back(i);
	}
	dump(rec(1) - 1);
}