#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int n;
LL ans, a[100050], x;

int work() {
    scanf("%d%lld", &n, &x);
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    ans = max(a[0]-x, 0LL);
    a[0] -= ans;
    for (int i = 1; i < n; ++i) ans += max(a[i]+a[i-1]-x, 0LL), a[i] = min(x-a[i-1], a[i]);
    printf("%lld\n", ans);
    return 0;
}

int main() {
    work();
    //while (~scanf("%d", &n)) work();
    //scanf("%d", &T); while (T--) work();

    return 0;
}
