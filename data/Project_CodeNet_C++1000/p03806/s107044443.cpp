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

void solve() {
    int n, ma, mb;
    cin >> n >> ma >> mb;
    vector<pair<int, int>> ab(n);
    vector<int> c(n);
    for (int i=0; i<n; ++i) cin >> ab.at(i).first >> ab.at(i).second >> c.at(i);

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(401, vector<int>(401, INF)));
    dp.at(0).at(0).at(0) = 0;
    for (int i=1; i<n+1; ++i) {
        int a = ab.at(i-1).first, b = ab.at(i-1).second;
        for (int j=0; j<401; ++j) {
            for (int k=0; k<401; ++k) {
                chmin(dp.at(i).at(j).at(k), dp.at(i-1).at(j).at(k));
                if (j >= a && k >= b) chmin(dp.at(i).at(j).at(k), dp.at(i-1).at(j-a).at(k-b) + c.at(i-1));
            }
        }
    }
    int res = INF;
    for (int i=1; i<401; ++i) {
        for (int j=1; j<401; ++j) {
            if (ma * j == mb * i) chmin(res, dp.at(n).at(i).at(j));
        }
    }
    cout << (res == INF ? -1 : res) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
