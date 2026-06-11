#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll dp[45][405][405];
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    V<int> s(n),t(n),u(n);
    for(int i=0;i<n;i++)cin>>s[i]>>t[i]>>u[i];
    for(int i=0;i<45;i++){
        for(int j=0;j<405;j++){
            for(int k=0;k<405;k++){
                dp[i][j][k]=inf;
    }
    }
    }
    dp[0][0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<405;j++){
            for(int k=0;k<405;k++){
                if(dp[i][j][k]>=inf)continue;
                chmin(dp[i+1][j][k],dp[i][j][k]);
                chmin(dp[i+1][j+s[i]][k+t[i]],dp[i][j][k]+u[i]);
            }
        }
    }
    ll ans=-1;
    for(int i=1;i<405;i++)for(int j=1;j<405;j++){
        if(dp[n][i][j]>=inf)continue;
        if(j*a==i*b){
            if(ans==-1)ans=dp[n][i][j];
            else chmin(ans,dp[n][i][j]);
        }
    }
    cout<<ans<<"\n";
}