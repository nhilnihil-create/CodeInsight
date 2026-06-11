#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
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

ll dp[50][410][410];  // dp[i][j][k] : 薬品iまででタイプAの物質がjグラム、タイプBの物質がkグラムのときの必要な予算の最小値

int main() {
    ll n, Ma, Mb;
    cin >> n >> Ma >> Mb;

    vl a(n), b(n), c(n);
    rep(i, n) {
        cin >> a[i] >> b[i] >> c[i];
    }

    rep(i, 50) {
        rep(j, 410) {
            rep(k, 410) {
                dp[i][j][k] = INF;
            }
        }
    }

    dp[0][0][0] = 0;
    rep(i, n) {
        exrep(j, 0, 400) {
            exrep(k, 0, 400) {
                chmin(dp[i+1][j][k], dp[i][j][k]);
                if(j + a[i] <= 400 && k + b[i] <= 400) {
                    chmin(dp[i+1][j + a[i]][k + b[i]], dp[i][j][k] + c[i]);
                }
            }
        }
    }

    ll ans = INF;
    exrep(j, 1, 400) {
        exrep(k, 1, 400) {
            if(j*Mb == k*Ma) {
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