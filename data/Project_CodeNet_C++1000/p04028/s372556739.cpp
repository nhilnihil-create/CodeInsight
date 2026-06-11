#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 6000;
const ll mod = 1e9 + 7;
ll dp[maxn][maxn];

ll qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1; 
    }
    return res;
}

ll inv(ll a) {
    return qpow(a, mod - 2);
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    int len = s.length();
    dp[0][0] = 1;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            dp[i + 1][j + 1] = ((2 * dp[i][j]) % mod + dp[i + 1][j + 1]) % mod;
            dp[i + 1][max(j - 1, 0)] = (dp[i][j] + dp[i + 1][max(j - 1, 0)]) % mod; 
        }
    }
    ll ans = (dp[n][len] * qpow( qpow(2, len), mod - 2) ) % mod;
    cout << ans;
}
