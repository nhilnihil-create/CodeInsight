#pragma region Macros
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;
#pragma endregion

// Warshall–Floyd algorithm ワーシャルフロイド法
std::vector<std::vector<long long>> warshallFloyd(const WGraph &G) {
    int n = (int)G.size();
    std::vector<std::vector<long long>> dis(n, std::vector<long long>(n, LINF));
    for (int i=0; i<n; i++) {
        dis.at(i).at(i) = 0;
    }
    for (int i=0; i<n; i++) {
        for (auto e : G.at(i)) {
            dis.at(i).at(e.first) = e.second;
        }
    }

    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                dis.at(i).at(j) = std::min(dis.at(i).at(j), dis.at(i).at(k) + dis.at(k).at(j));
            }
        }
    }

    return dis;
}

void solve() {
    int n, m;
    cin >> n >> m;
    WGraph G(n);
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        G.at(a-1).push_back({b-1, c});
        G.at(b-1).push_back({a-1, c});
    }

    int res = 0;
    auto dis = warshallFloyd(G);
    for (int i=0; i<n; i++) {
        for (auto p : G.at(i)) {
            if (dis.at(i).at(p.first) < p.second) {
                res++;
            }
        }
    }

    cout << res / 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
