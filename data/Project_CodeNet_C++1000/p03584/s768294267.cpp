#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define FORR(i, m, n) for (int i = (m); i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) FORR(i, n - 1, 0)
#define REP1(i, n) FOR(i, 1, (n) + 1)
#define ALL(c) (c).begin(), (c).end()
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
const int MOD = 1000000007;
const int INF = 1000000001;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> v(n);
    int a, b;
    REP(i, n) {
        cin >> a >> b;
        v[i] = make_pair(a, b);
    }

    auto calc = [&](int x) {
        ll r = 0;
        for (auto p : v) if ((p.first | x) == x) r += p.second;
        return r;
    };

    ll ans = calc(k);

    REP1(i, 30) {
        int b = (1 << i);
        if ((k & b) == 0) continue;
        int t = (k - b) | (b - 1);
        chmax(ans, calc(t));
    }

    cout << ans << endl;
}
