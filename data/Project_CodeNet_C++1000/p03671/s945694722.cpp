#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    int a, b, c;
    cin >> a >> b >> c;
    if (min(a, b) == min(b, c))
        cout << b + min(a, c) << endl;
    else
        cout << min(a, b) + min(b, c) << endl;
}
