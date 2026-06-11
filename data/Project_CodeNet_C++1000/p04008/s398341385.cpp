#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int ans = 0;
    vector<vector<int>> graph(N);
    for(int i = 0; i < N; ++i) {
        int a; cin >> a;
        a--;
        if(i) graph[a].emplace_back(i);
        else if(a) ans++;
    }
    vector<int> depth(N);
    auto dfs = [&](auto &&dfs, int cur, int pre) -> int {
        int d = depth[cur];
        for(auto &to : graph[cur]) {
            if(to == pre) continue;
            depth[to] = depth[cur] + 1;
            d = max(d, dfs(dfs, to, cur));
        }
        int ret = d;
        if(pre == 0) return ret;
        if(d - depth[cur] == K - 1) {
            ans++;
            ret = depth[pre];
        }
        return ret;
    };
    dfs(dfs, 0, 0);
    cout << ans << '\n';
    return 0;
}
