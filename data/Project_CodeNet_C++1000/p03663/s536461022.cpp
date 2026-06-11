#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll i = 1;
    while (i * 10 < (ll)1e11) {
        cout << "? " << i << endl;
        char c;
        cin >> c;
        if (c % 2 == 0) {
            i /= 10;
            break;
        }
        i *= 10;
    }
    debug(i);
    if (i == (ll)1e10) {
        i = 1;
        ll j = 2;
        for (int k = 0; k < 11; k++) {
            cout << "? " << j << endl;
            char c;
            cin >> c;
            if (c % 2 == 1) {
                cout << "! " << i << endl;
                break;
            }
            i *= 10;
            j *= 10;
        }
        return 0;
    }
    ll j = i * 10 - 1;
    while (i + 1 < j) {
        ll mid = (i + j) / 2;
        ll t = mid * 10 + 1;
        cout << "? " << t << endl;
        char c;
        cin >> c;
        if (c % 2 == 0) {
            i = mid;
        } else {
            j = mid;
        }
    }
    cout << "! " << j << endl;
    return 0;
}