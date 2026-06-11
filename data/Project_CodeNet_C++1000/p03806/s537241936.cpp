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
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
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

ll dp[50][410][410];  // dp[i+1][j][k] : i番目(iは0-index)までの薬品でAをjグラム,Bをkグラムとするときに必要な予算の最小値

int main() {
    ll n, mA, mB;
    cin >> n >> mA >> mB;
 
    vl a(n), b(n), c(n);
    ll sumA = 0, sumB = 0; 
    rep(i, n) {
        cin >> a[i] >> b[i] >> c[i];
        sumA += a[i];
        sumB += b[i];
    }
 
    rep(i, n+1) {
        rep(j, sumA+1) {
            rep(k, sumB+1) {
                dp[i][j][k] = INF;
            }
        }
    }
 
    dp[0][0][0] = 0;
    rep(i, n) {
        rep(j, sumA+1) {
            rep(k, sumB+1) {
                if(j >= a[i] && k >= b[i]) {
                    dp[i+1][j][k] = min(dp[i][j][k], dp[i][j - a[i]][k - b[i]] + c[i]);
                }
                else {
                    dp[i+1][j][k] = dp[i][j][k];
                }
            }
        }
    }
    
    ll ans = INF;
    exrep(j, 1, sumA) {
        exrep(k, 1, sumB) {
            if(mB*j == mA*k) {
                chmin(ans, dp[n][j][k]);
            }
        }
    }
 
    if(ans == INF) {
        out(-1);
    }
    else {
        out(ans);
    }
 
    re0;
}