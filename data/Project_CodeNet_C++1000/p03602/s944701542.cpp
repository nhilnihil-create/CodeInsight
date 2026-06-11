#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T, class U> inline bool chmax(T& a,U b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class U> inline bool chmin(T& a,U b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1e18;

struct UnionFind {
    vector<int> data; int sz;
    UnionFind(int sz) : data(sz, -1), sz(sz) { }
    bool unionSet(int x, int y) {
        if ((x = root(x)) == (y = root(y))) { return false; }
        if (data[x] > data[y]) { swap(x, y); }
        data[x] += data[y]; data[y] = x; sz--; return true;
    }
    bool findSet(int x, int y) { return root(x) == root(y); }
    int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
    int size(int x) { return -data[root(x)]; }
    int size() { return sz; }
};

int main() {
    int N;
    bool is_ok = true;
    cin >> N;
    long long A[N][N];
    vector<vector<long long>> G(N, vector<long long>(N, INF));
    vector<pair<long long, pair<int, int>>> edges;
    for (int i = 0; i < N; i++) G[i][i] = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        cin >> A[i][j];
        if (i < j) edges.emplace_back(A[i][j], make_pair(i, j));
    }
    // WF で最短路か判定(以降Aが最短路とする)
    // kruskal法の要領で辺の採用不採用を判定
    // 繋がっていないなら採用
    // 繋がっているとき、その辺を使って最短路が生まれるなら採用
    sort(edges.begin(), edges.end());
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            if (chmin(A[i][j], A[i][k] + A[k][j])) is_ok = false;
        }
    }
    
    if (!is_ok) { cout << -1 << endl; return 0; }

    auto wf = [&](int u, int v)->void {
        for (int k = 0; k < N; k++) {
            chmin(G[u][v], G[u][k] + G[k][v]);
            chmin(G[v][u], G[v][k] + G[k][u]);
        }
    };

    UnionFind uf(N);
    long long ans = 0;
    for (auto e : edges) {
        int u, v; tie(u, v) = e.second;
        long long cost = e.first;
        if (uf.unionSet(u, v)) { G[u][v] = cost; G[v][u] = cost; ans += cost; }
        else {
            wf(u, v);
            if (chmin(G[u][v], cost)) { G[v][u] = cost; ans += cost; }
        }            
    }
    
    cout << ans << endl;
    return 0;
}