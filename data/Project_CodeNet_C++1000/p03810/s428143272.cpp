#include <bits/stdc++.h>

#define PB          push_back
#define PF          push_front
#define MP          make_pair
#define FI          first
#define SE          second
#define SIZE( A )   int( ( A ).size( ) )
#define ALL( A )    ( A ).begin( ), ( A ).end( )
#define ALLR( A )   ( A ).rbegin( ), ( A ).rend( )

using namespace std;

typedef long long           ll;
typedef unsigned long long  ull;
typedef long double         lf;
typedef pair< int, int >    pii;
typedef pair< ll, ll >      pll;
typedef vector< bool >      vb;
typedef vector< lf >        vd;
typedef vector< ll >        vll;
typedef vector< int >       vi;
typedef vector< pii >       vpii;

const int MAXN = int( 1e5 )+10;
const int MOD  = int( 360 );
const int oo   = INT_MAX;

int n, odd, even, cnt;
int arr[ MAXN ];

bool reduce() {
  if( odd != 1 ) return false;
  int gcd = 0;
  for( int i = 0; i < n; ++i ) {
    if( arr[i] == 1 ) return false;
    if( arr[i]%2 ) --arr[i];
    gcd = __gcd( gcd, arr[i] );
  }
  odd = even = 0;
  for( int i = 0; i < n; ++i ) {
    arr[i] /= gcd;
    if( arr[i]%2 ) ++odd;
    else ++even;
  }
  return true;
}

int main( ) {

  #ifdef LOCAL
    freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
  #else
    //freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
  #endif

  while( cin >> n ) {
    even = odd = cnt = 0;
    for( int i = 0; i < n; ++i ) {
      cin >> arr[ i ];
      if( arr[i]%2 ) ++odd;
      else ++even;
    }
    while( reduce() ){ ++cnt; }
    even += cnt;
    if( even%2 ) {
      cout << "First\n";
    }
    else {
      cout << "Second\n";
    }
  }
  return 0;
}
