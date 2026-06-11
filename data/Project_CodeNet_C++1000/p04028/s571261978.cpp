#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
#include<random>
using namespace std ;

#define MOD 1000000007
#define MAXN 5007

int n , k ;
string a ;

long long dp[ MAXN ][ MAXN ] ;

long long fastpow ( long long x , long long pw ) {
    long long ret = 1 ;
    while ( pw > 0 ) {
        if ( ( pw & 1 ) == 0 ) {
            x = ( x * x ) % MOD ;
            pw /= 2 ;
        }
        else {
            ret = ( ret * x ) % MOD ;
            -- pw ;
        }
    }
    return ret ;
}

void input ( ) {
    cin >> k ;
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    dp[ 0 ][ 0 ] = 1 ;
    for ( int j = 0 ; j < k ; ++ j ) {
        for ( int i = 0 ; i < MAXN - 1 ; ++ i ) {
            int nw = i - 1 ;
            if ( nw < 0 ) { nw = 0 ; }
            dp[ nw ][ j + 1 ] = ( dp[ nw ][ j + 1 ] + dp[ i ][ j ] ) % MOD ;
            dp[ i + 1 ][ j + 1 ] = ( dp[ i + 1 ][ j + 1 ] + 2 * dp[ i ][ j ] ) % MOD ;
        }
    }
    long long aux = fastpow ( 2 , n ) ;
    aux = fastpow ( aux , MOD - 2 ) ;
    printf ( "%lld\n" , ( dp[ n ][ k ] * aux ) % MOD ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
