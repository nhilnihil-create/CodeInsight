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

ll dp[55][55][2505];  // dp[i+1][j][k] : x[i]まででj枚使って合計をkにする方法の総数

int main() {
    ll n, a;
    cin >> n >> a;

    vl x(n);
    ll u = 0;  // xの中の最大の数
    rep(i, n) {
        cin >> x[i];
        chmax(u, x[i]);
    }

    dp[0][0][0] = 1;
    rep(i, n) {
        exrep(j, 0, n) {
            exrep(k, 0, u*n) {
                ll y = 0;
                if(j >= 1 && k >= x[i]) {
                    y = dp[i][j - 1][k - x[i]];
                }
                dp[i+1][j][k] = dp[i][j][k] + y;
            }
        }
    }

    ll ans = 0;
    exrep(j, 1, n) {
        ans += dp[n][j][a*j];
    }

    out(ans);
    re0;
}