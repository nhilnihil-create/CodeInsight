#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define INF 1000000000
#define mod 1000000007
using ll=long long;
const ll LINF=1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n;cin>>n;
    vector<ll> x(n);
    rep(i,n) cin>>x[i];
    ll cnt=0,ans=1;
    rep(i,n){
        if(x[i]>=cnt*2+1)   cnt++;
        else                ans=ans*(cnt+1)%mod;
    }
    for(ll i=1;i<=cnt;i++) ans=ans*i%mod;
    cout<<ans<<endl;
    return 0;
}
