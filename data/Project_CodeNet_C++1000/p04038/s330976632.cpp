#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 2e3 + 5, M = N * N, mod = 1e9 + 7;

int n, k;
ll dp[N][N], fact[M], rev[M];

ll pw(ll a, ll b) {
	if(!b)
		return 1;
	ll ans = pw(a, b / 2);
	ans = (ans * ans) % mod;
	if(b & 1)
		ans *= a;
	return ans % mod;
}

void prep() {
	fact[0] = 1;
	for (int i = 1; i < M; i++)
		fact[i] = (fact[i - 1] * i) % mod;
	rev[M - 1] = pw(fact[M - 1], mod - 2);
	for (int i = M - 2; ~i; i--)
		rev[i] = (rev[i + 1] * (i + 1)) % mod;
}

int sum(int a, int b) {
	a += b;
	if(a >= mod)
		a -= mod;
	if(a < 0)
		a += mod;
	return a;
}

ll c(int x, int y) {
	if(y > x)
		return 0;
	ll ans = (fact[x] * rev[y]) % mod;
	ans = (ans * rev[x - y]) % mod;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);	
	cin >> n >> k;
	prep();
	if(k == 1)
		return cout << 1 << "\n", 0;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i][j] = sum(dp[i][j], dp[i - 1][j]);
			if(j) {
				ll cost = c((n * k) - ((j - 1) * (k - 1)) - i - 1, k - 2);
				dp[i][j] = sum(dp[i][j], dp[i][j - 1] * cost % mod);
			}
		}
	}
	cout << (fact[n] * dp[n][n]) % mod << "\n";
 }
