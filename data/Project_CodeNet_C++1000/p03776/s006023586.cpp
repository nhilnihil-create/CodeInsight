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

long long comb(long long n, long long r) {
    long long r_new = (r <= n/2) ? r : n-r;
    if (r_new < 0) return 0;
    if (r_new == 0) return 1;
    else return (n-r_new+1) * comb(n, r_new-1) / r_new;
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    for (int i=0; i<n; ++i) {
        cin >> v.at(i);
    }

    sort(v.rbegin(), v.rend());
    double sum = 0.0;
    for (int i=0; i<a; ++i) sum += v.at(i);
    cout << sum / a << '\n';

    map<ll, int> mp;
    for (ll x : v) ++mp[x];
    int cnt = -1;
    for (int i=0; i<a; ++i) {
        if (v.at(i) == v.at(a-1)) {
            cnt = i;
            break;
        }
    }
    if (cnt == 0) {
        ll res = 0;
        int dif = b - a;
        int num = mp[v.at(a-1)];
        for (int i=0; i<dif+1; ++i) {
            res += comb(num, a+i);
        }
        cout << res << '\n';
    } else {
        int num = mp[v.at(a-1)];
        cout << comb(num, a-cnt) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
