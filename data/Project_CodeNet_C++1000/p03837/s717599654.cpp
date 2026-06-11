#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N, M;
    cin >> N >> M;

    vec<vec<pair<int, int>>> G(N);
    vec<vec<int>> W(N, vec<int>(N, 1e9 + 7));
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
        W[a][b] = c;
        W[b][a] = c;
    }
    rep(i, N) W[i][i] = 0;

    function<void(int)> warshall_floyd = [&](int n) {
        for (int k = 0; k < n; k++) {            // 経由する頂点
            for (int i = 0; i < n; i++) {        // 始点
                for (int j = 0; j < n; j++) {    // 終点
                    W[i][j] = min(W[i][j], W[i][k] + W[k][j]);
                }
            }
        }
    };
    warshall_floyd(N);

    set<pair<int,int>> s;

    function<void(int, int, int, int, int, vec<int>)> dfs =
        [&](int now, int par, int end, int d, int maxd, vec<int> v) {
            if(now==end && d ==maxd){
                for(int i=1;i<v.size();++i){
                    int a = v[i-1];
                    int b = v[i];
                    if(a>b) swap(a,b);
                    s.insert({a,b});
                }
                return;
            }
            for (auto e : G[now]) {
                int next = e.first;
                int dist = e.second;
                if (next == par) continue;
                if (d + dist > maxd) continue;
                v.push_back(next);
                dfs(next, now, end, d + dist, maxd, v);
                v.pop_back();
            }
        };

    rep(i, N) rep(j, i) {
        dfs(j, -1, i, 0, W[j][i], vec<int>(1,j));
    }
    cout << M-s.size() << '\n';
}
