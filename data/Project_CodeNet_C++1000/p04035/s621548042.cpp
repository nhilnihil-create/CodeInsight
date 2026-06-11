#include <bits/stdc++.h>
using namespace std;

signed main () {
    int n, l;
    cin >> n >> l;
    vector < int > a(n + 1, 0);
    int j = 0;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i) {
        if (a[i] + a[i + 1] >= l) {
            j = i;
            break;
        }
    }
    if (j == 0)
        cout << "Impossible\n";
    else {
        cout << "Possible\n";
        for (int i = 1; i < j; ++i)
            cout << i << '\n';
        for (int i = n - 1; i > j; --i)
            cout << i << '\n';
        cout << j << '\n';
    }
}
