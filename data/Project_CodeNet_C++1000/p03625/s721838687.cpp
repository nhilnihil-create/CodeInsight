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
    ll n;
    cin >> n;
    ll a[n];
    ll h = 0 , w = 0;
    for( ll i = 0 ; i < n ; i++ ) {
        cin >> a[i];
    }
    sort( a , a + n );
    for( ll i = n - 1 ; i >= 0 ; i-- ) {
        if( a[i] == a[i + 1] ) {
            if( h == 0 ) {
                h = a[i];
                i--;
            } else {
                w = a[i];
                cout << h * w;
                return 0;
            }
        }
    }
    cout << 0;
}
