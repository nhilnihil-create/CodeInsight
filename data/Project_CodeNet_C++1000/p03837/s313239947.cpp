#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
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
    ll n,m;cin >> n >>m;
    vvl v(n,vl(n,inf));
    vpl p(m);vl w(m);
    rep(i,n)v[i][i]=0;
    rep(i,m){
        ll a,b,c;cin >>a >>b >>c;a--;b--;
        v[a][b]=c;v[b][a]=c;
        p[i].fi=a;p[i].se=b;w[i]=c;
    }
    rep(k,n)rep(i,n)rep(j,n)chmin(v[i][j],v[i][k]+v[k][j]);
    ll ans=0;
    rep(i,m){
        ll x=p[i].fi,y=p[i].se,c=w[i];
        if(v[x][y]!=c)ans++;
    }
    cout <<ans <<endl;
}