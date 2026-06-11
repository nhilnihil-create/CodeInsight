#include <bits/stdc++.h>
using namespace std;

int solveV(const vector<vector<int>> &G, int N, int K) {
    auto bfs = [&](int s) -> vector<int> {
        vector<int> dist(N, -1);
        queue<int> que;
        dist[s] = 0;
        que.push(s);
        while(!que.empty()) {
            int cur = que.front();
            que.pop();
            for(auto &to : G[cur]) {
                if(dist[to] == -1) {
                    dist[to] = dist[cur] + 1;
                    que.push(to);
                }
            }
        }
        return dist;
    };
    int ans = N;
    for(int s = 0; s < N; ++s) {
        auto dist = bfs(s);
        int res = 0;
        for(int i = 0; i < N; ++i) {
            if(dist[i] > K / 2) ++res;
        }
        ans = min(ans, res);
    }
    return ans;
}

int solveE(const vector<vector<int>> &G, int N, int K) {
    auto bfs = [&](int s, int t) -> vector<int> {
        vector<int> dist(N, -1);
        queue<int> que;
        dist[s] = 0;
        dist[t] = 0;
        que.push(s);
        que.push(t);
        while(!que.empty()) {
            int cur = que.front();
            que.pop();
            for(auto &to : G[cur]) {
                if(dist[to] == -1) {
                    dist[to] = dist[cur] + 1;
                    que.push(to);
                }
            }
        }
        return dist;
    };
    int ans = N;
    for(int s = 0; s < N; ++s) {
        for(auto &t : G[s]) {
            auto dist = bfs(s, t);
            int res = 0;
            for(int i = 0; i < N; ++i) {
                if(dist[i] > K / 2) ++res;
            }
            ans = min(ans, res);
        }
    }
    return ans;
}

void solve() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> G(N);
    for(int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if(K % 2) cout << solveE(G, N, K) << '\n';
    else cout << solveV(G, N, K) << '\n';
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
