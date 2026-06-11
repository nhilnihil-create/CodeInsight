#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;

ll a[200005];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (i > 0)
            a[i] += a[i - 1];
    }
    ll ans = LL_INF;
    for (int i = 0; i < n - 1; i++) {
        if (abs(a[n - 1] - 2 * a[i]) < ans)
            ans = abs(a[n - 1] - 2 * a[i]);
    }
    cout << ans << endl;
    return 0;
}