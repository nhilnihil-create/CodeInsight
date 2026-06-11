#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define RFOR(i, a, b) for (int i = (b)-1; i >= int(a); --i)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, int(n) + 1)
#define rrep(i, n) RFOR(i, 0, n)
#define rrep1(i, n) RFOR(i, 1, int(n) + 1)
#define all(c) begin(c), end(c)

template <typename T>
void __dump__(std::ostream &os, const T &first) {
    os << first;
}
template <typename First, typename... Rest>
void __dump__(std::ostream &os, const First &first, const Rest &... rest) {
    os << first << ", ";
    __dump__(os, rest...);
}
#define dump(...)                                         \
    do {                                                  \
        std::ostringstream os;                            \
        os << __LINE__ << ":\t" << #__VA_ARGS__ << " = "; \
        __dump__(os, __VA_ARGS__);                        \
        std::cerr << os.str() << std::endl;               \
    } while (0)

struct uf_tree {
    std::vector<int> parent;
    int __size;
    uf_tree(int size_) : parent(size_, -1), __size(size_) {}
    void unite(int x, int y) {
        if ((x = find(x)) != (y = find(y))) {
            if (parent[y] < parent[x]) std::swap(x, y);
            parent[x] += parent[y];
            parent[y] = x;
            __size--;
        }
    }
    bool is_same(int x, int y) { return find(x) == find(y); }
    int find(int x) { return parent[x] < 0 ? x : parent[x] = find(parent[x]); }
    int size(int x) { return -parent[find(x)]; }
    int size() { return __size; }
};

using Weight = int;
using Flow = int;
struct Edge {
    int src, dst;
    Weight weight;
    Flow cap;
    Edge() : src(0), dst(0), weight(0) {}
    Edge(int s, int d, Weight w) : src(s), dst(d), weight(w) {}
};
using Edges = std::vector<Edge>;
using Graph = std::vector<Edges>;
using Array = std::vector<Weight>;
using Matrix = std::vector<Array>;

void add_edge(Graph &g, int a, int b, Weight w = 1) {
    g[a].emplace_back(a, b, w);
    g[b].emplace_back(b, a, w);
}
void add_arc(Graph &g, int a, int b, Weight w = 1) { g[a].emplace_back(a, b, w); }

int n, m;
Graph g;
int color[100010];

bool dfs(int v, int c) {
    color[v] = c;
    bool res = true;
    for(auto &e : g[v]){
        if(color[e.dst] == -c) continue;
        if(color[e.dst] == c) res = false;
        if(color[e.dst] == 0) if(!dfs(e.dst, -c)) res = false;
    }
    return res;
}

signed main(){
    while(cin >> n >> m){
        memset(color, 0, sizeof color);
        g.assign(n, {});
        rep(i, m){
            int a, b;
            cin >> a >> b;
            --a; --b;
            add_edge(g, a, b);
        }
        int a = 0, b = 0, c = 0;
        rep(i, n){
            if(color[i]) continue;
            if(g[i].size() == 0){
                ++a;
            } else {
                if(dfs(i, 1)) ++b; else ++c;
            }
        }
        dump(a, b, c);
        int ans = 0;
        ans += a*a;
        ans += 2*a*(n-a);
        ans += (b+c)*(b+c);
        ans += b*b;
        cout << ans << endl;
    }
}
