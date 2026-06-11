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

    const ll MOD = (ll)1e9 + 7;
    int N; cin >> N;
    string S1; cin >> S1;
    string S2; cin >> S2;

    ll ans = 1;

    int i = 0;
    bool pre_v = false;
    if (S1[0] == S1[1]) {
        ans *= 6;
        i += 2;
        pre_v = false;
    } else {
        ans *= 3;
        i++;
        pre_v = true;
    }
    while(i<N) {
        if (pre_v) {
            if (i+1 < N && S1[i] == S1[i + 1]) {
                ans *= 2;
                ans %= MOD;
                i += 2;
                pre_v = false;
            } else {
                ans *= 2;
                ans %= MOD;
                i++;
                pre_v = true;
            }
        } else {
            if (i+1 < N && S1[i] == S1[i + 1]) {
                ans *= 3;
                ans %= MOD;
                i += 2;
                pre_v = false;
            } else {
                //ans *= 1;
                //ans %= MOD;
                i++;
                pre_v = true;
            }
        }
    }

    cout << ans << endl;

    return 0;
}