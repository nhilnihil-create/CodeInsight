#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastIO;
    int W, a, b;
    cin >> W >> a >> b;
    if ((a <= b && b <= a + W) || (b <= a && a <= b + W))
        cout << 0;
    else if (a + W < b)
        cout << b - (a + W);
    else if (b + W < a)
        cout << a - (b + W);
}