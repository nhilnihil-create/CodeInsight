#include <bits/stdc++.h>
using namespace std;

const int N = (int)5005, mod = 1004535809;

int n, k;
int a[N];
int dp[2 * N];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    dp[0] = 1;

    for(int i = 0; i < n; i++) {
        if(a[i] >= k) continue;
        for(int j = k - a[i]; j >= 0; j--) dp[j+a[i]] += dp[j], dp[j+a[i]] %= mod;
    }
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] >= k) {
            res ++;
            continue;
        }
        for(int j = 0; j <= k - a[i]; j++) dp[j+a[i]] -= dp[j], dp[j+a[i]] = (dp[j+a[i]] + mod) % mod;
        int cnt = 0;
        for(int j = k - a[i]; j < k; j++) if(dp[j] != 0) cnt++;
        if(cnt > 0) res ++;
        for(int j = k - a[i]; j >= 0; j--) dp[j+a[i]] += dp[j], dp[j+a[i]] %= mod;
    }
    cout << n - res << endl;
}