#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll h , w , x = 1e10;
    cin >> h >> w;
    if ( w % 3 == 0 ) x = min( x , 0ll );
    else x = min( x , h );
    if ( h % 3 == 0 ) x = min( x , 0ll );
    else x = min( x , w );
    for ( int i = 1 ; i < w ; i++ ) {
        ll a = i * h , b , c;
        if ( h % 2 == 1 ) {
            b = ( h / 2 ) * ( w - i );
            c = b + w - i;
        } else {
            b = ( h / 2 ) * ( w - i );
            c = b;
        }
        x = min( x , max( { a , b , c } ) - min( { a , b , c } ) );
    }
    for ( int i = 1 ; i < h ; i++ ) {
        ll a = i * w , b , c;
        if ( w % 2 == 1 ) {
            b = ( w / 2 ) * ( h - i );
            c = b + h - i;
        } else {
            b = ( w / 2 ) * ( h - i );
            c = b;
        }
        x = min( x , max( { a , b , c } ) - min( { a , b , c } ) );
    }
    cout << x;
}
