#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll N;
    cin >> N;
    ll mod = 1e9+7;
    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }
    vector<vector<ll>> dp(N+3, vector<ll>(2, 0));
    dp[N][0] = 1;
    dp[N][1] = N-1;
    dp[N-1][0] = N;
    dp[N-1][1] = (N-1)*N%mod;
    
    ll sum = 0;
    ll sum2 = 0;
    for (int i = N-2; i >= 1; i--) {
        dp[i][0] = (dp[i+1][0] + dp[i+1][1]) % mod;
        sum += dp[i+3][1];
        sum %= mod;
        sum2 += sum;
        sum2 %= mod;
        dp[i][1] = (sum2 + (N-1)*N) % mod;
    }
    cout << (dp[1][0] + dp[1][1]) % mod << endl;
    return 0;
}