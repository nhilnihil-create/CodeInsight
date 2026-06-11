#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long x, ans;
    cin >> x;
    if (x <= 6) {
        ans = 1;
    } else if (x <= 11) {
        ans = 2;
    } else if (x % 11 == 0) {
        ans = 2 * (x / 11);
    } else {
        ans = 2 * (x / 11) + (x % 11 > 6 ? 2 : 1);
    }
    cout << ans;

}

int main() {

    solve();
    return 0;
}
