#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    lint a, b, c, d;
    cin >> a >> b >> c >> d;
    lint rect1 = a * b, rect2 = c * d;
    if (rect1 >= rect2)
        cout << rect1 << endl;
    else
        cout << rect2 << endl;
}
