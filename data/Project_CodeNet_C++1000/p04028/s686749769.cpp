#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll modpow(ll x, ll n){
    if(n < 0) return 0;
    ll res = 1, r = x;
    while(n){
        if(n % 2) res = res * r % MOD;
        r = r * r % MOD;
        n /= 2;
    }
    return res;
}

ll dp[2][5002];

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k = s.size();
    int d[5002];
    dp[0][0] = 1;
    d[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++) dp[i % 2][j] = 0;
        for(int j = 1; j <= n; j++){
            dp[i % 2][j] = (dp[i % 2][j] + dp[(i + 1) % 2][j - 1] * 2) % MOD;
        }
        for(int j = 0; j <= n; j++){
            dp[i % 2][j] = (dp[i % 2][j] + dp[(i + 1) % 2][j + 1]) % MOD;
        }
        dp[i % 2][0] = (dp[i % 2][0] + dp[(i + 1) % 2][0]) % MOD;
        d[i] = dp[i % 2][0];
    }
    for(int j = 0; j <= n; j++) dp[0][j] = dp[1][j] = 0;
    ll ans = 0;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++) dp[i % 2][j] = 0;
        for(int j = 1; j <= n; j++){
            dp[i % 2][j] = (dp[i % 2][j] + dp[(i + 1) % 2][j - 1]) % MOD;
        }
        for(int j = 1; j <= n; j++){
            dp[i % 2][j] = (dp[i % 2][j] + dp[(i + 1) % 2][j + 1]) % MOD;
        }
        ans = (ans + dp[i % 2][k] * modpow(2, (i - k) / 2) % MOD * d[n - i] % MOD) % MOD;
    }
    cout << ans << endl;
}
