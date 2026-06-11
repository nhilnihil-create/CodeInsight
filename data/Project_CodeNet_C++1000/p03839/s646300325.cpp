#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    long a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long acc_a[n + 1], acc_b[n + 1];
    acc_a[0] = acc_b[0] = 0;
    for (int i = 1; i <= n; i++) {
        acc_a[i] = acc_a[i - 1] + a[i - 1];
        acc_b[i] = acc_b[i - 1] + max(0l, a[i - 1]);
    }

    long ans = 0;
    for (int i = k; i <= n; i++) {
        ans = max(ans, acc_b[n] - acc_b[i] + max(0l, acc_a[i] - acc_a[i - k]) + acc_b[i - k] - acc_b[0]);
    }
    cout << ans << endl;
    return 0;
}
