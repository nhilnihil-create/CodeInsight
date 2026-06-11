#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calc(ll x, ll y) {
    ll tmp;
    if (x == y) {
        tmp = 0;
    } else if (x < y) {
        tmp = y - x;
    } else {
        tmp = INT_MAX;
    }
    return tmp;
}

int main() {
    ll x, y;
    cin >> x >> y;

    ll output;
    ll a, b, c, d;

    a = calc(x, y);
    b = calc(-1 * x, y) + 1;
    c = calc(x, -1 * y) + 1;
    d = calc(-1 * x, -1 * y) + 2;

    output = min(min(a, b), min(c, d));

    cout << output << endl;

    return 0;
}
