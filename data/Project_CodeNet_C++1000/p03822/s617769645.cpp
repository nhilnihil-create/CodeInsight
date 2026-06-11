#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)

vector<vector<int>> G;

int dfs(int cur) {
    vector<int> dp;
    for(auto &to : G[cur]) dp.push_back(dfs(to));
    sort(dp.begin(), dp.end(), greater<int>());
    int res = 0;
    rep(i, 0, dp.size()) res = max(res, dp[i] + i + 1);
    return res;
}

int main() {
    int N; cin >> N;
    G.resize(N);
    rep(i, 0, N-1) {
        int a; cin >> a;
        a--;
        G[a].push_back(i + 1);
    }
    cout << dfs(0) << endl;
    return 0;
}
