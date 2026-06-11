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
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
int main(){
  int n ;cin>>n ;
  vector<ll> A(n) ;rep(i,n) cin>>A[i] ;
  int w=0 ;
  int ans=0 ;
  rep(i,n-1){
   if((w==1&&A[i]<A[i+1])
   ||(w==-1&&A[i]>A[i+1])) {
      ans++ ;
      w=0 ;
      }
   else if(A[i]>A[i+1] ) w=1 ;
   else if(A[i] <A[i+1] ) w= -1 ;
   
  }
  cout<< ans+1 <<endl ;
     return 0;
  }