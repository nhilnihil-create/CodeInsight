#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
const int INF = 1 << 28;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}

int main() {
    int n, k;
    cin >> n >> k;
    vl a(n, 0);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());

    auto noneed = [&](ll mid) {
        vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= n; ++j) {
            if (j - 1 == mid) {
                for (int i = 0; i <= k; ++i) {
                    dp[j][i] = dp[j - 1][i];
                }
            } else {
                for (int i = 0; i <= k; ++i) {
                    dp[j][i] = dp[j - 1][i];
                    if (i - a[j - 1] >= 0)
                        dp[j][i] = dp[j][i] || dp[j - 1][i - a[j - 1]];
                }
            }
        }
        bool noneed = true;
        for (int i = max(0LL, k - a[mid]); i < k; ++i) {
            if (dp[n][i]) {
                noneed = false;
                break;
            }
        }
        return noneed;
    };

    if (!noneed(0)) {
        cout << 0 << "\n";
        return 0;
    }
    if (noneed(n - 1)) {
        cout << n << "\n";
        return 0;
    }
    ll ng = 0;
    ll ok = n - 1;
    while (ng + 1 != ok) {
        ll mid = (ok + ng) / 2;

        if (noneed(mid))
            ng = mid;
        else
            ok = mid;
    }
    cout << ng + 1 << "\n";
    return 0;
}