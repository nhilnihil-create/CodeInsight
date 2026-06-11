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
    int n;
    cin >> n;
    WGraph G(n);
    for (int i=0; i<n-1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        G.at(a-1).push_back({b-1, c});
        G.at(b-1).push_back({a-1, c});
    }
    int q, k;
    cin >> q >> k;
    --k;

    vector<ll> fromK(n, -1);
    fromK.at(k) = 0;
    queue<int> que;
    que.push(k);
    while (!que.empty()) {
        int cur = que.front(); que.pop();
        for (auto p : G.at(cur)) {
            if (fromK.at(p.first) == -1) {
                fromK.at(p.first) = fromK.at(cur) + p.second;
                que.push(p.first);
            }
        }
    }

    vector<ll> res(q);
    for (int i=0; i<q; ++i) {
        int x, y;
        cin >> x >> y;
        res.at(i) = fromK.at(x-1) + fromK.at(y-1);
    }
    for (ll x : res) cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
