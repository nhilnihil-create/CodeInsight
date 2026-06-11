#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric> // accumulate
#include <queue>
#include <string>
#include <cmath> // sqrt
#include <map>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod) {
    return modpow(a, mod-2, mod);
}

ll dp[5010][5010];  //dp[キーを押す回数][文字列の長さ]

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int m = s.size();

    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                dp[i+1][j+1] += dp[i][j] * 2LL;
                dp[i+1][j+1] %= mod;
                dp[i+1][j] += dp[i][j];
                dp[i+1][j] %= mod;
            }
            else {
                dp[i+1][j+1] += dp[i][j] * 2LL;
                dp[i+1][j+1] %= mod;
                dp[i+1][j-1] += dp[i][j];
                dp[i+1][j-1] %= mod;
            }
        }
    }

    cout << dp[n][m] * modinv(modpow(2, m, mod), mod) % mod << endl;
}