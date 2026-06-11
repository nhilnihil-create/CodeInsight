#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n;
ll a[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int l = 1, r = n, ans;
    auto chk = [&](int x) {
        ll s = a[x];
        for (int i = 1; i <= n; i++) if (i ^ x) {
            if (a[i] > s * 2) return 0;
            s += a[i];
        }
        return 1;
    };
    while (l <= r) {
        int mid = (l + r) >> 1;
        chk(mid) ? r = (ans = mid) - 1 : l = mid + 1;
    }
    printf("%d\n", n - ans + 1);
    return 0;
}