#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
    int a[3];
    rep(i, 3) cin >> a[i];

    if (count(a, a + 3, 5) == 2 && count(a, a + 3, 7) == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
