#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    if (n <= k)
        cout << n * x << endl;
    else
        cout << k * x + (n - k) * y << endl;
    return 0;
}