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
#include <random>

// 処理内容
int main() {
    
    ll n; cin >> n;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];

    // ll n = 10;
    // vector<ll> a(n);

    // mt19937_64 mt(114514);
    // uniform_int_distribution<ll> rg(0, n-1);
    // REP(t, 10) {
    //     ll i = t;
    //     REP(j, n) {
    //         ll k = (i + j) % n;
    //         a[k] += j;
    //     }
    // }

    ll sum = accumulate(ALL_OF(a), 0LL);
    if (sum % (n * (n + 1) / 2) != 0) {
        cout << "NO" << endl;
        return 0;
    }

    ll opnum = sum / (n * (n + 1) / 2);

    vector<ll> d(n);
    REP(i, n) d[i] = a[(i+1)%n] - a[i] - opnum;

    bool okay = true;
    ll opcur = 0;
    REP(i, n) {
        if (d[i] % n == 0) {
            ll opterm = -d[i] / n;
            if (opterm < 0) {
                okay = false;
                break;
            } else {
                opcur += opterm;
            }
        } else {
            okay = false;
            break;
        }
    }
    cout << YES(okay) << endl;

}