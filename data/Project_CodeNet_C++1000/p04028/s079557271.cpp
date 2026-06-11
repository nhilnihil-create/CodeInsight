#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
#define Mod 1000000007
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;
#define INF 1ll<<59

int main(){
    ll i,j;
    ll n;
    cin>>n;
    string s;
    cin>>s;  // なんでも関係ない

    VVI dp(n+1,VI(n+2,0));  //dp[i][j] i操作で長さjの押し方
    dp[0][0]=1;
    for(i=1;i<=n;i++){
        for(j=0;j<=n;j++){
            if(j==0) dp[i][j]=dp[i-1][1]+dp[i-1][0];
            else {
                dp[i][j]=2*dp[i-1][j-1]+dp[i-1][j+1];
            }
            dp[i][j]%=Mod;
        }
    }
    ll ans=dp[n][s.size()];

    ll mt=(1000000007+1)/2;
    for(i=0;i<s.size();i++){
        ans*=mt;
        ans%=Mod;
    }
    cout<<ans<<endl;
    
}