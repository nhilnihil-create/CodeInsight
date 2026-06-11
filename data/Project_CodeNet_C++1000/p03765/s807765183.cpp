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

    vector<int> cntsa(lens+1), cntsb(lens+1), cntta(lent+1), cnttb(lent+1);
    for (int i=1; i<lens+1; ++i) {
        cntsa.at(i) = cntsa.at(i-1);
        cntsb.at(i) = cntsb.at(i-1);
        if (s.at(i-1) == 'A') ++cntsa.at(i);
        else ++cntsb.at(i);
    }
    for (int i=1; i<lent+1; ++i) {
        cntta.at(i) = cntta.at(i-1);
        cnttb.at(i) = cnttb.at(i-1);
        if (t.at(i-1) == 'A') ++cntta.at(i);
        else ++cnttb.at(i);
    }

    vector<bool> res(q);
    for (int i=0; i<q; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int sa = cntsa.at(b) - cntsa.at(a-1), sb = cntsb.at(b) - cntsb.at(a-1);
        int ta = cntta.at(d) - cntta.at(c-1), tb = cnttb.at(d) - cnttb.at(c-1);
        int ma = (ta - sa) % 3, mb = (tb - sb) % 3;
        if (ma < 0) ma += 3;
        if (mb < 0) mb += 3;
        if (ma == mb) res.at(i) = true;
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
