#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define pii pair<ll,ll>

using namespace :: std;

const ll maxn=5009;
const ll inf=1e9+500;
const ll mod=1e9+7;

ll poww(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
ll dp[maxn][maxn];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll m=s.size();

    dp[0][0]=1;
    for(ll i=1;i<=n;i++){
        dp[i][0]=(dp[i-1][1]+dp[i-1][0])%mod;;
        for(ll j=1;j<=n;j++){
            dp[i][j]=(dp[i-1][j-1]*2+dp[i-1][j+1])%mod;
        }
    }
    cout<<(dp[n][m]*poww(poww(2,m),mod-2))%mod;
}
