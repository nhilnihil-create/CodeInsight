#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, s = 0;
    cin >> n >> k;
    int a[n], r = n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (s + a[i] < k) s += a[i];
        else r = i;
    }
    cout << r;
}