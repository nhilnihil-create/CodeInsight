#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

// ただの辺
struct edge {
    int to;
    long long cost;
    // 引数一つの時は距離1
    edge(int t, long long c = 1) : to(t), cost(c) {}
};

// Bellman-Ford
// depend:edge
// 到達不可能:LLONG_MAX、負閉路を経由可能:LLONG_MIN
vector<lint> bellman_ford(vector<vector<edge>>& g, int s) {
    int n = g.size();
    vector<long long int> res(n, LLONG_MAX);
    res[s] = 0;
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < n; j++) {
            if (res[j] == LLONG_MAX) continue;
            for (int k = 0; k < (int)g[j].size(); k++) {
                int c = g[j][k].cost, dest = g[j][k].to;
                if (i < n - 1) {
                    res[dest] = min(res[dest], res[j] + c);
                } else {
                    if (res[j] == LLONG_MIN || res[dest] > res[j] + c) res[dest] = LLONG_MIN;
                }
            }
        }
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        lint c;
        cin >> a >> b >> c;
        a--, b--;
        c = -c;
        g[a].push_back(edge(b, c));
    }
    auto dist = bellman_ford(g, 0);
    lint res = dist[n - 1];
    if (res == LLONG_MIN) {
        cout << "inf" << endl;
    } else {
        cout << -res << endl;
    }
}