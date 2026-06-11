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
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}

 int main(){
  ll n ;cin>> n;
  vector<ll> A(n) ;rep(i,n) cin>>A[i] ;
  ll ans=0 ;
  ll j=0 ;
  ll a= 0 ;ll b=0 ;
  ll sum=0 ;
  rep(i,n){
   if(j%2==0) a+=A[i]%2 ;
   if(j%2==1) b+=A[i]%2 ;
   j++ ;
   if(A[i]==0 || i==n-1){
      if(a%2!=b%2) ans++ ;
     a=0 ; b=0 ;
     j=0 ;
   }  
   sum+=A[i] ;
  }
   cout<<(sum-ans)/2<<endl ;
   return 0;
  }