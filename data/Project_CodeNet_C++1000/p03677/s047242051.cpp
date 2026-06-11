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
#include<unordered_map>
using namespace std ;

#define MAXN 100007

int n , m ;
int a[ MAXN ] ;

long long add[ MAXN ] ;
long long cnt[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    long long ans = 0 ;
    for ( int i = 1 ; i < n ; ++ i ) {
        if ( a[ i ] < a[ i + 1 ] ) {
            ans += a[ i + 1 ] - a[ i ] ;
            add[ a[ i ] + 1 ] += a[ i ] + 1 ;
            add[ a[ i + 1 ] + 1 ] -= a[ i ] + 1 ;

            ++ cnt[ a[ i ] + 1 ] ;
            -- cnt[ a[ i + 1 ] + 1 ] ;
        }
        else {
            ans += a[ i + 1 ] + m - a[ i ] ;
            
            add[ a[ i ] + 1 ] += a[ i ] + 1 ;
            add[ m + 1 ] -= a[ i ] + 1 ;

            ++ cnt[ a[ i ] + 1 ] ;
            -- cnt[ m + 1 ] ;

            add[ 1 ] += a[ i ] - m + 1 ;
            add[ a[ i + 1 ] + 1 ] -= a[ i ] - m + 1 ;

            ++ cnt[ 1 ] ;
            -- cnt[ a[ i + 1 ] + 1 ] ;
        }
    }
    long long sm = 0 ;
    long long p = 0 ;
    long long mx = 0 ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        sm += add[ i ] ;
        p += cnt[ i ] ;
        if ( mx < p * i - sm ) { mx = p * i - sm ; }
    }
    printf ( "%lld\n" , ans - mx ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
