#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n, k, x, y;
    cin >> n >> k >> x >> y;

    ll ans = min(k, n) * x + max(n - k, 0) * y;

    cout << ans << endl;
    return 0;
}
