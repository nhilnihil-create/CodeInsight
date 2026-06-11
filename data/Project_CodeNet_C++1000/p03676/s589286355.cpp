
// Problem : D - 11
// Contest : AtCoder Regular Contest 077
// URL : https://atcoder.jp/contests/arc077/tasks/arc077_b
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define size(x) (int)x.size()

const int N = 1e6 + 1, mod = 1e9 + 7, inf = 2e9;

#define temptts template <class T, class... Ts>
temptts int add(T f) { return f; } temptts int add(T f, Ts... ts) { return (f + add(ts...)) % mod; }
temptts int sub(T f) { return f; } temptts int sub(T f, Ts... ts) { return (f - sub(ts...) + 1ll * mod * mod) % mod; }
temptts int mul(T f) { return f; } temptts int mul(T f, Ts... ts) { return (1ll * f * mul(ts...)) % mod; }
int binpow(ll n, ll k) { int ans = 1; while (k) { if (k & 1) ans = mul(ans, n); n = mul(n, n), k >>= 1; } return ans; }
int inv(int n) { return binpow(n, mod - 2); }
struct precompute { int f[N]; precompute() { f[0] = 1; for (int i = 1; i < N; i++) f[i] = mul(f[i - 1], i); } int operator() (int n) { return f[n]; } } fact;
int C(int n, int k) { return mul(fact(n), inv(mul(fact(k), fact(n - k)))); }

int n, a[N], cnt[N], p1, p2;

int main() { cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n + 1; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = 1; i < N; i++) if (cnt[i] > 1) cnt[0] = i;
	for (int i = 1; i <= n + 1; i++) {
		if (a[i] == cnt[0]) {
			if (!p1) p1 = i;
			else p2 = i;
		}
	}
	for (int k = 1; k <= n + 1; k++) {
		if (k - 1 <= n - p2 + p1) cout << sub(C(n + 1, k), C(n - p2 + p1, k - 1));
		else cout << C(n + 1, k);
		cout << '\n';
	}
}
