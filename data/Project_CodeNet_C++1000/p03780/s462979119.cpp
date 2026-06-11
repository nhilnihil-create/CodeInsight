#include <bits/stdc++.h>
using namespace std;
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector <int> v;
    for (int i = 0; i < n; ++ i) {
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    auto chk = [&] (int forbid) {
        if (v[forbid] >= k) return 0;
        vector <vector <int> > dp(n + 1, vector <int> (k, 0));
        dp[0][0] = 1;
        for (int i = 0; i < n; ++ i) if (i != forbid) {
            for (int j = 0; j < k; ++ j) {
                if (j >= v[i]) dp[i + 1][j] |= dp[i][j - v[i]];
                dp[i + 1][j] |= dp[i][j];
            }
        } else dp[i + 1] = dp[i];
        for (int i = k - v[forbid]; i < k; ++ i) if (dp[n][i]) return 0;
        return 1;
    };
    if (!chk(0)) {
        cout << 0 << endl;
        return 0;
    }
    int lb = 0, rb = v.size() - 1;
    while (lb < rb) {
        int md = lb + rb + 1 >> 1;
        if (chk(md)) lb = md;
        else rb = md - 1;
    }
    cout << lb + 1 << endl;
    return 0;
}