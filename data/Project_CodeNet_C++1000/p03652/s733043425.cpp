#include <bits/stdc++.h>
#define off  exit( 0 )
#define cn   continue
#define rt   return
#define sc   scanf
#define pr   printf
#define pb   push_back
#define pf   push_front
#define p_f  pop_front
#define p_b  pop_back
#define ff   first
#define ss   second
#define ll   long long
#define ld   long double
#define N    100256
#define M    998244353
#define I    1000000000000000000
#define pdd  pair < ld, ld >
#define pll  pair < ll, ll >
#define pii  pair < int, int >
#define sqr( a )           a * a
#define all( c )           c.begin(), c.end()
#define srt( c )           sort( all( c ) )
#define rev( c )           reverse( all( c ) )
#define srtr( c )          sort( c.rbegin(), c.rend() );
using namespace std;

ll n, m, a[ 505 ][ 505 ], ans = M;
bool ok[ 505 ];
void solve()
{
    sc( "%I64d%I64d", &n, &m );
    for( int i = 0; i < n; i ++ )
        for( int j = 0; j <m; j ++ )
        {
            cin >> a[i][j];
            a[i][j] --;
        }

    for( int k = 0; k < m; k ++ )
    {
        ll v[ 505 ];
        memset( v, 0LL, sizeof v );
        for( int i = 0; i < n; i ++ )
            for( int j = 0; j < m; j ++ )
                if( !ok[ a[i][j] ] )
                {
                    v[ a[i][j] ] ++;
                    break;
                }
        ll cnt = 0, t;
        for( int i = 0; i < m; i ++ )
            if( cnt < v[ i ] )
            {
                cnt = v[ i ];
                t = i;
            }
        ans = min( ans, cnt );
        ok[t] = 1;
    }

    pr( "%I64d", ans );
}

int main()
{
    int tt = 1;
    //sc( "%d", &tt );
    for( int i = 1; i <= tt; i ++ )
        solve();
}










