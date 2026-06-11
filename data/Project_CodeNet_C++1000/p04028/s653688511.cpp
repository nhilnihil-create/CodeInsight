#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (ll)a; i <= (ll)b; i++)
#define DEC(i, a, b) for(ll i = (ll)a; i >= (ll)b; i--)
typedef pair<ll, ll> pi;
#define f first
#define s second
#define pb push_back
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

ll n, l, dp[5005][5005], m = 1e9+7;
string s;

ll qexp(ll a, ll b) {
    a %= m;
    ll res = 1, base = a;
    while (b) {
        if (b & 1) {
            res *= base;
            res %= m;
        }
        base *= base;
        base %= m;
        b >>= 1;
    }
    return res % m;
}

void add(ll &a, ll b) {
	b %= m;
	a += b;
	a %= m;
}

int main() {
	fastio;
	cin >> n >> s;
	l = s.length();
	dp[0][0] = 1, dp[1][0] = 1, dp[1][1] = 2;
	FOR(i, 1, n) FOR(j, 0, i) {
		if (j == 0) {
			add(dp[i+1][j], dp[i][j]);
			add(dp[i+1][j+1], 2*dp[i][j]);
		} else {
			add(dp[i+1][j-1], dp[i][j]);
			add(dp[i+1][j+1], 2*dp[i][j]);
		}
	}
	cout << (dp[n][l] * qexp(qexp(2, l), m-2)) % m;
}
	
