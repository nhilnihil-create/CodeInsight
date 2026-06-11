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

int dfs(int cur, const Graph &G) {
    int n = (int)G.at(cur).size();
    vector<int> cnt(n);
    for (int i=0; i<n; ++i) {
        cnt.at(i) = dfs(G.at(cur).at(i), G);
    }
    sort(cnt.rbegin(), cnt.rend());
    int res = 0;
    for (int i=0; i<n; ++i) chmax(res, cnt.at(i)+i+1);
    return res;
}

void solve() {
    int n;
    cin >> n;
    Graph G(n);
    for (int i=1; i<n; ++i) {
        int a;
        cin >> a;
        G.at(a-1).push_back(i);
    }

    cout << dfs(0, G) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
