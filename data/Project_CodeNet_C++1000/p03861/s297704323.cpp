#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll a, b, x;
    cin >> a >> b >> x;

    // if (a % x == 0 && b % x == 0) {
    //     cout << (b - a) / x + 1 << endl;
    // } else if (a % x == 0 || b % x == 0) {
    //     cout << (b - a) / x + 1 << endl;
    // } else {
    //     cout << (b - a) / x << endl;
    // }

    ll output = b / x;
    if (a != 0) {
        output -= (a - 1) / x;
    } else {
        output++;
    }
    cout << output << endl;

    return 0;
}
