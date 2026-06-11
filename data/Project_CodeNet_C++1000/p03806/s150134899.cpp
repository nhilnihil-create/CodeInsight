#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF =1001001;

int main() {
    ll N,Ma,Mb;
    cin >> N >> Ma >> Mb;
    vector<int> A(N),B(N),C(N);
    for(int i=0;i<N;i++){
        cin >> A[i] >> B[i] >>C[i];
    } 
    int dp[N+1][401][401];
    memset(dp,INF,sizeof(dp));
    dp[0][0][0] = 0;
    for(int i=0;i<N;i++)for(int j=0;j<=400;j++)for(int k=0;k<=400;k++){
        dp[i+1][j][k] = min(dp[i+1][j][k],dp[i][j][k]);
        if(A[i]<=j && B[i]<=k){
            dp[i+1][j][k] = min(dp[i+1][j][k],dp[i][j-A[i]][k-B[i]]+C[i]);
        }
        // cerr << dp[i+1][3][3]<<endl;
    }
    cerr <<"A"<<endl;
    int ans = INF;
    for(int i=1;i<=400;i++){
        if(Ma*i>400|| Mb*i >400){
            break;
        }
        ans = min(ans,dp[N][Ma*i][Mb*i]);
    }
    if(ans == INF){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;

    return 0;
}