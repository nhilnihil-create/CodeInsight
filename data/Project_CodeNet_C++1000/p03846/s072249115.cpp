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
          
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for ( int i = 0 ; i < n ; i++ ) cin >> a[i];
    sort( a , a + n );
    if ( n % 2 == 1 ) {
        bool y = 1;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( i % 2 == 1 ) {
                if ( a[i] != i + 1 ) y = 0;
            } else {
                if ( a[i] != i ) y = 0;
            }
        }
        if ( y ) {
            int b = 1;
            for ( int i = 0 ; i < n / 2 ; i++ ) {
                b = ( b * 2 ) % 1000000007;
            }
            cout << b;
        } else cout << 0;
    } else {
        bool y = 1;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( i % 2 == 0 ) {
                if ( a[i] != i + 1 ) y = 0;
            } else {
                if ( a[i] != i ) y = 0;
            }
        }
        if ( y ) {
            int b = 1;
            for ( int i = 0 ; i < n / 2 ; i++ ) {
                b = ( b * 2 ) % 1000000007;
            }
            cout << b;
        } else cout << 0;
    }
}