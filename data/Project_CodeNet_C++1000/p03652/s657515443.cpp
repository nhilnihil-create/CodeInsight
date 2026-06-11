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

ll N, M;
map<ll, ll> now;
vector<VL> A;
VL Aidx;
vector<bool> stop;

int main() {
    cin >> N >> M;
    A.resize(N);
    Aidx.resize(N);
    stop.resize(M);
    REP(i, N) REP(j, M) { A[i].push_back(IN()); }
    ll ans = N;
    REP(loop, M - 1) {
        ll most = 0, tmp = 0;
        REP(i, N) { now[A[i][Aidx[i]]]++; }
        REP(i, N) {
            if(now[A[i][Aidx[i]]] > tmp) {
                most = A[i][Aidx[i]];
                tmp = now[A[i][Aidx[i]]];
            }
        }
        ans = min(tmp, ans);
        stop[most] = true;
        REP(i, N) {
            while(stop[A[i][Aidx[i]]] && Aidx[i] < M - 1) {
                Aidx[i]++;
            }
        }
        now.clear();
    }
    cout << ans << "\n";
}
