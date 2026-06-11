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
#define vtpl(x,y,z) vector<tuple<x,y,z>>
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
int main(){
    ll n;cin >>n;
    map<ll,ll> mp;
    rep(i,n){
        ll a;cin >> a;
        mp[a]++;
    }
    if(mp.size()>2)cout <<"No" <<endl,exit(0);
    if(mp.size()==1){
        ll t;
        for(auto p:mp)t=p.fi;
        if(t==n-1||t<=n/2)cout <<"Yes" <<endl;
        else cout <<"No" <<endl;
    }
    else{
        vpl v;
        for(auto x:mp){
            v.pb(x);
        }
        if(v[0].fi+1!=v[1].fi)cout <<"No" <<endl,exit(0);
        ll a=v[1].fi,x=v[0].se;
        if(a-x>=1&&x+2*(a-x)<=n)cout <<"Yes" <<endl;
        else cout <<"No" <<endl;
    }
}