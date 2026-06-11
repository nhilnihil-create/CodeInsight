#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const ll MOD=1e9+7;

ll powm(ll x,ll k){
    ll res=1;
    while(k){
        if(k&1) res=(res*x)%MOD;
        x=(x*x)%MOD;
        k>>=1;
    }
    return res;
}

ll modInverse(ll x){
    return powm(x,MOD-2);
}
int main(){
    int N;
    cin>>N;
    string s;
    cin>>s;
    int M=s.size();

    vector<vector<ll>> dp(2,vector<ll>(N+1,0));
    dp[0][0]=1;
    for(int i=0;i<N;i++){
        fill(dp[(i+1)&1].begin(),dp[(i+1)&1].end(),0LL);
        for(int j=0;j<N;j++){
            (dp[(i+1)&1][max(j-1,0)]+=dp[i&1][j])%=MOD;
            (dp[(i+1)&1][j+1]+=dp[i&1][j]*2)%=MOD;
        }
    }
    cout<<(dp[N&1][M]*modInverse(powm(2LL,M)))%MOD<<endl;
    return 0;
}