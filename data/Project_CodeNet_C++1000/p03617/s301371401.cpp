#include <bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

int main(){
  ll a , b , c , d ;
  cin >> a >> b >> c >> d ;
  ll n ;
  cin >> n ;
  ll one = min(4*a,2*b) ;
  one = min(one,c) ;
  if(n%2 == 0 ) cout << min( (n/2)*d ,n*one ) << endl ;
  if(n%2 == 1 ) cout << min( (n/2)*d + one , n*one ) << endl;
}