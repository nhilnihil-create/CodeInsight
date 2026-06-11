#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MAXN = 100 * 1000 + 123;









int n, A, B, a[MAXN];

int32_t main() {
    cin >> n >> A >> B;
    A -= B;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int dw = -1, up = 1000 * 1000 * 1000 + 123;
    while (up - dw > 1) {
        int m = (up + dw) / 2, use = 0;
        for (int i = 0; i < n; i++)
            use += max((a[i] - m * B + A - 1) / A, 0ll);
        if (use > m)
            dw = m;
        else
            up = m;
    }
    cout << up;
    return 0;
}