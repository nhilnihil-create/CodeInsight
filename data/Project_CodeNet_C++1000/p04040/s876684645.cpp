// IOI 2021
 
#include <bits/stdc++.h>
using namespace std;

#define sync ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
#define debug(x) cerr << #x << ": " << x << endl
#define debugP(p) cerr << #p << ": {" << p.first << ", " << p.second << '}' << endl
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 1e9, MOD = INF + 7;
 
/////////////////////////////////////////////////////////////////////
 
const int N = 3e5 + 5, LOG = 20;

int FACT[N], INV[N];

int Power(int a, int b) {
	int res = 1;
	for (; b; b >>= 1, a = 1LL * a * a % MOD) if (b & 1) res = 1LL * res * a % MOD;
	return res;
}
int C(int n, int k) { return k > n ? 0 : 1LL * INV[k] * INV[n - k] % MOD * FACT[n] % MOD; }
int P(int n, int m) { return C(n + m - 2, n - 1); }

int main() {
 
	sync;

	int h, w, a, b; cin >> h >> w >> a >> b;
	FACT[0] = 1;
	for (int i = 1; i < N; i++) FACT[i] = 1LL * FACT[i - 1] * i % MOD;
	INV[N - 1] = Power(FACT[N - 1], MOD - 2);
	for (int i = N - 2; i >= 0; i--) INV[i] = 1LL * INV[i + 1] * (i + 1) % MOD;
	int ans = 0;
	for (int i = 1; i <= h - a; i++) ans = (ans + 1LL * P(b, i) * P(w - b, h - i + 1) % MOD) % MOD;
	cout << ans << endl;

	return 0;
}
