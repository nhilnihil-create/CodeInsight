#include <bits/stdc++.h>
using namespace std;

int64_t solve(int64_t a, int64_t b) {
    if (a > b)
        swap(a, b);
    int64_t q = b / a;
    if (b % a != 0)
        return 2LL * q * a + solve(a, b % a);
    return 2LL * (q - 1) * a + a;
}

int main() {
    int64_t n, x; cin >> n >> x;

    int64_t ans = n + solve(x, n - x);

    cout << ans << "\n";
}