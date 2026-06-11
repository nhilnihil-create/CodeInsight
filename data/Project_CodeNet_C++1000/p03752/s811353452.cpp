#include <bits/stdc++.h>
#define LOOP(n) for (int _i = 0; _i < (n); _i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, r, n) for (int i = (r); i < (n); ++i)
#define ALL(obj) begin(obj), end(obj)
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int INF = 2100100100;
const int MOD = 1e9 + 7;

// 多次元 vector 生成
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

int N, M, K, Q;

int main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);

    cin >> N >> K;
    vector<ll> a(N);
    REP(i, N) cin >> a.at(i);

    ll ans = 1e18;
    REP(bit, 1 << N) {
        if (__builtin_popcount(bit) == K) {
            ll now = 0;
            ll sum = 0;
            REP(i, N) {
                int mask = 1 << i;
                if (bit & mask) {
                    if (now < a[i]) {
                        now = a[i];
                    } else {
                        now = now + 1;
                        sum += now - a[i];
                    }
                } else {
                    now = max(now, a[i]);
                }
            }
            chmin(ans, sum);
        }
    }
    cout << ans << endl;

    return 0;
}
