#ifdef _DEBUG
#include "MyLib.h"
#else
#define main_D main
#include "bits/stdc++.h" 
#include <regex>
#define _USE_MATH_DEFINES
#include <math.h>
#define FOR(i,s,e) for (int i = int(s); i < int(e); ++i)
#define REP(i,e) FOR(i,0,e)
#define INF (INT_MAX/2)
#define EPS (1.0e-8)
#define LINF (LONG_MAX/2)
const int MGN = 8;
const int ARY_SZ_MAX = 10000000;
using namespace std;
using ll = long long; using ull = unsigned long long;
using vi = vector<int>; using vvi = vector<vi>; using vvvi = vector<vvi>;
using vb = vector<bool>; using vvb = vector<vb>; using vvvb = vector<vvb>;
using vl = vector<ll>; using vvl = vector<vl>;
using vd = vector<double>; using vs = vector<string>;
using pii = pair<int, int>; using pll = pair<ll, ll>;
// functions

#endif
int N, W;
vi w, v;
map<pll,ll> dp;
ll dfs(int n, ll wt) {
    if (n >= N) return 0;
    
    if (dp.count(pll(n,wt)) > 0) return dp[pll(n,wt)];

    ll ret = 0;
    if (wt+w[n] <= W) {
        ll yes = dfs(n + 1, wt + w[n]) + v[n];
        ll no = dfs(n + 1, wt);
        ret = max(yes, no);
    } else {
        ret = dfs(n + 1, wt);
    }
    
    dp[pll(n,wt)] = ret;

    return ret;
}

int main_D() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> W;
    w = vi(N);
    v = vi(N);
    REP(i, N) cin >> w[i] >> v[i];

    ll ans = dfs(0, 0);

    cout << ans << endl;
    dp.clear();

    return 0;
}