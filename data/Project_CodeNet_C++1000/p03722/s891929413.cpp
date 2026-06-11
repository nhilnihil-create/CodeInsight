#include <bits/stdc++.h>
//#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;
//const int mod = 998244353;

template <typename T>
struct BellmanFord
{
    static constexpr T INF = numeric_limits<T>::max();

    struct edge
    {
        int u, v;
        T w;
        edge() {}
        edge(int u, int v, T w) : u(u), v(v), w(w) {}
    };

    int n;
    vector<vector<int>> G;
    vector<int> used, reach;
    BellmanFord(int n) : n(n), G(n), used(n, 0), reach(n, 1) {}

    vector<edge> es;
    void add_edge(int u, int v, T c)
    {
        es.emplace_back(u, v, c);
        G[u].emplace_back(v);
    }

    vector<T> build(int from, int &neg_loop)
    {
        vector<T> ds(n, INF);
        ds[from] = 0;
        for (int j = 0; j < n; j++)
        {
            bool update = 0;
            for (auto e : es)
            {
                if (!reach[e.u] || !reach[e.v] || ds[e.u] == INF)
                    continue;
                if (ds[e.v] > ds[e.u] + e.w)
                {
                    ds[e.v] = ds[e.u] + e.w;
                    update = 1;
                }
            }
            if (!update)
                break;
            if (j == n - 1)
            {
                neg_loop = 1;
                return ds;
            }
        }
        neg_loop = 0;
        return ds;
    }

    void dfs(int v)
    {
        if (used[v])
            return;
        used[v] = 1;
        for (int u : G[v])
            dfs(u);
    }

    T shortest_path(int from, int to, int &neg_loop)
    {
        for (int i = 0; i < n; i++)
        {
            fill(used.begin(), used.end(), 0);
            dfs(i);
            reach[i] = used[to];
        }
        return build(from, neg_loop)[to];
    }
};
template <typename T>
constexpr T BellmanFord<T>::INF;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    BellmanFord<int> G(n);
    rep(i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        c *= -1;
        G.add_edge(a, b, c);
    }
    int neg_loop;
    int ans = -G.shortest_path(0, n - 1, neg_loop);
    if (neg_loop)
        cout << "inf" << endl;
    else
        cout << ans << endl;
}