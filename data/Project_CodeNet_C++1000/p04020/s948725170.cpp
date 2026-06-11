#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000;
LL dp[maxn][2];
int main(){
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    dp[0][1] = -1e18;
    for(int i = 1, A; i <= N; i += 1){
        cin >> A;
        dp[i][0] = max(dp[i - 1][0] + A / 2, dp[i - 1][1] + (A + 1) / 2);
        if(A) dp[i][1] = max(dp[i - 1][0] + (A - 1) / 2, dp[i - 1][1] + A / 2);
        else dp[i][1] = -1e18;
    }
    cout << dp[N][0];
    return 0;
}