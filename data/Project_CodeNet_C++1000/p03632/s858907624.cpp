#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if( a <= c && d <= b) {
        cout << d - c << endl;
        return 0;
    }
    else if( c <= a && b <= d) {
        cout << b -a  << endl;
        return 0;
    }
    else if ( a <= c && c <= b) {
             cout << b - c << endl;
             return 0;
         }
    else if(c <= a && a <= d ) {
            cout << d - a << endl;
            return 0;
    }
    else cout << 0 << endl;

    return 0;
}