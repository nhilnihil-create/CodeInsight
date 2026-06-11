#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> a(n * m + 1);

    for (int i = 0; i <= n * m; i++) a[i] = false;

    for (int i = 0; i <= n / 2; i++) {
        for (int j = 0; j <= m / 2; j++) {
            int p = m * i + n * j - 2 * i * j;
            a[p] = a[n * m - p] = true;
        }
    }

    cout << (a[k] ? "Yes" : "No") << endl;

    return 0;
}
