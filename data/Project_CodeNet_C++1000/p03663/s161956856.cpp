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

int len ;
int a[ 17 ] ;

bool ask ( int en ) {
    cout << "? " ;
    for ( int i = 0 ; i <= en ; ++ i ) {
        cout << a[ i ] ;
    }
    if ( en == len - 1 ) { cout << "0" ; }
    cout << "\n" ;
    fflush ( stdout ) ;
    char ret ;
    cin >> ret ;
    if ( en == len - 1 ) { return ( ret == 'N' ) ; }
    return ( ret == 'Y' ) ;
}

void input ( ) {

}

void solve ( ) {
    len = 0 ;
    while ( len < 15 ) {
        cout << "? 1" ;
        for ( int i = 0 ; i < len ; ++ i ) {
            cout << "0" ;
        }
        cout << "\n" ;
        fflush ( stdout ) ;
        char ret ;
        cin >> ret ;
        if ( ret == 'Y' ) {
            ++ len ;
        }
        else { break ; }
    }
    if ( len == 15 ) {
        len = 0 ;
        while ( 1 ) {
            cout << "? 2" ;
            for ( int i = 0 ; i < len ; ++ i ) {
                cout << "0" ;
            }
            cout << "\n" ;
            fflush ( stdout ) ;
            char ret ;
            cin >> ret ;
            if ( ret == 'N' ) {
                ++ len ;
            }
            else { break ; }
        }
        cout << "! 1" ;
        for ( int i = 0 ; i < len ; ++ i ) {
            cout << "0" ;
        }
        cout << "\n" ;
        fflush ( stdout ) ;
        return ;
    }
    for ( int i = 0 ; i < len ; ++ i ) {
        a[ i ] = 0 ;
    }
    for ( int i = 0 ; i < len ; ++ i ) {
        int l , r , mid ;
        l = 0 ; r = 9 ;
        if ( i == 0 ) { ++ l ; }
        while ( r - l > 2 ) {
            mid = ( l + r ) / 2 ;
            a[ i ] = mid ;
            if ( ask ( i ) == true ) { l = mid ; }
            else { r = mid - 1 ; }
        }
        while ( r >= 0 ) {
            a[ i ] = r ;
            if ( ask ( i ) == true ) { break ; }
            -- r ;
        }
        if ( i == len - 1 ) { ++ r ; ++ a[ i ] ; }
    }
    cout << "! " ;
    for ( int i = 0 ; i < len ; ++ i ) {
        cout << a[ i ] ;
    }
    cout << "\n" ;
    fflush ( stdout ) ;
}


int main ( ) {
    //ios_base :: sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
