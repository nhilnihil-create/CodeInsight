#include <bits/stdc++.h>
using namespace std;
const long long INF = 100000000000000;
const int MOD = 1000000007;
#define rep(i, a) REP(i, 0, a)
#define REP(i, a, b) for(int i = a; i < b;i++)
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<P> vp;

int dp[41][401][401];

int main() {
    int n, ma, mb;
    cin >> n >> ma >> mb;
    vi a(n), b(n), c(n);
    rep(i, n) cin >> a[i] >> b[i] >> c[i];
    rep(i, n + 1) rep(j, 401) rep(k, 401){
        dp[i][j][k] = 1000000000;
    }
    rep(i, n + 1){
        dp[i][0][0] = 0;
    }
    rep(i, n) {
        rep(j, 401) {
            rep(k, 401){
                if(j >= a[i] && k >= b[i]){
                    dp[i + 1][j][k] = min(dp[i][j - a[i]][k - b[i]] + c[i], dp[i][j][k]);
                }else{
                    dp[i + 1][j][k] = dp[i][j][k];
                }
            }
        }
    }
    int p = 1, ans = 1000000000;
    while(true){
        if(dp[n][ma*p][mb*p]){
            ans = min(ans, dp[n][ma*p][mb*p]);
        }
        p += 1;
        if(p * max(ma, mb) > 400){
            break;
        }
    }
    if(ans == 1000000000){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
}