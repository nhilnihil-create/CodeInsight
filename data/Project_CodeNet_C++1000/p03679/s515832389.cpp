#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    int x, a, b;
    cin >> x >> a >> b;
    if (a >= b)
        cout << "delicious\n";
    else if (a + x >= b)
        cout << "safe\n";
    else
        cout << "dangerous\n";
}
