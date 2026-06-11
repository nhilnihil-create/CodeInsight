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


// 処理内容
int main() {
    
    ll n, m; cin >> n >> m;
    vector<vector<ll>> nbr(n);
    REP(i, m) {
        ll a, b; cin >> a >> b;
        --a; --b; // 0-indexed
        nbr[a].push_back(b);
        nbr[b].push_back(a);
    }

    deque<ll> ans = {0, nbr[0][0]};
    vector<bool> visited(n, false);
    visited[ans[0]] = visited[ans[1]] = true;
    for (;;) {
        ll v = ans.back();
        bool yet = false;
        for (ll nb : nbr[v]) {
            if (!visited[nb]) {
                ans.push_back(nb);
                visited[nb] = true;
                yet = true;
                break;
            }
        }
        if (!yet) break;
    }
    for (;;) {
        ll v = ans.front();
        bool yet = false;
        for (ll nb : nbr[v]) {
            if (!visited[nb]) {
                ans.push_front(nb);
                visited[nb] = true;
                yet = true;
                break;
            }
        }
        if (!yet) break;
    }

    cout << ans.size() << endl;
    for (ll &v : ans)
        cout << -~v << " \n"[&v == &ans.back()];
    
}