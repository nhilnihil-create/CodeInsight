#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, m;
    cin >> n >> m;
    int64_t ans = min(n, m / 2);
    m -= n * 2;
    if (m > 0) ans += m / 4;
    cout << ans << '\n';
    return 0;
}
