#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define empb emplace_back
#define all(x) (x).begin(),(x).end()
#define lbd(a, x) lower_bound(all(a), x)
const int mod = 1e9 + 7;
int power_mod(int a, int b) {
	int res = 1;
	for(; b; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) res = (ll) res * a % mod;
	return res;
}
const int N = 2e5 + 10;
int fac[N], ifac[N];
int C(int n, int m) {
	if(n < m || m < 0) return 0;
	return (ll) fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
int main() {
#ifdef local
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
  fac[0] = ifac[0] = 1;
  for(int i = 1; i < N; i++) fac[i] = (ll) fac[i - 1] * i % mod;
  ifac[N - 1] = power_mod(fac[N - 1], mod - 2);
  for(int i = N - 2; i; i--) ifac[i] = (ll) ifac[i + 1] * (i + 1) % mod;
  int n, m; cin >> n >> m;
  int a, b; cin >> a >> b;
  int res = C(n + m - 2, n - 1);
  for(int i = 0; i < a; i++) {
		res = (res - (ll) C(n - 1 - i + b - 1, b - 1) * C(m - b - 1 + i, i)) % mod;
  }
  if(res < 0) res += mod;
  cout << res << '\n';
	return 0;
}
