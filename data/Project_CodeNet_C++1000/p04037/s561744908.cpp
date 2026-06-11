#include <iostream>
#include <algorithm>
using namespace std;

long long n, a[(1<<20)];

pair < long long, long long > proj ( long long y, long long x ) {
    long long c = min( x, y );
    return make_pair( y-c, x-c );
}

void printS( long long c ) {
    if ( c%2 ) { cout << "First\n"; }
    else { cout << "Second\n"; }
}

int main () {
    cin >> n;
    for ( long long i = 0 ; i < n ; i ++ ) {
        cin >> a[i];
    }
    sort( a, a+n );
    reverse( a, a+n );
    int szX, szY;

    for ( long long i = 0 ; i < n ; i ++ ) {
        if ( i == n-1 || a[i+1] < a[i] ) {
            pair < long long , long long > c = proj( a[i]-1, i );
            if ( c.first == 0 && c.second == 0 ) { cout << "Second\n"; return 0; }
        }
    }

    long long t = -1, r = -1;

    for ( long long i = 0 ; i < n ; i ++ ) {
        if ( i == n-1 || a[i+1] < a[i] ) {
            if ( proj( a[i]-1, i ).first == 0 ) { r = proj( a[i]-1, i ).second; szY = a[i]; break; }
        }
    }
    for ( long long i = n-1 ; i >= 0 ; i -- ) {
        if ( i == n-1 || a[i+1] < a[i] ) {
            if ( proj( a[i]-1, i ).second == 0 ) { t = proj( a[i]-1, i ).first; szX = i+1; break; }
        }
    }

    if ( r == -1 ) {
        printS( t );
        return 0;
    }
    if ( t == -1 ) {
        printS( r );
        return 0;
    }

    if ( r%2 == t%2 ) {
        printS( r );
    }else {
        pair < int, int > cc = proj ( szY, szX );
        if ( cc.first <= 1 && cc.second <= 1 ) {
            if ( cc.first == 0 && cc.second == 0 ) {
                cout << "First\n";
                return 0;
            }else if ( cc.first == 1 ) {
                if ( t%2 == 0 ) {
                    cout << "First\n";
                }else {
                    cout << "Second\n";
                }
            }else {
                if ( r%2 == 0 ) {
                    cout << "First\n";
                }else {
                    cout << "Second\n";
                }
            }
        }
        else {
            if ( szX < szY ) {
                printS ( r );
            }else {
                printS( t );
            }
        }
    }
    return 0;
}
