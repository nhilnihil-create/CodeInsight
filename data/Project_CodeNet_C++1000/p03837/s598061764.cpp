// Template
#include <bits/stdc++.h>
#define rep_override(x, y, z, name, ...) name
#define rep2(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define rep(...) rep_override(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define per(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll INF = 3003003003003003003;
template <typename T> inline bool chmin(T& x, const T& y) {if (x > y) {x = y; return 1;} return 0;}
template <typename T> inline bool chmax(T& x, const T& y) {if (x < y) {x = y; return 1;} return 0;}
struct IOSET {IOSET() {cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10);}} ioset;

// Main
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(n, inf));
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        g[a][b] = c; g[b][a] = c;
    }
    rep(i, n) g[i][i] = 0;
    
    vector<vector<int>> dist = g;
    rep(k, n) rep(i, n) rep(j, n) chmin(dist[i][j], dist[i][k] + dist[k][j]);
    
    int ans = m;
    rep(i, n) rep(j, i + 1, n) {
        if (g[i][j] == inf) continue;
        rep(x, n) rep(y, n) {
            if (dist[x][i] + g[i][j] + dist[j][y] == dist[x][y]) {
                --ans;
                goto ioi;
            }
        }
    ioi:;
    }
    
    cout << ans << "\n";
}
