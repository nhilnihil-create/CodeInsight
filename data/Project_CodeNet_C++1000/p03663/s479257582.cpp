#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    auto check = [](ll x) {
        cout << "? " << x << std::endl;
        char a;
        cin >> a;
        return a == 'Y';
    };

    ll l = 1e10, r = 1e11;
    while ( r - l > 1 ) {
        ll m = (l+r)/2;
        if ( check(m) ) r = m;
        else l = m;
    }
    ll x = r / 10, t = x;
    while ( t % 10 == 0 ) t /= 10;
    if ( t != 1 ) {
        while ( !check(x-1) ) x /= 10;
    } else {
        while ( x > 1 && check(x-1) ) x /= 10;
    }
    cout << "! " << x << std::endl;
    return 0;
}

int main() {
    solve();
    return 0;
}