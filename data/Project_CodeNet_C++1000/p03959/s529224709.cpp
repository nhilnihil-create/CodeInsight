#include <bits/stdc++.h>
#define LOOP(n) for (int _i = 0; _i < (n); _i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, r, n) for (int i = (r); i < (n); ++i)
#define ALL(obj) begin(obj), end(obj)
using namespace std;
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
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

using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
const int INF = 2100100100;
const int MOD = 1e9 + 7;

int N, M, K, Q, W, H, R, C;
string S;

int main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);

    cin >> N;
    vector<int> T(N + 1, 0), A(N + 1, 0), H_max(N, INF), H_min(N, 0);
    REP(i, N) cin >> T.at(i + 1);
    REP(i, N) cin >> A.at(i);

    FOR(i, 1, N + 1) {
        if (T[i - 1] < T[i]) {
            chmin(H_max[i - 1], T[i]);
            chmax(H_min[i - 1], T[i]);
        } else {
            chmin(H_max[i - 1], T[i]);
            chmax(H_min[i - 1], 1);
        }
    }

    RREP(i, N - 1) {
        if (A[i] > A[i + 1]) {
            chmin(H_max[i], A[i]);
            chmax(H_min[i], A[i]);
        } else {
            chmin(H_max[i], A[i]);
            chmax(H_min[i], 1);
        }
    }
    /*REP(i, N) { cout << H_max[i] << " "; }
    cout << endl;
    REP(i, N) { cout << H_min[i] << " "; }
    cout << endl;
*/
    ll ans = 1;
    REP(i, N) {
        ll num = (ll)(H_max[i] - H_min[i] + 1);
        if (num <= 0) {
            cout << 0 << endl;
            return 0;
        }
        ans *= num;
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}
