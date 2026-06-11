#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORR(i, a, b) for(int i = (a); i > (b); --i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOREACH(x, a) for(auto &(x) : (a))
#define VECCIN(x)                                                              \
    for(auto &youso_ : (x)) cin >> youso_
#define mp make_pair
#define bitcnt __builtin_popcount
#define All(a) (a).begin(), (a).end()
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
#define CINT(...)                                                              \
    int __VA_ARGS__;                                                           \
    CIN(__VA_ARGS__)
#define LCIN(...)                                                              \
    ll __VA_ARGS__;                                                            \
    CIN(__VA_ARGS__)
#define SCIN(...)                                                              \
    string __VA_ARGS__;                                                        \
    CIN(__VA_ARGS__)
#define Yes(a) cout << (a ? "Yes" : "No") << "\n"
#define YES(a) cout << (a ? "YES" : "NO") << "\n"

typedef long long ll;
typedef unsigned long long ul;
typedef vector<int> V;
typedef vector<ll> VL;
typedef pair<int, int> Pair;
typedef pair<ll, ll> PL;
typedef priority_queue<int> PQ;
typedef priority_queue<int, V, greater<int>> PQG;

const int INF = 1e9;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const ll LINF = 1e18;

ll N, K;
VL a, sum, opt;

int main() {
    cin >> N >> K;
    a.resize(N);
    sum.resize(N + 1);
    opt.resize(N + 1);
    VECCIN(a);
    REP(i, N) {
        sum[i + 1] += sum[i] + a[i];
        opt[i + 1] += opt[i] + (a[i] > 0 ? a[i] : 0);
    }
    ll ans = 0;
    REP(i, N - K + 1) {
        ll tmp = opt[i] + max(0LL, sum[i + K] - sum[i]) + (opt[N] - opt[i + K]);
        ans = max(tmp, ans);
    }
    cout << ans << "\n";
}
