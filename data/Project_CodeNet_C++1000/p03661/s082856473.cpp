#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;
ll a[200000], ans = (1L << 62), X, x;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%ld", &a[i]);
        X += a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        x += a[i];
        ans = min(ans, abs(X - x - x));
    }
    cout << ans << endl;
    return 0;
}