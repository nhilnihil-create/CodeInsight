#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, x, y, s = 0;
    cin >> n >> k >> x >> y;
    if (k <= n) s = s + k * x + (n - k) * y;
    else s = s + n * x;
    cout << s;
}