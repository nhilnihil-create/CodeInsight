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

#define MAXN 200007

int n , k ;
int a[ MAXN ] ;
long long pref[ MAXN ] ;

pair < long long , int > srt[ MAXN ] ;

class Tree {
public :
    int tr[ 5 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos ) {
        if ( IR < pos || pos < IL ) { return ; }
        ++ tr[ where ] ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos ) ;
        }
    }
    int query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( CURL > CURR ) { return 0 ; }
        if ( CURR < IL || IR < CURL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) {
            return tr[ where ] ;
        }
        int mid = ( IL + IR ) / 2 ;
        return ( query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};
Tree w ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        pref[ i ] = ( pref[ i - 1 ] + a[ i ] - k ) ;
    }
}

void solve ( ) {
    for ( int i = 0 ; i <= n ; ++ i ) {
        srt[ i ] = { pref[ i ] , i } ;
    }
    sort ( srt , srt + n + 1 ) ;
    w.init ( 1 , 0 , n ) ;
    long long ans = 0 ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        ans += w.query ( 1 , 0 , n , 0 , srt[ i ].second ) ;
        w.update ( 1 , 0 , n , srt[ i ].second ) ;
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
