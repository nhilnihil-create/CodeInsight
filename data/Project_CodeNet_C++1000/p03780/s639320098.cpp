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
const ll MAX_N = 100010;
 
int main() {
    ll n, k;
    cin >> n >> k;

    vl a(n);
    rep(i, n) {
        cin >> a[i];
    }
    sort(all(a));

    // まずa[i]が必要かどうかは
    // 「要素の総和がk-a[i]以上k未満のa[i]を含まない部分集合が存在するならa[i]は必要。そうでなければ不必要」
    // と判定できる。

    // 次に解の単調性 「a[i] < a[j]のとき、a[j]が不必要 ⇒ a[i]も不必要」 を示す。
    // 仮定より要素の総和がk-a[j]以上k未満のa[j]を含まない部分集合は存在しない。
    // つまりa[j]を含まない部分集合の要素の総和はk-a[j]未満またはk以上。
    // k-a[j] < k-a[i] より要素の総和がk-a[i]以上k未満のa[i]もa[j]も含まない部分集合は存在しない。
    // a[j]を含む部分集合の要素の総和はk未満またはk+a[j]以上なので、
    // a[j]を含むがa[i]は含まない部分集合の要素の総和はk-a[i]未満またはk+a[j]-a[i]以上。
    // k < k + (a[j] - a[i]) より要素の総和がk-a[i]以上k未満のa[j]を含むがa[i]は含まない部分集合は存在しない。
    // 以上よりa[j]を含むかどうかによらずa[i]は不必要。

    // 判定問題「a[x]は不必要か？」を二分探索で解く
    ll left = -1;
    ll right = n;
    while(right - left > 1) {
        ll x = (left + right)/2;
        vector<vector<bool>> dp(n+1, vector<bool>(k+1, false));  // dp[i+1][j] : a[i]までで総和をjにできるならtrue
        dp[0][0] = true;
        rep(i, n) {
            exrep(j, 0, k) {
                if(dp[i][j]) {
                    dp[i+1][j] = true;
                }
                if(i == x) {
                    continue;
                }
                if(j >= a[i] && dp[i][j - a[i]]) {
                    dp[i+1][j] = true;
                }
            }
        }
        bool noneed = true;
        exrep(j, max(0LL, k-a[x]), k-1) {
            if(dp[n][j]) {
                noneed = false;
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