#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n;
long long a[maxn], b[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", &a[i], &b[i]);
    }
    long long ans = 0;
    for (int i = n; i; i--) {
        a[i] += ans;
        ans += (b[i] - a[i] % b[i]) % b[i];
    }
    printf("%lld\n", ans);
    return 0;
}