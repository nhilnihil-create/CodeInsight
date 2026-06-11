#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll n, k;
vector<ll> a;
vector<vector<bool>> dp;

bool Check(ll idx) {
    int src = 0, dst = 1;
    fill(dp[src].begin(), dp[src].end(), false);
    dp[src][0] = true;
    for (int i = 0; i < n; ++i) {
        if (i == idx) continue;
        fill(dp[dst].begin(), dp[dst].end(), false);
        for (int j = 0; j < k; ++j) {
            dp[dst][j] = dp[dst][j] | dp[src][j];
            if (0 <= j - a[i]) dp[dst][j] = dp[dst][j] | dp[src][j - a[i]];
        }
        swap(src, dst);
    }

    for (int i = 0; i < k; ++i)
        if (dp[src][i] && k - a[idx] <= i) return true;

    return false;
}

ll Solve() {
    cin >> n >> k;
    a.resize(n);
    dp.resize(2);
    dp[0].resize(k + 1); dp[1].resize(k + 1);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());

    if (accumulate(a.begin(), a.end(), 0ll) < k) return n;

    // 必要な要素の集合を見つける
    ll lb = -1, ub = n;
    while (1 < ub - lb) {
        ll mid = (lb + ub) >> 1;
        if (Check(mid)) lb = mid;
        else ub = mid;
    }

    return n - lb - 1;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cout << Solve() << endl;

    return 0;
}
