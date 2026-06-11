#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x;
    cin >> x;
    int n = (int)sqrt((double)2.0 * x);
    for (int i = max(0, n - 10); i <= n + 10; i++) {
        if (i * (i + 1) / 2 >= x) {
            cout << i;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(20);
    solve();
    return 0;
}
