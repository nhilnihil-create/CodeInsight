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
    ll n,w;cin >> n >>w;
    vvl it(4);
    ll x;cin >> x;
    ll p;cin >> p;it[0].pb(p);
    rep(i,n-1){
        ll a,b;cin >> a >>b;
        it[a-x].pb(b);
    }
    ll ans=0;
    sort(all(it[0]));rev(all(it[0]));
    sort(all(it[1]));rev(all(it[1]));
    sort(all(it[2]));rev(all(it[2]));
    sort(all(it[3]));rev(all(it[3]));
    rep(i,it[0].size()+1){
        rep(j,it[1].size()+1){
            rep(k,it[2].size()+1){
                rep(l,it[3].size()+1){
                    ll val=0;
                    rep(a,i){
                        val+=it[0][a];
                    }
                    rep(b,j){
                        val+=it[1][b];
                    }
                    rep(c,k){
                        val+=it[2][c];
                    }
                    rep(d,l){
                        val+=it[3][d];
                    } 
                    if(w>=x*(i+j+k+l)+j+2*k+3*l){
                        chmax(ans,val);
                    }                   
                }
            }
        }
    }
    cout <<ans <<endl;
}