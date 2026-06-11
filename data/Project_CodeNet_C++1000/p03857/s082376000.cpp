#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph= vector<vector<int>>; 
#define rep(i,n) for (ll i=0; i < (n); ++i)
#define rep2(i,n,m) for(ll i=n;i<=m;i++)
#define rep3(i,n,m) for(ll i=n;i>=m;i--)
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define mpa make_pair
#define fi first
#define se second
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}

struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n,-1) {}
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
};
 int main(){
   ll n,k ,l ; cin>>n>>k>>l ;
   UnionFind af(n),bf(n) ;
   rep(i,k){
     ll a,b ;cin>>a>>b ;
     a-- ;b-- ;
     af.unite(a,b) ;
   }
   rep(i,l){
     ll a,b ;cin>>a>>b ;
     a-- ;b-- ;
     bf.unite(a,b) ;
   }
   vector<pair<P,ll>> A(n) ;
   rep(i,n){
     A[i].fi.fi=af.find(i) ;
     A[i].fi.se=bf.find(i) ;
     A[i].se=i ;
     // cout<<af.find(i)<<" "<<bf.find(i)<<endl;
   }
   sort(A.begin(),A.end()) ;
   vector<pair<ll,vector<ll>>> B(n) ;
   rep(i,n){
     B[i].fi=0 ;
   }
   ll j=0 ;
   rep(i,n){
     if(i==0 || ((A[i].fi.fi==A[i-1].fi.fi) &&(A[i].fi.se==A[i-1].fi.se))){
     B[j].fi ++ ;
     B[j].se.pb(A[i].se) ;
     }
     else{
       j++ ;
       B[j].fi ++ ;
       B[j].se.pb(A[i].se) ;
     }
   }
   ll ans[n] ;
   rep(i,n){
     if(B[i].fi==0) break ;
   for(auto u : B[i].se ){
   ans[u]=B[i].fi ;
   }
   }

  rep(i,n){
    if(i==n-1)cout<<ans[i]<<endl ;
    else cout<<ans[i]<<" " ;
  }
   return 0;
  }