#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*
 * Supports O(logN) lowest common ancestor queries on an immutable tree.
 */
struct lowest_common_ancestor_log {
    int L, N;
    vi depth, link;

    lowest_common_ancestor_log() { }

    lowest_common_ancestor_log(const vvi &graph, int root = 0) : N(graph.size()) {
        L = 32 - __builtin_clz(N);
        depth.resize(N);
        link.resize(L*N);
        init(root, root, graph);
    }

    /*
     * Initializes the link table in O(NlogN). link[l * N + i] contains the index
     * of the (2 ** l)th ancestor of vertex i.
     */
    void init(int loc, int par, const vvi &graph) {
        link[loc] = par;
        for (int l = 1; l < L; l++)
            link[l*N + loc] = link[(l-1)*N + link[(l-1)*N + loc]];

        for (int nbr : graph[loc]) if (nbr != par) {
            depth[nbr] = depth[loc] + 1;
            init(nbr, loc, graph);
        }
    }

    // Returns the index of the dist-th ancestor of vertex loc in O(logN).
    int above(int loc, int dist) {
        dist = min(dist, N - 1);
        for (int l = 0; l < L; l++) if (dist & (1 << l)) {
            loc = link[l*N + loc];
        }
        return loc;
    }

    // Returns the least common ancestor of vertices u and v in O(logN).
    int lca(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        v = above(v, depth[v] - depth[u]);
        if (u == v) return u;

        for (int l = L - 1; l >= 0; l--) {
            if (link[l*N + u] != link[l*N + v])
                u = link[l*N + u], v = link[l*N + v];
        }
        return link[u];
    }

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    bool on_path(int u, int v, int inx) {
        return dist(u, v) == dist(u, inx) + dist(inx, v);
    }
};

void go(auto& g, auto& ord, auto& in, auto& out, auto& dep, int loc) {
    in[loc] = ord.size();
    ord.push_back(loc);
    for (int ch : g[loc]) {
        dep[ch] = dep[loc] + 1;
        go(g, ord, in, out, dep, ch);
    }
    out[loc] = ord.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    cin >> N >> K;

    vvi g(N);

    vi par(N);
    for (int i = 0; i < N; i++) {
        cin >> par[i];
        --par[i];
        if (i) {
            g[par[i]].push_back(i);
        }
    }

    int ans = 0;
    if (par[0]) {
        par[0] = 0;
        ans++;
    }

    vi ord, in(N), out(N), dep(N);
    go(g, ord, in, out, dep, 0);
    lowest_common_ancestor_log lca(g);

    set<int> alive;
    vi dord;
    for (int i = 0; i < N; i++) {
        alive.insert(i);
        dord.push_back(i);
    }
    sort(all(dord), [&](int i, int j) { return dep[i] > dep[j]; });

    for (int v : dord) {
        if (!alive.count(in[v])) continue;

        int l = lca.above(v, K - 1);
        if (par[l]) {
            ans++;
            par[l] = 0;
            auto it = alive.lower_bound(in[l]);
            while (it != alive.end() && *it < out[l])
                alive.erase(it++);
        }
    }

    cout << ans << endl;

    return 0;
}

