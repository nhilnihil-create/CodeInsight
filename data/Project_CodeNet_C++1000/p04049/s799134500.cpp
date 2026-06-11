// Template
#include <bits/stdc++.h>
#define rep_override(x, y, z, name, ...) name
#define rep2(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, r) for (int i = (l); i < (r); ++i)
#define rep(...) rep_override(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll INF = 3003003003003003003;
template <class T> inline bool chmin(T &x, const T &y) {if (x > y) {x = y; return 1;} return 0;}
template <class T> inline bool chmax(T &x, const T &y) {if (x < y) {x = y; return 1;} return 0;}
struct IOSET {IOSET() {cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10);}} ioset;

// Main Code
int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(2 * n - 1);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        int c = n + i;
        g[a].push_back(c); g[c].push_back(a);
        g[b].push_back(c); g[c].push_back(b);
    }
    
    vector<vector<int>> dist(2 * n - 1, vector<int>(2 * n - 1, -1));
    rep(i, 2 * n - 1) {
        queue<int> q;
        q.push(i);
        dist[i][i] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v: g[u]) {
                if (dist[i][v] == -1) {
                    dist[i][v] = dist[i][u] + 1;
                    q.push(v);
                }
            }
        }
    }
    
    int ans = inf;
    rep(i, 2 * n - 1) {
        int res = 0;
        rep(j, n) {
            if (dist[i][j] > k) ++res;
        }
        chmin(ans, res);
    }
    cout << ans << "\n";
    return 0;
}
