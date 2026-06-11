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
    ll n;cin >> n;
    vl v(n);rep(i,n)cin >> v[i];
    ll sum=accumulate(all(v),0LL);
    ll p=n*(n+1)/2;
    if(sum%p!=0)cout << "NO" <<endl,exit(0);
    ll lap=sum/p;
    vector<ll> end(n);
    v.pb(v[0]);
    rep(i,n){
        ll dif=v[i+1]-v[i];
        if((lap-dif)%n!=0)cout << "NO" <<endl,exit(0);
        end[i]+=(lap-dif)/n;
        if(end[i]<0)cout << "NO" <<endl,exit(0);
    }
    if(accumulate(all(end),0LL)==lap){
        ll now=0;
        rep(i,n)now+=end[i]*(n-i);
        bool ok=true;
        rep(i,n){
            //cout << now <<endl;
            if(now!=v[i])ok=false;
            now+=lap;
            now-=end[i]*n;
        }
        if(ok)cout << "YES" <<endl;
        else cout <<"NO" <<endl;
    }
    else cout << "NO" <<endl;
}