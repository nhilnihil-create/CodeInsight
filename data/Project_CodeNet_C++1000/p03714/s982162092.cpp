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

signed main() {
    LCIN(N);
    VL a(3 * N);
    VECCIN(a);
    VL fsum(N + 1), bsum(N + 1);
    PQG<ll> fp;
    PQ<ll> bp;
    REP(i, N) {
        fsum[0] += a[i];
        fp.emplace(a[i]);
    }
    REP(i, N) {
        bsum[0] += a[3 * N - 1 - i];
        bp.emplace(a[3 * N - 1 - i]);
    }
    REP(i, N) {
        fp.emplace(a[N + i]);
        ll ft = fp.top();
        fp.pop();
        fsum[i + 1] = fsum[i] + a[N + i] - ft;
        bp.emplace(a[2 * N - 1 - i]);
        ll bt = bp.top();
        bp.pop();
        bsum[i + 1] = bsum[i] + a[2 * N - 1 - i] - bt;
    }
    ll ans = -LINF;
    REP(i, N + 1) { ans = max(ans, fsum[i] - bsum[N - i]); }
    cout << ans << "\n";
}
