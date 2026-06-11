#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, y, x;
    cin >> n >> k >> x >> y;
    if (n < k) {
        cout << n * x;
        return 0;
    }
    cout << k * x + (n - k) * y;
}
