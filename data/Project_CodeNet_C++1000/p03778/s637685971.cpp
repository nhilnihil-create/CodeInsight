#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int w, a, b;
    cin >> w >> a >> b;
    int ans;
    if (abs(b - a) <= w) {
        ans = 0;
    } else if (b < a) {
        ans = a - (b + w);
    } else
        ans = b - (a + w);

    cout << ans;

}

int main() {

    solve();
    return 0;
}

