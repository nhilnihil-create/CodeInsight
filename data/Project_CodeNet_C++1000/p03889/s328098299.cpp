#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define ull unsigned long long

const int base = 233;
const int N = 1e5 + 5;

char st[N];
ull hasf , hass , hast;

int main ( void ) {
    scanf ( "%s" , st + 1 );
    int len = strlen ( st + 1 );
    for ( int i = 1 ; i <= len ; i++ ) 
        hasf = hasf * base + st[i];
    for ( int i = len ; i >= 1 ; i-- )
        hass = hass * base + st[i];
    if ( hasf == hass ) {
        puts ( "Yes" );
      //  system ( "pause" );
        return 0;
    }
    for ( int i = 1 ; i <= len ; i++ ) {
        if ( st[i] == 'b' ) 
            st[i] = 'd';
        else if ( st[i] == 'd' ) 
            st[i] = 'b';
        else if ( st[i] == 'p' ) 
            st[i] = 'q';
        else if ( st[i] == 'q' ) 
            st[i] = 'p';
    } 
    for ( int i = 1 ; i <= len ; i++ ) 
        hast = hast * base + st[i];
    if ( hasf == hast || hast == hass ) {
        puts ( "Yes" );
     //   system ( "pause" );
        return 0;
    }
    puts ( "No" );
    //system ( "pause" );
    return 0;
}