#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

long long bellmanFord(const WGraph &G, const int s, const int t) {
    int N = (int)G.size();
    std::vector<long long> dis(N, LINF);

    // seek shortest path
    dis[s] = 0;
    for (int i=0; i<N-1; ++i) {
        for (int j=0; j<N; ++j) {
            for (auto e : G[j]) {
                if (dis[e.first] > dis[j] + e.second) dis[e.first] = dis[j] + e.second;
            }
        }
    }

    // find negative loop
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            for (auto e : G[j]) {
                if (dis[e.first] > dis[j] + e.second) {
                    if (e.first == t) return -LINF;
                    dis[e.first] = dis[j] + e.second;
                }
            }
        }
    }

    return dis[t];
}

void solve() {
    int N, M;
    cin >> N >> M;
    WGraph G(N);
    for (int i=0; i<M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a-1].push_back({b-1, -c});
    }

    ll res = -bellmanFord(G, 0, N-1);
    if (res == LINF) cout << "inf" << '\n';
    else cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
