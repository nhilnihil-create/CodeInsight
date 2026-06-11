#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[n - 1] - a[0] > 1) {
        cout << "No" << '\n';
        return 0;
    }
    if (a[n - 1] == a[0]) {
        if (a[0] <= n / 2 || a[0] == n - 1) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
        return 0;
    }
    int x = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != a[0]) {
            x = n - i;
            break;
        }
    }
    if (n - x + 1 <= a[n - 1] && a[n - 1] <= n - x + x / 2) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
    return 0;
}