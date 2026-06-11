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
    string s, t;
    int q;
    cin >> s >> t >> q;
    int lens = (int)s.size(), lent = (int)t.size();

    vector<int> cnts(lens+1), cntt(lens+1);
    for (int i=1; i<lens+1; ++i) {
        if (s.at(i-1) == 'A') cnts.at(i) = cnts.at(i-1) + 1;
        else cnts.at(i) = cnts.at(i-1) + 2;
    }
    for (int i=1; i<lent+1; ++i) {
        if (t.at(i-1) == 'A') cntt.at(i) = cntt.at(i-1) + 1;
        else cntt.at(i) = cntt.at(i-1) + 2;
    }

    vector<bool> res(q);
    for (int i=0; i<q; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int sv = cnts.at(b) - cnts.at(a-1), tv = cntt.at(d) - cntt.at(c-1);
        if (sv%3 == tv%3) res.at(i) = true;
        else res.at(i) = false;
    }
    for (auto b : res) {
        if (b) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
