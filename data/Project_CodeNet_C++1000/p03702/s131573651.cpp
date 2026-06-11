#include <bits/stdc++.h>
using namespace std;

int main() {
    long n, a, b;
    cin >> n >> a >> b;
    long h[n], diff = a - b;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    long lb = -1, ub = (h[max_element(h, h + n) - h] - 1) / b + 1;
    long ans = ub;
    while (ub - lb > 1) {
        long mid = (lb + ub) / 2, count = 0;
        for (int i = 0; i < n; i++) {
            if (mid * b < h[i])
                count += (h[i] - mid * b - 1) / diff + 1;
        }
        if (count <= mid) {
            ans = mid;
            ub = mid;
        } else {
            lb = mid;
        }
    }
    cout << ans << endl;
    return 0;
}
