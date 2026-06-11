#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t a, b, x;
    cin >> a >> b >> x;

    int64_t count = 0;

    if (a == 0) count++;
    int64_t b2 = b - (b % x);
    if (a > 0) {
        count += b2 / x - (a - 1) / x;
    } else {
        count += b2 / x - a / x;
    }

    cout << count << endl;
    return 0;
}