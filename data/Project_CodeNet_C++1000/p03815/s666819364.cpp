// abc.053.C - X: Yet Another Die Game

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main( void ) {
    ll x;
    cin >> x;

    ll cnt = ( x - x % 11 ) / 11;
    cnt *= 2;
    if( x % 11 != 0 ) {
        if( x % 11 <= 6 )
            cnt += 1;
        else
            cnt += 2;
    }
    cout << cnt << endl;

    return 0;
}
