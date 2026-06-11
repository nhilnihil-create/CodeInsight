#include <bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
#define mp make_pair
using namespace std;
using ll=long long;
using P=pair<int,int>;
const ll INF=1LL<<30;
const ll LINF=1LL<<61;
const double eps=1e-5;
const ll MOD=1e9+7;
ll mpow(ll x,ll n){
    ll res=1;
    while(n>0){
        if(n&1){
            res*=x;
            res%=MOD;
        }
        x=x*x%MOD;
        n>>=1;
    }
    return res;
}
int main(){
    int n;cin>>n;
    string s;cin>>s;
    int m=s.length();
    vector<vector<ll>> dp(n+1,vector<ll>(n+1));
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            dp[i+1][j+1]+=dp[i][j]*2LL;dp[i+1][j+1]%=MOD;
            if(j>0){
                dp[i+1][j-1]+=dp[i][j];dp[i+1][j-1]%=MOD;
            }else{
                dp[i+1][j]+=dp[i][j];dp[i+1][j]%=MOD;
            }
        }
    }
    cout<<dp[n][m]*mpow(mpow(2,m),MOD-2)%MOD<<endl;
}   
