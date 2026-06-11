#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#define rep(i,n) for (long long i=0; i < (n); ++i)
#define rep2(i,n,m) for(long long i=n;i<=m;i++)
#define rep3(i,n,m) for(long long i=n;i>=m;i--)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){
 ll n;
 cin >> n ;
 vector<ll> A(n) ;
 rep(i,n) cin>> A[i] ;
 sort(A.begin(),A.end()) ;
 ll sum=0 ;
 rep(i,n){
   sum+=A[i] ;
 }
 ll ans=1 ;
  rep(i,n-1){
    
    sum-=A[n-1-i];
    if(A[n-1-i]>2*sum){
      break ;
    }
   ans++ ;
  } 
   
   cout <<ans<<endl;
    return 0;
}