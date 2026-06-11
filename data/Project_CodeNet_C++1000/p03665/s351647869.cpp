#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define rep(i,n) for (long long i=0; i < (n); ++i)
#define rep2(i,n,m) for(long long i=n;i<=m;i++)
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
int main() {
  int n ,p;
  cin >> n>>p ;
  vector<int> A(n) ;
  rep(i,n) cin >>A[i] ;
  int odd = 0 ;
  rep(i,n) {
    if(A[i]%2==1) odd++ ;
  }
  int even= n-odd ;
  ll base= pow(2,even) ;
  ll all=pow(2,odd) ;
  ll ans=0 ;//奇数のもの
  for(int i=0;2*i+1<=odd;i++){
    int c=2*i+1 ;
    ll comb=1 ;
    rep(j,c){
      comb*=(odd-j) ;
    
      comb/=(j+1) ;
    }
   ans+=comb ;
  }
    if(p==1)
    cout << base*ans <<endl ;
    else
     cout <<base*(all-ans) <<endl ; 
     return 0;
}
