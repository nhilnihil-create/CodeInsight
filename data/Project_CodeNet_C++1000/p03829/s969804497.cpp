#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;
int main() {

  ll N , A , B  ;
  int ans = 0 ;
  cin >> N >> A >> B ;
  vector<ll> X(N) ;
  rep(i,N) cin >> X.at(i) ;
  ll sum = 0 ;
  rep(i,N-1) sum += min( A*(X.at(i+1) - X.at(i) ) , B ) ;
  cout << sum << endl;
}