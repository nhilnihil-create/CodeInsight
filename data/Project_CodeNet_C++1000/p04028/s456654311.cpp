#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

constexpr ll MOD = (ll)1e9 + 7;

ll MODpow(ll n, ll m) {
    ll result = 1;
    while (m) {
        if (m % 2 == 1) {
            result *= n;
            result %= MOD;
        }

        m /= 2;
        n *= n;
        n %= MOD;
    }

    return result;
}

int main() {
    ll N;
    string s;
    cin >> N >> s;

    const ll M = s.size();

    //dp[i][j] := キーをi回押して長さjの文字列を作る方法の数
    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, 0));
    dp[0][0] = 1;
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            //'0'or'1'を押す
            (dp[i + 1][j + 1] += dp[i][j] * 2) %= MOD;

            //'B'を押す
            (dp[i + 1][max(j - 1, (ll)0)] += dp[i][j]) %= MOD;
        }
    }

    cout << dp[N][M] * MODpow(MODpow(2, M), MOD - 2) % MOD << endl;
}