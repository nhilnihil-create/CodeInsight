#include <bits/stdc++.h>
#include <iostream>
#include <utility>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ll long long
#define P pair<int,int>
const int MOD = 1000000007;
const int INF = 1001001001;
using namespace std;

struct Edge {
    int n1, n2, cost;
    Edge(int n1_, int n2_, int cost_) {
        n1 = n1_;
        n2 = n2_;
        cost = cost_;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    int a, b, c;
    vector<vector<int>> g(n, vector<int>(n, INF));
    vector<Edge> e;

    rep(i,m) {
        cin >> a >> b >> c;
        a--; b--;
        g[a][b] = g[b][a] = c;
        e.emplace_back(a, b, c);
    }

    rep(i,n) g[i][i] = 0;

    rep(k,n) {
        rep(i,n) {
            rep(j,n) {
                g[i][j] = min(g[k][j]+g[i][k], g[i][j]);
            }
        }
    }

    int ans = 0;
    for (auto edge: e) {
        if (g[edge.n1][edge.n2] < edge.cost) ans++;
    }
    cout << ans << endl;
    return 0;
}