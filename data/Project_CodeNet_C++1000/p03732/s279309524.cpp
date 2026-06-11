#include <bits/stdc++.h>

using namespace std;

#define int long long
// #define double long double
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define FORR(i, a, b) for(ll i = (a); i > (b); --i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOREACH(x, a) for(auto &(x) : (a))
#define VECCIN(x)                                                              \
    for(auto &youso_ : (x)) cin >> youso_
#define bitcnt __builtin_popcount
#define SZ(x) ((ll)(x).size())
#define fi first
#define se second
#define All(a) (a).begin(), (a).end()
#define rAll(a) (a).rbegin(), (a).rend()
template <typename T = long long> inline T IN() {
    T x;
    cin >> x;
    return (x);
}
inline void CIN() {}
template <class Head, class... Tail>
inline void CIN(Head &&head, Tail &&... tail) {
    cin >> head;
    CIN(move(tail)...);
}
#define CCIN(...)                                                              \
    char __VA_ARGS__;                                                          \
    CIN(__VA_ARGS__)
#define DCIN(...)                                                              \
    double __VA_ARGS__;                                                        \
    CIN(__VA_ARGS__)
#define LCIN(...)                                                              \
    ll __VA_ARGS__;                                                            \
    CIN(__VA_ARGS__)
#define SCIN(...)                                                              \
    string __VA_ARGS__;                                                        \
    CIN(__VA_ARGS__)
#define Printv(v)                                                              \
    {                                                                          \
        REP(x, v.size()) { cout << v[x] << (x == v.size() - 1 ? "\n" : " "); } \
    }
template <typename T = string> inline void eputs(T s) {
    cout << s << "\n";
    exit(0);
}
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
    std::fill((T *)array, (T *)(array + N), val);
}
template <typename T> using PQG = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using PQ = priority_queue<T>;

typedef long long ll;
typedef pair<ll, ll> PL;
typedef vector<PL> VPL;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<double> VD;

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
const ll dx[] = {1, 0, -1, 0};
const ll dy[] = {0, 1, 0, -1};
#define PI 3.141592653589793238

ll dp[2][110][303];
VL w(100), v(100);
ll w0;

signed main() {
    LCIN(N, W);
    REP(i, N) {
        cin >> w[i] >> v[i];
        if(i == 0)
            w0 = w[0], w[0] = 0;
        else
            w[i] -= w0;
    }
    ll now = 0, next = 1;
    REP(i, N) {
        Fill(dp[next], 0LL);
        REP(j, N + 1) REP(k, 303) {
            if(k - w[i] >= 0 && j) {
                dp[next][j][k] =
                    max(dp[now][j][k], dp[now][j - 1][k - w[i]] + v[i]);
            } else
                dp[next][j][k] = dp[now][j][k];
        }
        swap(now, next);
    }
    ll ans = 0;
    REP(j, N + 1) REP(k, 303) {
        if(j * w0 + k <= W) ans = max(ans, dp[now][j][k]);
    }
    cout << ans << "\n";
}
