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
using namespace std ;

#define MAXN 100007
#define LOG 20

int n ;
int a[ MAXN ] ;
int len ;

int fw[ MAXN ][ LOG ] ;
int bw[ MAXN ][ LOG ] ;


void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    scanf ( "%d" , &len ) ;
}

void solve ( ) {
    int pos = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        while ( pos < n && a[ pos + 1 ] <= a[ i ] + len ) { ++ pos ; }
        fw[ i ][ 0 ] = pos ;
    }
    pos = n ;
    for ( int i = n ; i >= 1 ; -- i ) {
        while ( pos > 1 && a[ pos - 1 ] >= a[ i ] - len ) { -- pos ; }
        bw[ i ][ 0 ] = pos ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j < LOG ; ++ j ) {
            bw[ i ][ j ] = bw[ bw[ i ][ j - 1 ] ][ j - 1 ] ;
        }
    }
    for ( int i = n ; i >= 1 ; -- i ) {
        for ( int j = 1 ; j < LOG ; ++ j ) {
            fw[ i ][ j ] = fw[ fw[ i ][ j - 1 ] ][ j - 1 ] ;
        }
    }
    int q ;
    scanf ( "%d" , &q ) ;
    while ( q -- ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        int ans = 0 ;
        int h = x ;
        for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
            
            if ( x < y && fw[ h ][ i ] < y ) {
                if ( fw[ h ][ i ] > 0 ) { 
                    ans += ( 1 << i ) ;
                    h = fw[ h ][ i ] ;
                }
            }
            else if ( y < x && bw[ h ][ i ] > y ) {
                ans += ( 1 << i ) ;
                h = bw[ h ][ i ] ;
            }
        }
        printf ( "%d\n" , ans + 1 ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
