/**
 *    author:  FromDihPout
 *    created: 2020-07-26
**/

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

const long long INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int,int>, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges[i] = {{u, v}, w};
    }
    
    vector<long long> score(n, -INF);
    score[0] = 0;
    for (int i = 0; i < n; i++) {
        for (auto e : edges) {
            int u = e.f.f, v = e.f.s, w = e.s;
            if (score[u] >= -INF) {
                score[v] = max(score[v], score[u] + w);
            }
        }
    }
    long long prev = score[n-1];
    for (int i = 0; i < n; i++) {
        for (auto e : edges) {
            int u = e.f.f, v = e.f.s, w = e.s;
            if (score[u] >= -INF) {
                score[v] = max(score[v], score[u] + w);
            }
        }
    }
    if (score[n-1] > prev) {
        cout << "inf" << '\n';
    }
    else {
        cout << prev << '\n';
    }
    return 0;
}