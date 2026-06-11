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
    int n, ma, mb;
    cin >> n >> ma >> mb;
    vector<int> a(n), b(n), c(n);
    rep(i, n) {
        cin >> a[i] >> b[i] >> c[i];
    }

    auto dp = make_vec<int>(50, 500, 500);
    rep(i, 50) rep(j, 500) rep(k, 500) dp[i][j][k] = INF;
    dp[0][0][0] = 0;
    rep(i, n) {
        rep(j, 500) {
            rep(k, 500) {
                if (j - a[i] >= 0 && k - b[i] >= 0) {
                    chmin(dp[i + 1][j][k], dp[i][j - a[i]][k - b[i]] + c[i]);
                }
                chmin(dp[i + 1][j][k], dp[i][j][k]);
            }
        }
    }

    int ans = INF;
    rep(a, 500) rep(b, 500) {
        if (a * b == 0) continue;
        if (a * mb != b * ma) continue;
        chmin(ans, dp[n][a][b]);
    }
    cout << (ans == INF ? -1 : ans) << endl;
}
