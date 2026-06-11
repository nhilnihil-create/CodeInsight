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

#define MAXN 300007

int n , m ;

pair < int , int > a[ MAXN ] ;

vector < int > open[ MAXN ] ;
vector < int > close[ MAXN ] ;

vector < int > divs[ MAXN ] ;
int ans[ MAXN ] ;


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
    void update ( int where , int IL , int IR , int pos , int val ) {
        if ( IR < pos || pos < IL ) { return ; }
        tr[ where ] += val ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , val ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        }
    }
    int query ( int where , int IL , int IR , int pos ) {
        if ( IL > pos ) { return 0 ; }
        if ( IR <= pos ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return ( query ( 2 * where , IL , mid , pos ) + query ( 2 * where + 1 , mid + 1 , IR , pos ) ) ;
        
    }
};
Tree w ;

void calc_divs ( ) {
    int cnt = 0 ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        for ( int j = i ; j <= m ; j += i ) {
            divs[ j ].push_back ( i ) ;
            ++ cnt ;
        }
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
        open[ a[ i ].first ].push_back ( i ) ;
        close[ a[ i ].second ].push_back ( i ) ;
    }
}

void solve ( ) {
    calc_divs ( ) ;
    w.init ( 1 , 1 , m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int sz = open[ i ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            w.update ( 1 , 1 , m , a[ open[ i ][ j ] ].first , 1 ) ;
        }
        sz = divs[ i ].size ( ) ;
        int cnt = w.query ( 1 , 1 , m , i ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            ans[ divs[ i ][ j ] ] += cnt - w.query ( 1 , 1 , m , i - divs[ i ][ j ] ) ;
        }
        sz = close[ i ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            w.update ( 1 , 1 , m , a[ close[ i ][ j ] ].first , -1 ) ;
        }
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        printf ( "%d\n" , ans[ i ] ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
