#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
vector<vector<int>> dp(5010,vector<int>(5010)),dp2(5010,vector<int>(5010));
int main(){
    ll n,maxk;cin >> n >>maxk;
    vector<int> v(n);rep(i,n)cin >> v[i];
    ll ans=0;
    //vector<vector<int>> dp(n+1,vector<int>(maxk));
    dp[0][0]=1;
    rep(j,n){
        rep(k,maxk){
            dp[j+1][k]+=dp[j][k];
            if(k+v[j]<maxk)dp[j+1][k+v[j]]+=dp[j][k];
        }
    }
    //vector<vector<int>> dp2(n+1,vector<int>(maxk));
    dp2[n][0]=1;
    per(j,n){
        rep(k,maxk){
            dp2[j][k]+=dp2[j+1][k];
            if(k+v[j]<maxk)dp2[j][k+v[j]]+=dp2[j+1][k];
        }
    }
    rep(i,n){
        bool need=false;
        vector<int> st;
        rep(j,maxk)if(dp2[i+1][j])st.pb(j);
        rep(j,maxk){
            if(dp[i][j]){
                ll z=lower_bound(all(st),maxk-j)-lower_bound(all(st),maxk-j-v[i]);
                if(z){need=true;break;}
            }
            if(need)break;
        }
        if(!need)ans++;
    }
    cout << ans <<endl;
}