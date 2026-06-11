#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
typedef vector<vector<P>> vvP;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;

ll dp[110][110][310];  // dp[i+1][j][k] : i番目の品物まででj個選んで重さの総和k以下のときの価値の総和の最大値

int main() {
    ll n, W;
    cin >> n >> W;

    vl weight(n), value(n);
    rep(i, n) {
        cin >> weight[i] >> value[i];
    }

    ll w0 = weight[0];
    rep(i, n) {
        weight[i] -= w0;
    }
    
    rep(i, n) {
        rep(j, n) {
            exrep(k, 0, 3*n) {
                chmax(dp[i+1][j+1][k], dp[i][j+1][k]);
                if(k >= weight[i]) {
                    chmax(dp[i+1][j+1][k], dp[i][j][k - weight[i]] + value[i]);
                }
            }
        }
    }
    
    ll ans = 0;
    exrep(j, 1, n) {
        exrep(k, 0, 3*n) {
            if(w0*j + k <= W) {
                chmax(ans, dp[n][j][k]);
            }
        }
    }
    
    out(ans);
    re0;
}