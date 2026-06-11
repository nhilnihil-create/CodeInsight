#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int INF = 1e9;

vector<int> bfs(vector<vector<int>> const& g, int s) {
    int const n = g.size();
    vector<int> d(n, INF);
    d[s] = 0;
    queue<int> que;
    que.push(s);
    while(!que.empty()) {
        int v = que.front();
        que.pop();
        for(auto to : g[v]) {
            if(d[to] != INF) {
                continue;
            }
            d[to] = d[v] + 1;
            que.push(to);
        }
    }
    return d;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> g(N);
    for(int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<vector<int>> vs(N);
    vector<int> sz(N);
    for(int i = 0; i < N; ++i) {
        auto d = bfs(g, i);
        for(int j = 0; j < N; ++j) {
            if(d[j] > K) {
                vs[i].push_back(j);
                sz[i]++;
            }
        }
    }

    int res = 0;
    while(true) {
        auto it = max_element(sz.begin(), sz.end());
        if(*it == 0) {
            break;
        }
        int v = it - sz.begin();
        sz[v] = 0;
        for(auto w : vs[v]) {
            sz[w]--;
        }
        vs[v].clear();
        res++;
    }
    cout << res << endl;
}