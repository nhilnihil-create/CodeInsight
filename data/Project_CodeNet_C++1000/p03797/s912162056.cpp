#include <bits/stdc++.h>
using namespace std;

int main() {
    long n, m;
    cin >> n >> m;

    long ans = min(n, m / 2);
    if (n >= m / 2) {
        cout << ans << endl;
    } else {
        m -= 2 * ans;
        ans += m / 4;
        cout << ans << endl;
    }
}
