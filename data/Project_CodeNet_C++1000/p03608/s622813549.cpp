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
//#define at(x,i) get<i>(x);//
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
    ll n,m,r;cin >> n >>m >>r;
    vl v(r);rep(i,r){cin >> v[i];v[i]--;}sort(all(v));
    vvl dist(n,vl(n,inf));
    rep(i,m){
        ll a,b,c;cin >>a >>b >>c;a--;b--;
        dist[a][b]=c;
        dist[b][a]=c;
    }
    rep(i,n)dist[i][i]=0;
    rep(k,n)rep(i,n)rep(j,n)chmin(dist[i][j],dist[i][k]+dist[k][j]);
    ll ans=inf;
    do{
        ll tmp=0;
        rep(i,v.size()-1){
            tmp+=dist[v[i]][v[i+1]];
        }
        chmin(ans,tmp);
    }while(next_permutation(all(v)));
    cout <<ans <<endl;
}