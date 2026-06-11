#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
int dp[N];

int add(int a, int b) {return (a + b) % MOD;}
int mul(int a, int b) {return 1ll * a * b % MOD;}
int main() {
    int n, sum = 2; cin >> n;
    dp[0] = dp[1] = 1;
    for (int i = 2; i < n; i++) dp[i] = add(sum, MOD - dp[i - 2]), sum = add(sum, dp[i]);
    int ans = 1;
    for (int i = 1; i < n; i++) ans += mul(n - 1, dp[i - 1]), ans %= MOD;
    for (int i = 1; i < n; i++) ans += add(mul(mul(n - 1, n - 2), dp[i - 1]), mul(dp[i], n - 1)), ans %= MOD;
    cout << add(ans, n - 1) << "\n";
}
