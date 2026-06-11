#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define v vector 

const ll mod = 1e9 + 7;
const ll invtwo = 500000004;
const ll maxN = 5001;

ll dp[maxN][maxN]; //n, m;

ll fastpow(ll x, ll n) {
    ll res = 1;
    while (n != 0) {
        if(n & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        n = (n >> 1);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    string s;
    cin >> n >> s;
    m = s.size();

    dp[0][0] = 1; // base case;

    for(ll i = 1; i <= n; i ++) {
        for(ll j = 0; j <= n; j ++) {
            ll val = 0;
            if(j == 0) val += dp[i-1][j];
            if(j-1 >= 0) {
                val = (val + dp[i-1][j-1] * 2) % mod;
            }
            if(j+1 < maxN) {
                val = (val + dp[i-1][j+1]) % mod;
            }
            dp[i][j] = val;
        }
    }
    ll ans = dp[n][m];
    for(ll i = 0; i < m; i ++) {
        ans = (ans * invtwo) % mod;
    }
    cout << ans << endl;

    return 0;
}