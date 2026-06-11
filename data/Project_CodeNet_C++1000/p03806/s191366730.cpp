#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int n,ma,mb;
    cin >> n >> ma >> mb;
    int a[n],b[n],c[n];
    REP(i,n){
        cin >> a[i] >> b[i] >> c[i];
    }
    vector<vector<vector<int>>> dp(vector<vector<vector<int>>>(n + 1, vector<vector<int>>(400 + 1, vector<int>(400 + 1, INF))));
    dp[0][0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= 400; j++){
            for(int k = 0; k <= 400; k++){
                dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
                if(j - a[i] < 0 || k - b[i] < 0) continue;
                dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j - a[i]][k - b[i]] + c[i]);
            }
        }
    }
    int ans = INF;
    for(int i = 1; ma * i <= 400 && mb * i <= 400; i++){
        ans = min(ans, dp[n][ma * i][mb * i]);
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}