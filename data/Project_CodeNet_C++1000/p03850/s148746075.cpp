// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> Pt;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
#define mod9 1000000009LL
#define mod7 1000000007LL
#define INF  1023456789LL
#define INF16 10000000000000000LL
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline LL getint(){
  LL _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline LL add( LL _x , LL _y , LL _mod = mod7 ){
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
inline LL sub( LL _x , LL _y , LL _mod = mod7 ){
  _x -= _y;
  return _x < 0 ? _x + _mod : _x;
}
inline LL mul( LL _x , LL _y , LL _mod = mod7 ){
  _x *= _y;
  return _x >= _mod ? _x % _mod : _x;
}
LL mypow( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 1LL;
  LL _ret = mypow( mul( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = mul( _ret , _a , _mod );
  return _ret;
}
LL mymul( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 0LL;
  LL _ret = mymul( add( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = add( _ret , _a , _mod );
  return _ret;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define N 101010
void build(){

}
int n , op[ N ];
LL vl[ N ] , sv[ N ] , ans , ev[ N ];
void init(){
  n = getint();
  for( int i = 1 ; i <= n ; i ++ ){
    if( i > 1 ){
      char c[ 9 ]; scanf( "%s" , c );
      if( c[ 0 ] == '-' )
        op[ i ] = 1;
    }
    vl[ i ] = getint();
    sv[ i ] = sv[ i - 1 ] + vl[ i ];
    if( op[ i ] ) ans -= vl[ i ];
    else ans += vl[ i ];
    ev[ i ] = ans;
  }
}
void solve(){
  int lst = -1;
  for( int i = n ; i >= 1 ; i -- )
    if( op[ i ] ){
      if( lst != -1 ){
        LL tans = ev[ i - 1 ] - ( sv[ lst - 1 ] - sv[ i - 1 ] ) +
                                ( sv[ n ] - sv[ lst - 1 ] );
        //printf( "%d %lld %d %lld %lld %lld\n" , i , tans , lst , ev[ i - 1 ] , sv[ lst ] - sv[ i - 1 ] , sv[ n ] - sv[ lst - 1 ] );
        ans = max( ans , tans );
      }
      lst = i;
    }
  printf( "%lld\n" , ans );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
