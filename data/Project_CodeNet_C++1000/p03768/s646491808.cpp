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

ll N, M, Q;
VL v, d, c;
vector<VL> con, color;

void paint(ll v, ll d, ll c) {
    if(color[v][d]) return;
    color[v][d] = c;
    if(d == 0) return;
    paint(v, d - 1, c);
    FOREACH(x, con[v]) paint(x, d - 1, c);
}

int main() {
    cin >> N >> M;
    con.resize(N);
    REP(i, M) {
        LCIN(a, b);
        con[--a].emplace_back(--b);
        con[b].emplace_back(a);
    }
    cin >> Q;
    REP(i, Q) {
        v.emplace_back(IN() - 1);
        d.emplace_back(IN());
        c.emplace_back(IN());
    }
    color.assign(N, VL(11, 0));
    REPR(i, Q - 1) paint(v[i], d[i], c[i]);
    REP(i, N) cout << color[i][0] << "\n";
}
