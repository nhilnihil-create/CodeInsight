#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    ll n,k;cin>>n>>k;
    vector<ll> a(n),b(n);
    rep(i,n) cin>>a[i]>>b[i];
    string s;ll tmp=k;
    while(tmp>0){
        s+=('0'+tmp%2);
        tmp/=2;
    }
    //sはbit表現の逆順

    ll ans=0;
    rep(i,n){
        if(k==(a[i]|k)) ans+=b[i];
    }

    rep(i,s.size()){
        if(s[i]=='0') continue;

        ll bi=k;
        // i桁を0にしてi桁以下をすべて1にした数を生成する
        rep(j,i){
            bi=(bi|(1<<j));
        }
        bi=(bi^(1<<i));
        // debug
        // cout<<i<<": "<<bitset<5>(bi)<<endl;

        ll tmp=0;
        rep(j,n){
            if(bi==(a[j]|bi)) tmp+=b[j];
        }
        ans=max(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}
