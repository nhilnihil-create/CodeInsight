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
  int n;
  cin >> n ;
  vector<int> A(n) ;
  rep(i,n) cin >> A[i] ;
  ll sum =0 ;
  rep(i,n) sum+=A[i] ;
  ll sam=A[0] ;
  ll ans= abs(sam*2-sum) ;
  rep2(i,1,n-2){
    sam+=A[i] ;
    ans =min(ans,abs(2*sam-sum)) ;
  }
 cout << ans <<endl ;
     return 0;
}
