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
#define MAXN 1000007

int n ;
long long dp[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
}

void solve ( ) {
    dp[ 0 ] = 1 ;
    long long ans = 0 ;
    long long pref = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        dp[ i ] = pref ;
        dp[ i ] += dp[ i - 1 ] ;
        dp[ i ] %= MOD ;
        if ( i >= 2 ) {
            pref += dp[ i - 2 ] ;
            pref %= MOD ;
        }
    }
    for ( int i = 0 ; i < n - 1 ; ++ i ) {
        long long h = ( dp[ i ] * ( n - 1 ) ) % MOD ;
        h = ( h * ( n - 1 ) ) % MOD ;
        ans = ( ans + h ) % MOD ;
    }
    int coef = n ; 
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        ans = ( ans + dp[ i ] * coef ) % MOD ;
        if ( i != n - 2 ) { -- coef ; }
    }
    printf ( "%lld\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
