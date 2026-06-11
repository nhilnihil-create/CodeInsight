#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(a) (int) (a).size()

const int p = 1e9 + 7;
const int maxn = 1e6 + 10;

int dp[maxn];
int ans = 0, sum = 0;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    dp[1] = 1;
    sum = 0;
    for (int i = 2; i <= n; i++) {
        if (i - 3 >= 0) {
            sum += dp[i - 3];
            sum %= p;
        }
        dp[i] = sum;
        dp[i] += dp[i - 1];
        dp[i] %= p;
//        cout << dp[i] << " ";
    }
//    cout << "\n";
    ans += dp[n] * n % p;
    ans %= p;
    for (int i = 1; i <= n - 1; i++) {
        ans += dp[i] * ((n - 1) * (n - 1) % p) % p;
        ans %= p;
    }
    for (int i = 1; i <= n - 1; i++) {
        ans += dp[i] * min(i + 1, n - 1) % p;
        ans %= p;
    }
    cout << ans << "\n";

    return 0;
}
