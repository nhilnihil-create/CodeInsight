/*
* @Author: _dp95
* @Date:   2020-04-12 09:54:32
*/
#include "bits/stdc++.h"
using namespace std ;

#define timesaver ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll ;
typedef long double ldb ;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define nl '\n'

#define all( x ) x.begin(),x.end() 
#define sz( x ) ( int )( x ).size( )
#define mem( a, val ) memset(a, val, sizeof( a ) )
#define deci( x ) cout<<fixed<<setprecision( x );
#define bitcount( x ) __builtin_popcountll( x )

const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

const int MAX = 2*1000*1000 + 10 ;
const ll INF = 1e18 ;
const int MOD = 1e9 + 7 ;

map<ll,ll>mpp ;

ll exp( ll x, ll y ){
  ll ans = 1 ;
  while( y ){
    if(y&1)
      ans = ans*x % MOD ;
    x = x*x % MOD ;
    y >>= 1 ;
  }
  return ans ;
}

signed main( ){
  timesaver ;
  ll n ;
  cin >> n ;
  vector< ll > v(n) ;
  for( ll &i : v )
    cin >> i ;
  for( ll i = 1 ; i <= n ; i++ ){
    ll l = i-1 ;
    ll r = n-i ;
    mpp[abs(l-r)]++ ;
  }
  for( ll i : v )
    mpp[i]-- ;
  ll f = 1 ;
  for( auto i : mpp ){
    if( i.S != 0 )
      f = 0 ;
  }
  if( !f )
    return cout << 0 << nl, 0 ;
  n = n/2 ;
  cout << exp( 2, n ) << nl ;
}