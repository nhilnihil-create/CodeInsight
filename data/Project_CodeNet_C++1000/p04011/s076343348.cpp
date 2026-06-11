#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    lint n, k, x, y;
    cin >> n >> k >> x >> y;
    if (n < k)
        cout << n * x << endl;
    else
        cout << k * x + (n - k) * y << endl;
}

