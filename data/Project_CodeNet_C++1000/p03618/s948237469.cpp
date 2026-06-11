#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;

int64_t dp[maxn];
int cnt[26];

signed main () {
    string a;
    cin >> a;
    int n = a.size();
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        dp[i] += (i - 1) - cnt[a[i - 1] - 'a'];
        ++cnt[a[i - 1] - 'a'];
    }
    cout << dp[n] << '\n';
}
