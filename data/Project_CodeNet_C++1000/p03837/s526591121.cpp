/*
* @Author: _dp95
* @Date:   2020-04-13 07:06:33
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

const int MAX = 2*100 + 10 ;
const ll INF = 1e18 ;
const int MOD = 1e9 + 7 ;

ll d[MAX][MAX] ;
vector< vector< ll > > edges ;

signed main( ){
  timesaver ;
  for( ll i = 0 ; i < MAX ; i++ ){
    for( ll j = 0 ; j < MAX ; j++ )
      d[i][j] = INF ;
  }
  ll n, m ;
  cin >> n >> m ;
  for( ll i = 0 ; i < m ; i++ ){
    ll x, y, w ;
    cin >> x >> y >> w ;
    edges.pb({x,y,w});
    d[x][y] = d[y][x] = w ;
  }
  for (ll k = 1; k <= n; ++k) {
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            if (d[i][k] < INF && d[k][j] < INF)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
        }
    }
  }
  for( int i = 0 ; i <= n ; i++ )
    d[i][i] = 0 ;
  ll ans(0) ;
  for( auto g : edges ){
    ll x = g[0], y =g[1], w = g[2] ;
    ll f = 1 ;
    for( ll i = 1 ; i <= n ; i++ )
      for( ll j = 1 ; j <= n ; j++ ){
        if( d[i][j] == (d[i][x] + d[j][y] + w ) )
          f = 0 ;
      }
    ans += f ;
  }
  cout << ans << nl ;
}