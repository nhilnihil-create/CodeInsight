#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main(){
    int n,ma,mb;
    cin >> n >> ma >> mb;
    int a[n],b[n],c[n];
    rep(i,n){
        cin >> a[i] >> b[i] >> c[i];
    }
    int dp[n+1][400][400];
    rep(i,n+1) rep(j,400) rep(k,400) dp[i][j][k] = 400000;
    dp[0][0][0] = 0;
    rep(i,n){
        rep(j,400) rep(k,400) {
            // 選ばない場合
            dp[i+1][j][k] = MIN(dp[i+1][j][k],dp[i][j][k]);
            // 選ぶ場合
            if(j-a[i]>=0 && k-b[i]>=0){
                dp[i+1][j][k] = MIN(dp[i+1][j][k],dp[i][j-a[i]][k-b[i]]+c[i]);
            }
        }
    }
    int out = 40000;
    rep(j,400) rep(k,400) {
        if(j==0&&j==0) continue;
        if(ma*k == mb*j) out = MIN(dp[n][j][k],out);
    }
    if(out==40000) cout << -1 << endl;
    else cout << out << endl;

    return 0;
}