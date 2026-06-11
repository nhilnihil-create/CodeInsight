#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long a, b, x;
    cin >> a >> b >> x;
    long long ans;
    long long ar, bl;
    ar = a + (x - a % x) % x;
    bl = b - b % x;
    if (ar > b || bl < a) {
        cout << 0;
        return;
    }
    ans = (bl - ar) / x + 1;
    cout << ans;
}

int main() {

    solve();
    return 0;
}
