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

int main(){
  ll n ;cin>> n ;
  vector<ll> A(n) ;
  vector<ll> B(n) ;
  rep(i,n) cin>>A[i]>>B[i] ;
  ll x=A[0] ;ll y=B[0] ;
  ll baia=0 ; ll baib=0 ;
  rep(j,n-1){
  ll i= j+1 ;
  if(x<=A[i]) baia=1 ;
  else{
  ll syo= x/A[i] ; ll ama= x%A[i] ;
  if(ama==0) baia= syo ;
  else baia=syo+1 ;
  }
  if(y<=B[i]) baib=1 ;
  else{
  ll syo= y/B[i] ; ll ama= y%B[i] ;
  if(ama==0) baib= syo ;
  else baib=syo+1 ;
  }
  baia=max(baia,baib) ;
  x= A[i]*baia ;
  y= B[i]*baia ;
  }
   ll ans= x+y ;
   cout<<ans<<endl ;
  return 0;
  }