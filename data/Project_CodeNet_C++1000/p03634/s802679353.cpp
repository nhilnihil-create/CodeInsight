#include <bits/stdc++.h>
using namespace std;

// template {{{
#define  range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r) - 1; i >= (int)(l); (i) -= 1)

#define  whole(f, x, ...) ([&](decltype((x)) container) { return (f)(  begin(container),  end(container), ## __VA_ARGS__); })(x)
#define rwhole(f, x, ...) ([&](decltype((x)) container) { return (f)( rbegin(container), rend(container), ## __VA_ARGS__); })(x)

#define debug(x) cerr << "(" << __LINE__ << ")" << #x << ": " << (x) << endl

using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

// constexpr i32 mod   = 998244353;
constexpr i32 mod   = 1e9 + 7;
constexpr i32 inf   = 1001001001;
constexpr i64 infll = 1001001001001001001ll;

constexpr int dx[] = {0, -1, 1, 0, -1, 1, -1, 1};
constexpr int dy[] = {-1, 0, 0, 1, -1, -1, 1, 1};

struct IoSetup { IoSetup(int x = 15){ cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(x); cerr << fixed << setprecision(x); } } iosetup;

template <typename T = i64> T input() { T x; cin >> x; return x; }

template <typename T> ostream &operator<<(ostream &os, vector<T> &v) { range(i, 0, v.size()) { os << v[i] << (i + 1 != v.size() ? " " : ""); } return os; }
template <typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &in : v) is >> in; return is; }

template <typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1, T2> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
template <typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { is >> p.first >> p.second; return is; }

template <typename T> vector<T> make_vector(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_vector(size_t a, Ts... ts) { return vector<decltype(make_vector(ts...))>(a, make_vector(ts...)); }

template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
// }}}

// {{{
struct LowestCommonAncestor{
    int n,h;
    vector< vector<int> > G,par;
    vector<int> dep;
    LowestCommonAncestor(){}
    LowestCommonAncestor(int n):n(n),G(n),dep(n){
        h=1;
        while((1<<h)<=n) h++;
        par.assign(h,vector<int>(n,-1));
    }

    void add_edge(int u,int v){
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    void dfs(int v,int p,int d){
        par[0][v]=p;
        dep[v]=d;
        for(int u:G[v])
            if(u!=p) dfs(u,v,d+1);
    }

    void build(int r=0){
        dfs(r,-1,0);
        for(int k=0;k+1<h;k++)
            for(int v=0;v<n;v++)
                if(~par[k][v])
                    par[k+1][v]=par[k][par[k][v]];
    }

    int lca(int u,int v){
        if(dep[u]>dep[v]) swap(u,v);
        for(int k=0;k<h;k++)
            if((dep[v]-dep[u])>>k&1)
                v=par[k][v];

        if(u==v) return u;

        for(int k=h-1;k>=0;k--)
            if(par[k][u]!=par[k][v])
                u=par[k][u],v=par[k][v];

        return par[0][u];
    }

    int distance(int u,int v){
        return dep[u]+dep[v]-dep[lca(u,v)]*2;
    }
};
// }}}

void solver() {
    int n = input();

    struct edge {
        int to;
        i64 cost;
        edge() {}
        edge(int to, i64 cost) : to(to), cost(cost) {}
    };

    auto G = make_vector(n, 0, edge());
    LowestCommonAncestor lca(n);

    range(i, 0, n - 1) {
        int u = input() - 1, v = input() - 1, c = input();
        G[u].emplace_back(v, c);
        G[v].emplace_back(u, c);
        lca.add_edge(u, v);
    }

    lca.build();

    vector< i64 > dists(n, -1);
    dists[0] = 0;
    queue< int > que({0});
    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (auto &e: G[v]) {
            if (dists[e.to] != -1) continue;
            dists[e.to] = dists[v] + e.cost;
            que.emplace(e.to);
        }
    }

    auto get_distance = [&](int u, int v) {
        return dists[u] + dists[v] - 2 * dists[lca.lca(u, v)];
    };

    int q = input(), k = input() - 1;
    range(i, 0, q) {
        int x = input() - 1, y = input() - 1;
        cout << get_distance(x, k) + get_distance(k, y) << endl;
    }
}

signed main(int argc, char *argv[]) {
    solver();
}
