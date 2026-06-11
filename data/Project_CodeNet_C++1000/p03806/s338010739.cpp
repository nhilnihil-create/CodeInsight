#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N, MA, MB;
    cin >> N >> MA >> MB;
    int inf = 9999999;
    vector<vector<int>> dp(401, vector<int>(401, inf));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = 400; j >= a; j--) {
            for (int k = 400; k >= b; k--) {
                dp[j][k] = min(dp[j][k], dp[j-a][k-b]+c);
            }
        }
    }
    int ans = inf;
    for (int i = 1; max(i*MA, i*MB) <= 400; i++) {
        ans = min(ans, dp[i*MA][i*MB]);
    }
    if (ans < inf) cout << ans << endl;
    else cout << -1 << endl;
    
    return 0;
}