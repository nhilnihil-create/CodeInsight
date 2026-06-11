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

int n ;
long long a[ MAXN ] ;
pair < long long , int > b[ MAXN ] ;

long long ans[ MAXN ] ;

void move ( int &st , long long &cnt ) {
    while ( st > 1 && b[ st - 1 ].first == b[ st ].first ) { -- st ; ++ cnt ; }
    
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%lld" , &a[ i ] ) ;
        b[ i ] = { a[ i ] , i } ;
    }
    sort ( b + 1 , b + n + 1 ) ;
}

void solve ( ) {
    long long cnt = 1 ;
    int id = n ;
    int mnpos = b[ id ].second ;
    while ( id > 0 ) {
        move ( id , cnt ) ;
        long long diff = b[ id ].first - b[ id - 1 ].first ;
        mnpos = min ( mnpos , b[ id ].second ) ;
        ans[ mnpos ] += diff * cnt ;
        -- id ;
        ++ cnt ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%lld\n" , ans[ i ] ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
