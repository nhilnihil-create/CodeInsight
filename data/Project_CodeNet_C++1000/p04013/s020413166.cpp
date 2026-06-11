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

ll dp[60][60][2600];  // dp[i+1][j][k] : i番目(iは0-index)まででj枚選んで合計kになる選び方の数

int main() {
    ll n, a;
    cin >> n >> a;
 
    vl x(n);
    ll sum = 0;
    rep(i, n) {
        cin >> x[i];
        sum += x[i];
    }
 
    dp[0][0][0] = 1;
    rep(i, n) {
        rep(j, n+1) {
            rep(k, sum+1) {
                dp[i+1][j][k] += dp[i][j][k];
                if(j >= 1 && k >= x[i]) {
                    dp[i+1][j][k] += dp[i][j-1][k - x[i]];
                }
            }
        }
    }
    
    ll ans = 0;
    exrep(j, 1, n) {
        if(j*a <= sum) {
            ans += dp[n][j][j*a];
        }
    }
 
    out(ans);
    re0;
}