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
#define LINF (LLONG_MAX/2)
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


int main_D() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, W; cin >> N >> W;
    vl w(N+1,0);
    vl v(N+1,0);
    FOR(i,1,N+1) cin >> w[i] >> v[i];

    ll WMIN = LINF;
    FOR(i,1,N+1) WMIN = min(WMIN, w[i]);    

    vi r(N+1,0);
    FOR(i, 1, N + 1) r[i] = w[i] - WMIN;

    const ll RMAX = 400;
    vector<vvl> dp(N+MGN, vvl(N+MGN, vl(RMAX+MGN, 0)));
    dp[0][0][0] = 0;

    FOR(i,1,N+1) {
        FOR(j,1,i+2) {
            for (ll k = 0; k <= RMAX; k++) {  
                ll next = (k >= r[i]) 
                    ? dp[i - 1][j - 1][k - r[i]] + v[i] : 0;
                dp[i][j][k] = max(next, dp[i - 1][j][k]);
            }
        }
    }

    ll ans = 0;
    for (ll j = 1; j <= N; j++) {
        if (WMIN * j <= W) {
            ans = max(ans, dp[N][j][min(RMAX, W - WMIN*j)]);
        }
    }

    cout << ans << endl;

    return 0;
}