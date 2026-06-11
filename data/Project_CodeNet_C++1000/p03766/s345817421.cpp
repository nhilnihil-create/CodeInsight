#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

const int N = 2000005;

int n, dp[N], dp_sum[N], mod = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 2 * n + 1 ; i > n ; i--){
        dp[i] = 1;
        dp_sum[i] = dp[i] + dp_sum[i + 1];
    }
    dp[n] = n;
    dp_sum[n] = dp[n] + dp_sum[n + 1];
    for(int i = n - 1 ; i >= 1 ; i--){
        dp[i] = dp[i + 1];
        dp[i] = ((dp[i] + dp_sum[i + 3]) % mod - dp_sum[i + n + 2] + mod) % mod;
        dp[i] = (dp[i] + 1LL * (n - 1) * (n - 1)) % mod;
        dp_sum[i] = (dp[i] + dp_sum[i + 1]) % mod;
    }
    cout << dp[1] << endl;
}
