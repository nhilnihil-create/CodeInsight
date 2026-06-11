#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N,Ma,Mb;
    cin >> N >> Ma >> Mb;
    vector<int> a(N), b(N), c(N);
    rep(i,N) cin >> a[i] >> b[i] >> c[i];
    vector<vector<int> > dp(420, vector<int>(420));
    rep(i,420){
        rep(j,420){
            dp[i][j] = 10000000;
        }
    }
    dp[0][0] = 0;
    rep(i,N){
        for (int j = 400; j >= 0; j--){
            for (int k = 400; k >= 0; k--){
                dp[j + a[i]][k + b[i]] = min(dp[j + a[i]][k + b[i]], dp[j][k] + c[i]);
            }
        }
    }
    int count = 1;
    int ans = 10000000;
    while(true){
        if (count * Ma >= 420 || count * Mb >= 420){
            break;
        }
        else{
            ans = min(ans, dp[count * Ma][count * Mb]);
            count++;
        }
    }
    if (ans == 10000000) cout << -1 << endl;
    else cout << ans << endl;
}
