#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n, K;
ll a[maxn], s[maxn], pre[maxn], suf[maxn];

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]), s[i] = s[i - 1] + a[i];
        pre[i] = pre[i - 1];
        if (a[i] > 0) pre[i] += a[i];
    }
    for (int i = n; i; i--) {
        suf[i] = suf[i + 1];
        if (a[i] > 0) suf[i] += a[i];
    }
    ll ans = 0;
    for (int i = 1; i + K - 1 <= n; i++) {
        ans = max(ans, pre[i - 1] + suf[i + K] + max(0LL, s[i + K - 1] - s[i - 1]));
    }
    printf("%lld\n", ans);
    return 0;
}