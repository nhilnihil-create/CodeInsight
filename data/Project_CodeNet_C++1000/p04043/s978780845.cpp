#include <bits/stdc++.h>

using namespace std;
int main () {
    int f = 2,s = 1;
    int x; 
    for ( int i = 0 ; i < 3 ; i++ ) {
        cin >> x;
        if ( x == 5 ) f--;
        if ( x == 7 ) s--;
    }
    if ( !f && !s ) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
