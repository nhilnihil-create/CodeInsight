#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#define rep(i,n) for (long long i=0; i < (n); ++i)
#define rep2(i,n,m) for(long long i=n;i<=m;i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
int main(){
  int n;
  cin>> n ;
  int k=2*n ;
  vector<int> A(k) ;
  rep(i,k) cin>> A[i] ;
  sort(A.begin(),A.end()) ;
  int ans=0 ;
  rep(i,n){
    ans+=A[i*2] ;
  }
  cout <<ans<<endl ; 
    return 0;
}