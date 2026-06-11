#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

struct edge {
    int from, to; ll cost;
    edge(int from, int to, ll cost) : from(from), to(to), cost(cost) {}
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<edge> es;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        es.emplace_back(a, b, -c);
    }

    vector<ll> d(n, linf);
    d[0] = 0;
    for (int i = 0; i < n * 2; i++) {
        for (auto &e: es) {
            if (d[e.from] < linf && d[e.from] + e.cost < d[e.to]) {
                if (i < n - 1) {
                    d[e.to] = d[e.from] + e.cost;
                } else {
                    d[e.to] = -linf;
                }
            }
        }
    } 

    if (d[n - 1] <= -linf) cout << "inf" << endl;
    else cout << -d[n - 1] << endl;
    return 0;
}
