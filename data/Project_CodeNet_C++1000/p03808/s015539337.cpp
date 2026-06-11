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
 
 

 int main(){
  ll n ; cin>> n ;
  vector<ll> A(n) ;
  rep(i,n) cin>>A[i] ;
  bool flag=1 ;
  ll sum =0 ;
  rep(i,n) sum+= A[i] ;
  ll base = n*(n+1)/2 ;
  if((sum%base)!=0) flag=0 ;
  ll kai = sum/base ;
  ll u=0 ;
 
  rep(i,n){
    ll now=0 ;
   if(i==n-1) now = A[0]-A[n-1] ;
   else now= A[i+1]-A[i] ;
   ll kk = (kai-now)/(n) ;
   if( !((  (kai-now)%(n) ==0   ) && (0<=kk )&&(kk<=kai))) flag=0 ;
  
  u+= kk ;
  }

  if(u!=kai) flag=0 ;
  if(flag) cout<<"YES"<<endl ;
  else cout<<"NO"<<endl ;
  return 0 ;
}


