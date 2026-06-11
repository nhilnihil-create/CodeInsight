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

bitset<5555> dp;
ll N, K;
VL a;

bool check(ll k) {
    dp.reset();
    dp.set(0);
    REP(j, N) {
        if(k == j) continue;
        dp |= dp << a[j];
    }
    FOR(val, max(K - a[k], 0LL), K) {
        if(dp.test(val)) {
            return true;
        }
    }
    return false;
}
signed main() {
    cin >> N >> K;
    a.resize(N);
    VECCIN(a);
    sort(All(a));
    ll lb = -1, ub = N;
    while(ub - lb > 1) {
        ll mid = (ub + lb) / 2;
        if(check(mid))
            ub = mid;
        else
            lb = mid;
    }
    cout << lb + 1 << "\n";
}
