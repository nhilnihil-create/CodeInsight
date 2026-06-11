#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, a[maxn];

int main() {
    scanf("%d", &n), n *= 3;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1, greater<int>());
    long long sum = 0;
    for (int i = 2; i <= n / 3 * 2; i += 2) {
        sum += a[i];
    }
    printf("%lld\n", sum);
    return 0;
}