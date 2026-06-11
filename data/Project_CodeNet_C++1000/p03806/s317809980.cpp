#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 1e9;
int dp[41][505][505];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, ma, mb;
    cin >> n >> ma >> mb;
    vector<int> a(n), b(n), c(n);
    rep(i,n) cin >> a[i] >> b[i] >> c[i];
    rep(i,n+1)rep(j,501)rep(k,501) dp[i][j][k] = INF;
    dp[0][0][0] = 0;
    int ans = INF;
    rep(i,n)rep(j,401)rep(k,401){
        chmin(dp[i+1][j][k], dp[i][j][k]);
        chmin(dp[i+1][j+a[i]][k+b[i]], dp[i][j][k]+c[i]);
    }
    for(int j = 1; j <= 400; ++j){
        for(int k = 1; k <= 400; ++k){
            if(j*mb == k*ma && dp[n][j][k] != 0){
                chmin(ans, dp[n][j][k]);
            }
        }
    }
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}
