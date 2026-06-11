/// IN THE NAME OF GUITAR
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef pair<ll, ll> pll;

#define sz(x)                       (ll) x.size()
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second
#define lc                          id << 1
#define rc                          lc | 1

ll Pow(ll a, ll b, ll md, ll ans = 1) {
    for (; b; b >>= 1, a = a * a % md)
        if (b & 1)
            ans = ans * a % md;
    return ans % md;
}
 
const ll MAXN = 1e6 + 20;
const ll INF  = 1e18;
const ll MOD  = 1e9 + 7;
ll dp[MAXN], ps[MAXN], n;

int main() {
	scanf("%lld", &n);
	dp[n - 1] = n * n % MOD; dp[n] = ps[n] = n;
	ps[n - 1] = (dp[n] + dp[n - 1]) % MOD;
	for (ll i = n - 2; i >= 1; i--) {
		dp[i] = (dp[i + 1] + (n - 1) * (n - 1) % MOD) % MOD;
		dp[i] = ((dp[i] + ps[i + 3]) % MOD + 1 + i) % MOD;
		ps[i] = (ps[i + 1] + dp[i]) % MOD;
	}
	printf("%lld\n", dp[1]);
    return 0;
}
 