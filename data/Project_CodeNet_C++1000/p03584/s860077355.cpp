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
    int n, k;
    cin >> n >> k;
    vector<pair<int, ll>> ab(n);
    for (int i=0; i<n; ++i) cin >> ab.at(i).first >> ab.at(i).second;

    ll res = 0;
    int mask = (1<<30) - 1;
    for (int i=29; i>=0; --i) {
        mask -= 1<<i;
        if (k & (1<<i)) {
            ll tmp = 0;
            for (auto p : ab) {
                int a = p.first;
                ll b = p.second;
                if ((a | mask) == mask) tmp += b;
            }
            chmax(res, tmp);
            mask += 1<<i;
        }
    }
    ll tmp = 0;
    for (auto p : ab) {
        int a = p.first;
        ll b = p.second;
        if ((a | k) == k) tmp += b;
    }
    chmax(res, tmp);
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
