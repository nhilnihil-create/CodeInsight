#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

ll dp[55][3000][55];


int main(){
    int N, A;
    cin >> N >> A;
    vector<int> X(N);
    for(int i=0; i<N; i++) cin>>X[i];

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;

    for(int i=0; i<N; i++) {
        for(int s=0; s<=A*N; s++) {
            for(int k=0; k<N; k++) {
                if(dp[i][s][k] == 0) continue;
                dp[i+1][s][k] += dp[i][s][k];
                dp[i+1][s+X[i]][k+1] += dp[i][s][k];
            }
        }
    }

    ll ans = 0;
    for(int k=1; k<=N; k++) ans += dp[N][A*k][k];
    cout << ans;
}