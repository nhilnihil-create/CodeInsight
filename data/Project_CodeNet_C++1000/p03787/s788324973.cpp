#include "bits/stdc++.h"
using namespace std;
using ll     = long long;
using pii    = pair<int, int>;
using pll    = pair<ll, ll>;
using vi     = vector<int>;
using vl     = vector<ll>;
using vvi    = vector<vi>;
using vvl    = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}
template <class C>
void print(const C &c, std::ostream &os = std::cout) {
    std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, " "));
    os << std::endl;
}

struct UnionFind {
    vector<int> rank, parent, size;

    // +1 for 1-indexed nodes
    UnionFind(int n) : rank(n + 1, 0), parent(n + 1), size(n + 1, 1) {
        iota(parent.begin(), parent.end(), 0); // parent is itself
    }
    int root(int x) {
        if (x != parent[x]) {
            parent[x] = root(parent[x]);
        }
        return parent[x];
    }
    bool isSame(int x, int y) { return root(x) == root(y); }
    bool unite(int x, int y) { return link(root(x), root(y)); }
    bool link(int x, int y) {
        if (x == y)
            return false;
        if (rank[x] > rank[y]) {
            parent[y] = x;
            size[x] += size[y];
        } else {
            parent[x] = y;
            size[y] += size[x];
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
        return true;
    }
    int getSize(int x) { return size[root(x)]; }
};

// ref: http://prd-xxx.hateblo.jp/entry/2017/10/13/004256
struct BipartileGraph {
    vi colors;
    vvi edges;
    int n;
    BipartileGraph(int n) : colors(n, -1), edges(n), n(n) {}
    void addEdge(int f, int t) {
        edges[f].emplace_back(t);
        edges[t].emplace_back(f);
    }
    void clear() { colors.resize(n, -1); }
    // true = bipartile
    bool build(int s, int color = 0) {
        colors[s] = color;
        for (auto &e : edges[s]) {
            if (colors[e] == color)
                return false;
            if (colors[e] == -1 && !build(e, color ^ 1))
                return false;
        }
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    BipartileGraph g(n);
    UnionFind uf(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g.addEdge(a, b);
        uf.unite(a, b);
    }
    vector<bool> used(100001, false);
    ll twoes  = 0;
    ll num    = 0;
    ll single = n;
    for (int i = 0; i < n; ++i) {
        int r = uf.root(i);
        if (used[r])
            continue;
        int s   = uf.getSize(r);
        used[r] = true;
        if (s != 1) {
            num++;
            single -= s;
            g.clear();
            if (g.build(r)) {
                twoes++;
            }
        }
    }
    ll ret = num * num;
    ret += twoes * twoes;
    ret += 2 * n * single - single * single;
    cout << ret << "\n";
    return 0;
}