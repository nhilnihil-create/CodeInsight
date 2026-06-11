#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<(n);++i)
#define rep2(i,a,b) for (ll i=(a);i<(b);++i)
#define debug(x) cout << #x << '=' << x << endl
#define all(v) (v).begin(),(v).end()
const ll MOD=1e9+7;
//const ll MOD=998244353;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;}
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;}
    return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    ll ans=0,sum=0;
    vector<ll> dp(n);
    rep(i,n){
        if (i==0||i==1) dp[i]=1;
        else dp[i]=(sum+MOD-dp[i-2])%MOD;
        sum=(sum+dp[i])%MOD;
        if (i<n-2) ans=(ans+dp[i]*(((n-1)*(n-1)%MOD+i+2)%MOD)%MOD)%MOD;
        else if (i==n-2) ans=(ans+dp[i]*(n-1)%MOD*n%MOD)%MOD;
        else ans=(ans+dp[i]*n%MOD)%MOD;
    }
    cout << ans << endl;
}