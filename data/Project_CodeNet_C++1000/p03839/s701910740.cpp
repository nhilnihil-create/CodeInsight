#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
  
typedef long long ll;
const int N = 100010;
const ll mod = 1e9 + 7;

ll a[N], b[N];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    ll ans = 0, p = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        b[i] = b[i - 1] + a[i];
        if (a[i] > 0) p += a[i];
    }
    for (int i = 1; i <= k; ++i) {
        if (a[i] > 0) p -= a[i];
    }
    for (int i = 1; i + k - 1 <= n; ++i) {
        ans = max(ans, p);
        ans = max(ans, b[i + k - 1] - b[i - 1] + p);
        if (a[i] > 0) p += a[i];
        if (a[i + k] > 0) p -= a[i + k];
    }
    printf("%lld\n", ans);
    return 0;
}