#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef vector<ll> vi;
typedef vector<vi> vvi;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define REP(i,k,n) for(ll i=k;i<(ll)(n);i++)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(v) v.begin(),v.end()
const ll inf=1001001001001001;
template<class T> bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T> void out(T a){cout<<a<<endl;}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<endl;}
template<class T> void outvv(T v){rep(i,v.size())outv(v[i]);}

int main(){
    int n,k;cin>>n>>k;
    ll ans=0,mi=inf;
    vi v(n);
    rep(i,n)cin>>v[i];
    rep(i,n)if(v[i]>0)ans+=v[i];
    vi sei(n);
    rep(i,n)if(v[i]>0)sei[i]=v[i];
    ll sum=0;
    rep(i,k)sum+=sei[i];
    REP(i,k,n){
        chmin(mi,sum);
        sum-=sei[i-k];
        sum+=sei[i];
    }
    chmin(mi,sum);
    sei=vi(n);
    rep(i,n)if(v[i]<0)sei[i]=-v[i];
    sum=0;
    rep(i,k)sum+=sei[i];
    REP(i,k,n){
        chmin(mi,sum);
        sum-=sei[i-k];
        sum+=sei[i];
    }
    chmin(mi,sum);
    out(ans-mi);
}