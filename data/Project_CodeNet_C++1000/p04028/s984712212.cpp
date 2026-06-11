#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const ll MOD=1e9+7;

ll powm(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1){
            res*=x;
            res%=MOD;
        }
        x*=x;
        x%=MOD;
        y>>=1;
    }
    return res;
}
ll mod_inv(ll x){
    return powm(x,MOD-2);
}
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int m=s.size();
    vector<vector<ll>> dp(2,vector<ll>(n+m+1,0));
    vector<ll> rig(n+1);
    dp[0][n]=1;
    rig[0]=dp[0][n+m];
    for(int i=0;i<n;i++){
        fill(dp[(i+1)&1].begin(),dp[(i+1)&1].end(),0LL);
        for(int j=0;j<n+m;j++){
            dp[(i+1)&1][j+1]+=dp[i&1][j]*2;
            dp[(i+1)&1][j+1]%=MOD;
            if(j-1>=0){
                dp[(i+1)&1][j-1]+=dp[i&1][j];
                dp[(i+1)&1][j-1]%=MOD;
            }
        }
        rig[i+1]=dp[(i+1)&1][n+m];
    }
    vector<ll> lef(n+1);
    vector<vector<ll>> dp2(2,vector<ll>(n+1,0));
    dp2[0][n]=1;
    lef[0]=1;
    for(int i=0;i<n;i++){
        fill(dp2[(i+1)&1].begin(),dp2[(i+1)&1].end(),0LL);
        for(int j=0;j<=n;j++){
            if(j!=n){
                dp2[(i+1)&1][j+1]+=dp2[i&1][j]*2;
                dp2[(i+1)&1][j+1]%=MOD;
            }
            if(j-1>=0){
                dp2[(i+1)&1][j-1]+=dp2[i&1][j];
                dp2[(i+1)&1][j-1]%=MOD;
            }
        }
        lef[i+1]=accumulate(dp2[(i+1)&1].begin(),dp2[(i+1)&1].end(),0LL);
        lef[i+1]%=MOD;
    }
    
    ll res=0;
    for(int i=0;i<=n;i++){
        res+=lef[i]*rig[n-i];
        res%=MOD;
    }

    res*=mod_inv(powm(2,m));
    res%=MOD;
    cout<<res<<endl;
    return 0;
}