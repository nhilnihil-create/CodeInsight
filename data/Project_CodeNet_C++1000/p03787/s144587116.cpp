#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main()
{
    Int N, M; cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> visited(N);
    vector<pair<int, bool>> A;
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        bool able = true;
        stack<pair<int, int>> S;
        S.emplace(i, 1);
        while (!S.empty()) {
            int t, c; tie(t, c) = S.top(); S.pop();
            if (visited[t]) continue;
            visited[t] = c, cnt++;
            for (int n : G[t]) {
                if (visited[n] == 0) S.emplace(n, 3-c);
                if (visited[n] == c) able = false;
            }
        }
        if (cnt) A.emplace_back(cnt, able);
    }
    Int single = 0, able = 0, unable = 0;
    for (auto& a : A) {
        if (a.first == 1) single++;
        else if (a.second) able++;
        else unable++;
    }
    Int ans = 0;
    ans += single * single + single * (N - single) * 2;
    ans += able * able * 2;
    ans += able * unable;
    ans += unable * able;
    ans += unable * unable;
    cout << ans << endl;
    return 0;
}
