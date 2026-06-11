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
const int MGN = 10;
const int ARY_SZ_MAX = 10000000;
using namespace std;
using ll = long long; using ull = unsigned long long;
using vi = vector<int>; using vvi = vector<vi>; using vvvi = vector<vvi>;
using vb = vector<bool>; using vvb = vector<vb>; using vvvb = vector<vvb>;
using vl = vector<ll>; using vvl = vector<vl>;
using vd = vector<double>; using vs = vector<string>;
using pii = pair<int, int>; using pll = pair<ll, ll>;
using psi = pair<string, int>;
// functions
template<typename T>
inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
#endif 


int main_D() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, W; cin >> N >> W;
    vl w(N + 1, 0); vl v(N + 1, 0);
    ll wMin = LINF;
    FOR(i, 1, N + 1) {
        cin >> w[i] >> v[i];
        wMin = min(wMin, w[i]);
    }

    vi dw(N + 1, 0);
    FOR(i, 1, N + 1) dw[i] = w[i] - wMin;
    ll dwMax = 3;

    auto dp = vector<vector<map<ll, ll>>>(N + 2, vector<map<ll, ll>>(N + 2, map<ll, ll>()));

    FOR(i, 1, N + 1) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= dwMax * i; k++) {
                if (k + dw[i] <= dwMax * i) {
                    chmax(dp[i + 1][j + 1][k + dw[i]], dp[i][j][k] + v[i]);
                }

                chmax(dp[i + 1][j][k], dp[i][j][k]);
            }
        }
    }

    ll ans = 0;
    for (int j = 0; j <= N; j++) {
        for (int k = 0; k <= dwMax * N; k++) {
            ll w = wMin * j + k;
            if (w <= W) {
                ans = max(ans, dp[N + 1][j][k]);
            }
        }
    }
    cout << ans << endl;

    return 0;
}