#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 2000010
int a[N], n;
int sta[N], top;
int l[N], r[N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        while (top && a[i] <= a[sta[top]]) r[sta[top--]] = i - 1;
        sta[++top] = i;
    }
    while (top) r[sta[top--]] = n;
    for (int i = n; i; i--) {
        while (top && a[i] <= a[sta[top]]) l[sta[top--]] = i + 1;
        sta[++top] = i;
    }
    while (top) l[sta[top--]] = 1;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += (ll)(r[i] - i + 1) * (i - l[i] + 1) * a[i];
    printf("%lld\n", ans);
    return 0;
}
