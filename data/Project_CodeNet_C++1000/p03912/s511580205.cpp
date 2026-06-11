#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(unique(all(x)), x.end());
typedef long long ll;
typedef complex<double> Complex;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    vector<int> cnt(100100);
    rep(i, n) {
        cin >> x[i];
        cnt[x[i]]++;
    }

    int ans = 0;
    vector<int> v(m);
    vector<int> p(m);
    for (int i = 1; i <= 100000; i++) {
        if (cnt[i] == 0) continue;
        v[i % m] += cnt[i];
        p[i % m] += cnt[i] / 2;
    }

    ans += v[0] / 2;
    if (m % 2 == 0) ans += v[m / 2] / 2;

    for (int i = 1; i < m - i; i++) {
        if (v[i] >= v[m - i]) {
            ans += v[m - i];
            ans += min(p[i], (v[i] - v[m - i]) / 2);
        } else {
            ans += v[i];
            ans += min(p[m - i], (v[m - i] - v[i]) / 2);
        }
    }
    cout << ans << endl;
}