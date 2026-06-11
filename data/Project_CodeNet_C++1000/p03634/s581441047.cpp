#include <bits/stdc++.h>
#define FASTIO
using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

template <typename _Ty>
struct Edge {
    int src, to;
    _Ty cost;

    constexpr Edge(int _to, _Ty _cost) noexcept
        : src(-1), to(_to), cost(_cost) {}
    constexpr Edge(int _src, int _to, _Ty _cost) noexcept
        : src(_src), to(_to), cost(_cost) {}
};
template <typename _Ty>
using WeightedGraph = std::vector<std::vector<Edge<_Ty>>>;

WeightedGraph<ll> g;
int N;
Vl dist;

void dfs(int idx, int par, ll d) {
    dist[idx] = d;
    for (const auto& to : g[idx]) {
        if (to.to == par) continue;
        dfs(to.to, idx, d + to.cost);
    }
}


int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif

    cin >> N;
    g.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }

    int Q, K;
    cin >> Q >> K;
    --K;

    dist.resize(N);
    dfs(K, -1, 0);

    while (Q--) {
        int x, y;
        cin >> x >> y;
        --x, --y;

        cout << dist[x] + dist[y] << '\n';
    }

    return 0;
}