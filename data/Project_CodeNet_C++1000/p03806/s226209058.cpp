#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n); i >= 0; i--)
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define ALL(obj) begin(obj), end(obj)
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int INF = 2100100100;
const int MOD = 1e9 + 7;
// 多次元 vector 生成
template <class T> vector<T> make_vec(size_t a) { return vector<T>(a); }
template <class T, class... Ts> auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <class T> bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

int dp[45][420][420];

int main() {
    int N, Ma, Mb;
    cin >> N >> Ma >> Mb;

    vector<int> a(N), b(N), c(N);
    REP(i, N) { cin >> a.at(i) >> b.at(i) >> c.at(i); }

    REP(i, 45) {
        REP(j, 420) {
            REP(k, 420) { dp[i][j][k] = INF; }
        }
        dp[i][0][0] = 0;
    }

    REP(i, N) {
        REP(j, 400) {
            REP(k, 400) {
                if (dp[i][j][k] != INF) {
                    FOR(l, i, N) { chmin(dp[l + 1][j + a[i]][k + b[i]], dp[i][j][k] + c[i]); }
                }
            }
        }
    }
    /*
        REP(j, 10) {
            REP(k, 10) { cout << dp[N][j][k] << " "; }
            cout << endl;
        }
    */
    int ans = INF;
    FOR(i, 1, 405) {
        int a = i * Ma;
        int b = i * Mb;
        if (a > 400 || b > 400) {
            break;
        }
        // cout << ans << endl;
        chmin(ans, dp[N][a][b]);
    }
    if (ans != INF) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
