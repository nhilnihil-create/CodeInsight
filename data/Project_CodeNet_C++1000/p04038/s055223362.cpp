#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll; 
typedef long double ld;
typedef pair<ll, ll> pll;

const ll N = 2300, Mod = 1e9 + 7;
const ll SQ = 330;


ll n, k, dp[N][N], I[N * N], F[N * N];
ll sum(ll a, ll b) {
	return (a + b + Mod) % Mod;
}
ll mul(ll a, ll b) {
	return (a * b) % Mod;
}
ll Pow(ll a, ll b) {
	ll res = 1;
	for (; b; b >>= 1, a = mul(a, a))
		if (b & 1)
			res = mul(res, a);
	return res;
}

ll C(ll r, ll n) {
	if (r > n || r < 0)
		return 0;
	return mul(F[n], mul(I[r], I[n - r]));
}
int main () {
    ios::sync_with_stdio(0), cin.tie(0);
    F[0] = 1;
    for (int i = 1; i < N * N; i ++)
    	F[i] = mul(i, F[i - 1]);
    I[N * N - 1] = Pow(F[N * N - 1], Mod - 2);
    for (int i = N * N - 2; ~i; i --)
    	I[i] = mul(i + 1, I[i + 1]);
    //cout << C(0, 0) << endl;
    cin >> n >> k;
    if (k == 1)
    	return cout << 1, 0;
    dp[0][0] = 1;
    for (int i = 0; i <= n; i ++) { // zero
    	for (int j = 0; j <= n; j ++) { // col
    		if (i < j) continue;
    		if (i + j == 0) continue;
    		if (i) {
    			dp[i][j] = sum(dp[i][j], dp[i - 1][j]);
			}
			if (j) {
				ll res = C(k - 2, n * k - i - ((j - 1)* (k - 1)) - 1);
				res =  mul(res, dp[i][j - 1]);
				dp[i][j] = sum(dp[i][j], res);
			}
		}
	}
	ll ans = mul(dp[n][n], F[n]);
	cout << ans;
    return (0);
}