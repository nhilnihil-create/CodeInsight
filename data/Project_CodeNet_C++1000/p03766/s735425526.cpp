#include <bits/stdc++.h>
using namespace std;

const int MOD = ( int ) 1e9 + 7;
const int MAXN = ( int ) 1e6;

int N;
int dp[ MAXN + 1 ];
int pdp[ MAXN + 1 ];

signed main(){
  ios::sync_with_stdio( 0 );
  cin >> N;
  pdp[ 0 ] = dp[ 0 ] = 1;
  pdp[ 1 ] = dp[ 1 ] = N;
  ++pdp[ 1 ];
  for( int i = 2; i <= N; ++i ){
    dp[ i ] = ( 1LL * pdp[ i - 1 ] - ( i - 2 >= 0 ? dp[ i - 2 ] : 0 ) + ( N - ( i - 1 ) ) ) % MOD;
    ( dp[ i ] += 1LL * ( N - 1 ) * ( N - 1 ) % MOD ) %= MOD;
    pdp[ i ] = ( pdp[ i - 1 ] + dp[ i ] ) % MOD;
  }
  if( dp[ N ] < 0 ) dp[ N ] += MOD;
  cout << dp[ N ] << endl;
  return 0;
}
