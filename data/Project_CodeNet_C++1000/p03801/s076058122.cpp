// May this submission get accepted!

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
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return true;} return false; }
template<class T> bool chmin(T &a, const T &b) {if (a > b) {a = b; return true;} return false; }
#define INF 0x7FFFFFFF
#define LINF 0x7FFFFFFFFFFFFFFFLL
#define Yes(q) ((q) ? "Yes" : "No")
#define YES(q) ((q) ? "YES" : "NO")
#define Possible(q) ((q) ? "Possible" : "Impossible")
#define POSSIBLE(q) ((q) ? "POSSIBLE" : "IMPOSSIBLE")
#define DUMP(q) cerr << "[DEBUG] " #q ": " << (q) << " at " __FILE__ ":" << __LINE__ << endl
#define DUMPALL(q) { cerr << "[DEBUG] " #q ": ["; REP(i, (q).size()) { cerr << (q)[i] << (i == i_len-1 ? "" : ", "); } cerr << "] at " __FILE__ ":" << __LINE__ << endl; }
template<class T> T gcd(const T &a, const T &b) { return a < b ? gcd(b, a) : b ? gcd(b, a % b) : a; }
template<class T> T lcm(const T &a, const T &b) { return a / gcd(a, b) * b; }

// gcc拡張マクロ
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll

// エイリアス
#define DANCE_ long
#define ROBOT_ unsigned
#define HUMAN_ signed
#define CHOKUDAI_ const
using  ll = DANCE_ HUMAN_ DANCE_;
using ull = DANCE_ ROBOT_ DANCE_;
using cll = DANCE_ DANCE_ CHOKUDAI_;
using  ld = long double;
using namespace std;

// モジュール


// 処理内容
int main() {
    
    ll n; cin >> n;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];
    
    vector<ll> acmx(n);
    vector<ll> nonzero; nonzero.reserve(n);
    vector<ll> scmx(n);
    REP(i, n) {
        acmx[i] = !i ? a[i] : max(acmx[i-1], a[i]);
        if (!i || acmx[i-1] != acmx[i]) {
            nonzero.push_back(i);
        }
    }
    REP(i, n) {
        ll j = lower_bound(ALL_OF(acmx), acmx[i]) - acmx.begin();
        scmx[i] = !j ? 0 : acmx[j-1];
    }
    
    // DUMPALL(acmx);
    // DUMPALL(scmx);

    vector<ll> asr = a;
    sort(ALL_OF(asr), greater<ll>());
    vector<ll> asrimos(n+1, 0);
    REP(i, n) asrimos[i+1] = asrimos[i] + asr[i];

    // DUMPALL(asr);
    // DUMPALL(asrimos);

    vector<ll> ans(n, 0);
    ll prev = 0;
    DSRNG(_i, nonzero.size()-1, 1) {
        ll i = nonzero[_i];
        ll je = lower_bound(ALL_OF(asr), scmx[i], greater<ll>()) - asr.begin();
        ll term = asrimos[je] - je * scmx[i];
        ans[i] = term - prev;
        prev = term;
    }
    
    ans[0] = accumulate(ALL_OF(a), 0LL) - prev;

    REP(i, n) cout << ans[i] << '\n';
    
}