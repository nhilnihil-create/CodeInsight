#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Graph= vector<vector<ll>>;
struct edge{ll to ; ll cost ;} ;
using graph =vector<vector<edge>> ;
#define rep(i,n) for (ll i=0; i < (n); ++i)
#define rep2(i,n,m) for(ll i=n;i<=m;i++)
#define rep3(i,n,m) for(ll i=n;i>=m;i--)
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define mpa make_pair
#define fi first
#define se second 
#define set20 cout<<fixed<<setprecision(20) ;
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
double pi=acos(-1) ;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
 
vector<bool> seen;
vector<ll> ans ;
void dfs(const Graph &G, int v,vector<ll> &ans) {
    seen[v] = true; // v を訪問済にする
    
    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        ans[next_v]= ans[v]+1 ;
        dfs(G, next_v,ans); // 再帰的に探索
    }
}

 int main(){
 ll n ; cin>> n ;
 Graph g(n) ;
 rep(i,n-1){
   ll a,b ;
   cin>>a>>b ;
   a--;b-- ;
  g[a].pb(b) ;
  g[b].pb(a) ;
 }

 vector<ll> x(n),y(n) ;
 seen.assign(n,false) ;
 dfs(g,0,x) ;
 seen.assign(n,false) ;
 dfs(g,n-1,y) ;
 ll cnt=0 ;
 rep(i,n){
   if(x[i]<=y[i]) cnt++ ;
   //cout<<x[i]<<" "<<y[i]<<endl ;
 }
 
 if(cnt>n-cnt) cout<<"Fennec"<<endl ;
 else cout<<"Snuke"<<endl ;
   return 0 ;
 }

