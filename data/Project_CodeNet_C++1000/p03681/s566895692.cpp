#include<bits/stdc++.h>
using namespace std ;

# define ll long long
# define line cout << "\n" ;

# define fast ios_base :: sync_with_stdio ( false ) ; cin.tie ( 0 ) ; cout.tie ( 0 ) ;

const int N = 1e6 + 3 , mod = 1e9 + 7 ;
ll fact[N] ;

void pre_compute ()
{
    fact[0] = 1 ;
    for ( int i = 1 ; i < N ; i ++ )
    {
        fact[i] = fact[i - 1] * i ;
        fact[i] %= mod ;
    }
}

void solve ()
{
    ll a , b ;
    cin >> a >> b ;

    ll diff = abs ( a - b ) ;
    if ( diff > 1 ) { cout << 0 ; line ; return ; }

    ll ans = fact[a] * fact[b] ;
    ans %= mod ;

    ll x = 1 ;
    if ( a == b ) x = 2 ;

    ans *= x ;
    ans %= mod ;

    cout << ans ; line ;
}

int main()
{fast
//    freopen ( "input.txt" , "r" , stdin ) ;
//    freopen ( "output.txt" , "w" , stdout ) ;

    pre_compute () ;

    int t = 1 ;
    // cin >> t ;

    while ( t -- )
        solve ( ) ;

    return 0 ;
}
