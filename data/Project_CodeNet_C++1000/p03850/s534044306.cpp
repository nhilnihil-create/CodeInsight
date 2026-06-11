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

int n ;
int a[ MAXN ] ;
char op[ MAXN ] ;

int nxt[ MAXN ] ;
long long pref[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( i == 1 ) { op[ i ] = '+' ; }
        else { cin >> op[ i ] ; }
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    pref[ 0 ] = 0 ;
    long long ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        pref[ i ] = pref[ i - 1 ] + a[ i ] ;
        if ( op[ i ] == '-' ) { ans -= a[ i ] ; }
        else { ans += a[ i ] ; }
    }
    int lst = n + 1 ;
    for ( int i = n ; i >= 1 ; -- i ) {
        nxt[ i ] = lst ;
        if ( op[ i ] == '-' ) { lst = i ; }
    }
    long long aux = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( op[ i ] == '-' ) {
            long long sr = aux - ( pref[ nxt[ i ] - 1 ] - pref[ i - 1 ] ) + ( pref[ n ] - pref[ nxt[ i ] - 1 ] ) ;
            ans = max ( ans , sr ) ;
        }
        if ( op[ i ] == '-' ) { aux -= a[ i ] ; }
        else { aux += a[ i ] ; }
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
