#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastIO;

    uint64_t n, power = 1;
    cin >> n;

    for (uint64_t i = 1; i <= n; i++) {
        power *= i;
        power %= 1000000007;
    }
    cout << power << endl;
}