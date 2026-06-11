#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x, y;
    cin >> x >> y;
    long long ans = 0;
    if (y - x >= 0) {
        ans = min(y - x, abs(abs(y) - abs(x)) + 1);
    }
    else {
        if (x * y <= 0) {
            ans = abs(abs(y) - abs(x)) + 1;
        }
        else {
            ans = abs(abs(y) - abs(x)) + 2;
        }
    }
    cout << ans << endl;
}