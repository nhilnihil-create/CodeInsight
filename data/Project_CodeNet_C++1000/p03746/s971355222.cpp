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
    int n, m;
    cin >> n >> m;
    Graph G(n);
    for (int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        G.at(a-1).push_back(b-1);
        G.at(b-1).push_back(a-1);
    }

    deque<int> res;
    vector<bool> used(n, false);
    int cur = 0;
    while (true) {
        used.at(cur) = true;
        res.push_back(cur);
        bool end = true;
        for (int nx : G.at(cur)) {
            if (!used.at(nx)) {
                used.at(nx) = true;
                cur = nx;
                end = false;
                break;
            }
        }
        if (end) break;
    }

    auto check = [&used, &G](int s) -> int {
        for (int nx : G.at(s)) {
            if (!used.at(nx)) {
                return nx;
            }
        }
        return -1;
    };
    int s = 0;
    while ((s = check(s)) != -1) {
        used.at(s) = true;
        res.push_front(s);
    }

    cout << res.size() << '\n';
    for (int i=0; i<(int)res.size(); ++i) {
        cout << res.at(i) + 1;
        if (i == (int)res.size()-1) cout << '\n';
        else cout << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
