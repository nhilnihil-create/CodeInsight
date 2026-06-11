#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define rep(i,n) for(ll i=0;i<(ll)n;i++)

const ll INF = 1e9;

int main(){
    int N,MA,MB; cin >> N >> MA >> MB;
    int ma=0,mb=0;
    vector<ll> A(N),B(N),C(N);
    rep(i,N){
        int a,b,c; cin >> a >> b >> c;
        A[i] = a; B[i] = b; C[i] = c;
        ma = max(ma, a); mb = max(mb, b);
    }
    ll dp[N+1][ma*(N+1)][mb*(N+1)];
    rep(i,N+1)rep(j,ma*(N+1))rep(k,mb*(N+1)){
        if(j==0 && k==0) dp[i][j][k] = 0;
        else dp[i][j][k] = INF;
    }
    
    for(int i=1;i<=N;i++){
        for(int j=0;j<=ma*N;j++){
            for(int k=0;k<=mb*N;k++){
                if(j-A[i-1] >= 0 && k-B[i-1] >= 0){
                    dp[i][j][k] = min(dp[i][j][k], dp[i-1][j-A[i-1]][k-B[i-1]] + C[i-1]);
                }
                dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]);
            }
        }
    }
    ll res = INF;
    for(int i=1;i<=N;i++){
        res = min(res, dp[N][MA*i][MB*i]);
    }
    if(res==INF){
        cout << -1 << endl;
        return 0;
    }
    cout << res << endl;
}