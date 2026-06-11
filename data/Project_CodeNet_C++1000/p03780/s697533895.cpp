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
const ll INF = 1e9;
const ll MAX_N = 100010;

int main() {
    ll n, k;
    cin >> n >> k;

    vl a(n);
    ll sum = 0;
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    sort(all(a));

    if(sum < k) {
        out(n);
        re0;
    }

    ll left = -1;
    ll right = n;
    while(right - left > 1) {

        ll x = (left + right)/2;

        // a[x]が必要かどうか考える
        if(a[x] >= k) {
            right = x;
            continue;
        }

        vvl dp(n+1, vl(k));  // dp[i+1][j] : a[i]までの要素の総和がjとなるか？
        dp[0][0] = 1;
        rep(i, n) {
            if(i == x) {
                rep(j, k) {
                    if(dp[i][j]) {
                        dp[i+1][j] = 1;
                    }
                }
            }
            else {
                rep(j, k) {
                    if(dp[i][j]) {
                        dp[i+1][j] = 1;
                        if(j + a[i] < k) {
                            dp[i+1][j + a[i]] = 1;
                        }
                    }
                }
            }
        }

        ll noneed = 1;  // a[x]が不必要なら1
        exrep(j, k - a[x], k-1) {
            if(dp[n][j]) {
                noneed = 0;
            }
        }

        if(noneed) {
            left = x;
        }
        else {
            right = x;
        }
    }

    out(right);
    re0;
}