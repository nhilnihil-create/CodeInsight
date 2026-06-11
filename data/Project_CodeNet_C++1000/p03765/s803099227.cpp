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

string a[ 2 ] ;
int pref[ 2 ][ MAXN ] ;

void input ( ) {
    for ( int i = 0 ; i < 2 ; ++ i ) {
        cin >> a[ i ] ;
        int sz = a[ i ].size ( ) ;
        for ( int j = 1 ; j <= sz ; ++ j ) {
            pref[ i ][ j ] = pref[ i ][ j - 1 ] ;
            if ( a[ i ][ j - 1 ] == 'A' ) { ++ pref[ i ][ j ] ; }
            else { pref[ i ][ j ] += 2 ; }
        }
    }
}

void solve ( ) {
    int q ;
    int x , y , z , t ;
    cin >> q ;
    while ( q -- ) {
        cin >> x >> y >> z >> t ;
        int h1 = pref[ 0 ][ y ] - pref[ 0 ][ x - 1 ] ;
        int h2 = pref[ 1 ][ t ] - pref[ 1 ][ z - 1 ] ;
        h1 %= 3 ; h2 %= 3 ;
        if ( h1 == h2 ) { cout << "YES\n" ; }
        else { cout << "NO\n" ; }
        
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
