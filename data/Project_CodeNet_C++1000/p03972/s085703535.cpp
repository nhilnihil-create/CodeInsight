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
    ll w, h;
    cin >> w >> h;
    vector<ll> p(w), q(h);
    for (int i=0; i<w; ++i) cin >> p.at(i);
    for (int i=0; i<h; ++i) cin >> q.at(i);

    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    ll res = 0;
    ll cnt = (h+1) * (w+1) - 1;
    ll curP = 0, curQ = 0;
    while (cnt > 0) {
        bool addP = true;
        if (curP == w || (curQ < h && p.at(curP) > q.at(curQ))) addP = false;
        ll add = addP ? h+1-curQ : w+1-curP;
        chmin(add, cnt);
        cnt -= add;
        res += add * (addP ? p.at(curP++) : q.at(curQ++));
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
