#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
using namespace std;
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , x = 0;
    cin >> n;
    int a[n];
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> a[i];
        x += a[i];
    }
    sort( a , a + n );
    if ( x % 10 == 0 ) {
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = i ; j < n ; j++ ) {
                if ( ( x - a[j] ) % 10 > 0 ) {
                    cout << x - a[j];
                    return 0;
                }
            }
            x -= a[i];
        }
    } else {
        cout << x;
        return 0;
    }
    cout << 0;
}

