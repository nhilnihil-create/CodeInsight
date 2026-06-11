#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(s) (int)s.size()

int main() {
    int n, bw;
    cin >> n >> bw;
    unordered_map<int, int> dp;
    dp[0] = 0;
    rep(i, 0, n) {
        int w, v;
        cin >> w >> v;
        unordered_map<int, int> ndp = dp;
        for (auto p : dp)
            if (p.first + w <= bw) ndp[p.first + w] = max(ndp[p.first + w], p.second + v);
        dp.swap(ndp);
    }
    int ans = 0;
    for (auto p : dp) ans = max(ans, p.second);
    cout << ans << '\n';
}