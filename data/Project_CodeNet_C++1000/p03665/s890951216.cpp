#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    ll N,P;
    cin>>N>>P;
    vector<ll> A(N);
    vector<vector<ll>> dp(50+10,vector<ll>(2,0));
    for(ll i=0; i<N; i++) cin>>A[i];

    dp[0][0] = 1;

    for(ll i=0; i<N; i++){
        if(A[i]%2 == 0){
            dp[i+1][0] = dp[i][0]*2;
            dp[i+1][1] = dp[i][1]*2;   
        }

        else if(A[i]%2 != 0){
            dp[i+1][0] = dp[i][0] + dp[i][1]; 
            dp[i+1][1] = dp[i][0] + dp[i][1];
        }
    }

    cout<<dp[N][P]<<endl;

    return 0;

}