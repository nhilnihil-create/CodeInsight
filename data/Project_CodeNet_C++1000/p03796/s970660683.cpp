#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int main() {
    int n;
    cin >> n;
    int64_t ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
        ans %= mod;
    }
    cout << ans << '\n';
    return 0;
}
