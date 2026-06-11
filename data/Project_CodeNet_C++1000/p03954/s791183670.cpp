#pragma GCC optimize ("O3")
#pragma GCC target ("tune=native")
#pragma GCC target ("avx")

#include <bits/stdc++.h>

// 汎用マクロ
#define ALL_OF(x) (x).begin(), (x).end()
#define REP(i,n) for (long long i=0, i##_len=(n); i<i##_len; i++)
#define RANGE(i,is,ie) for (long long i=(is), i##_end=(ie); i<=i##_end; i++)
#define DSRNG(i,is,ie) for (long long i=(is), i##_end=(ie); i>=i##_end; i--)
#define UNIQUE(v) { sort((v).begin(), (v).end()); (v).erase(unique((v).begin(), (v).end()), (v).end()); }
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0; }
template<class T> bool chmin(T &a, const T &b) {if (a > b) {a = b; return 1;} return 0; }
#define INF 0x7FFFFFFF
#define LINF 0x7FFFFFFFFFFFFFFFLL
#define Yes(q) (q ? "Yes" : "No")
#define YES(q) (q ? "YES" : "NO")
#define DUMP(q) cerr << "[DEBUG] " #q ": " << (q) << " at " __FILE__ ":" << __LINE__ << endl
#define DUMPALL(q) { cerr << "[DEBUG] " #q ": ["; REP(dumpall_i, (q).size()) { cerr << q[dumpall_i] << (dumpall_i == (q).size() - 1 ? "" : ", "); } cerr << "] at " __FILE__ ":" << __LINE__ << endl; }

// gcc拡張マクロ
#define gcd __gcd
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll

// エイリアス
using  ll = long long;
using ull = unsigned long long;
using  ld = long double;
using namespace std;

// モジュール
bool is_ge(ll k, const vector<ll> &a) {

    vector<bool> g(a.size());
    REP(i, a.size()) g[i] = a[i] >= k ? true : false;

    ll m = a.size();
    ll i = m / 2;
    if (g[i] != g[i-1] && g[i] != g[i+1]) {
        bool is_corner = true;
        REP(j, m-1) if (g[j] == g[j+1]) {
            is_corner = false;
            break;
        }
        if (is_corner) {
            return g[0];
        } else {
            ll cl = i, cr = i;
            while (cl >  0  && g[cl] != g[cl-1] && g[cl] != g[cl+1]) cl--;
            while (cr < m-1 && g[cr] != g[cr-1] && g[cr] != g[cr+1]) cr++;
            if (i - cl < cr - i) {
                return g[cl];
            } else {
                return g[cr];
            }
        }
    } else {
        return g[i];
    }

}

// 処理内容
int main() {
    
    ll n; cin >> n;
    vector<ll> a(n*2-1);
    REP(i, n*2-1) cin >> a[i];

    ll ok = 0;
    ll ng = n*2;
    while (ng - ok > 1) {
        ll mid = (ok + ng) / 2;
        if (is_ge(mid, a)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;
    
}