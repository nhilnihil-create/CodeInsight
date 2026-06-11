#include <bits/stdc++.h>
using namespace std;

long long gcd(long long x, long long y);

signed main() {
    int n;
    long long t[100], g, ans;

    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        cin >> t[i];
    }
    g = t[0];

    for ( int i = 1; i < n; i++ ) {
        if ( t[i] % g == 0 ) {
            g = t[i];
        } else if ( g % t[i] != 0 ) {
            g = (t[i] / gcd(t[i], g)) * g;  
        }
    }

    cout << g << endl;

    return (0);
}

long long gcd(long long x, long long y) {
    if ( y > x ) {
        swap(x, y);
    }

    long long z = x % y;
    while ( z != 0 ) { 
        x = y;
        y = z;
        z = x % y;
    }

    return (y);
}