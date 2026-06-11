#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=1000000007;

int main(){
    ll N;
    cin >> N;
    ll P;
    cin >> P;
    vector<ll> A(N,0);
    for(ll i=0;i<N;i++){
        cin>>A[i]
    ;}

    //dp[i][j]はi袋目までであまりjの場合の数
    vector<vector<ll>> dp(N, vector<ll>(2, 0));
    if(A[0]%2==0)dp[0][0]=2;
    else {dp[0][1]=1;dp[0][0]=1;}
    for(ll i=1;i<N;i++){
        if(A[i]%2==0){
            dp[i][0]=dp[i-1][0]*2;
            dp[i][1]=dp[i-1][1]*2;
        }
        else{
            dp[i][0]=dp[i-1][1]+dp[i-1][0];
            dp[i][1]=dp[i-1][0]+dp[i-1][1];

        }
    ;}
    cout<<dp[N-1][P]<<endl;

    return 0;
}
