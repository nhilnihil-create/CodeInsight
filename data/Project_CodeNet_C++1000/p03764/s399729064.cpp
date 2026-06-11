#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 1000000007;
int n, m;
long long x[maxn], y[maxn];

int main() {
    scanf("%d %d", &n, &m);
    long long ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &x[i]);
        ans1 += x[i] * (i - 1) - x[i] * (n - i), ans1 %= P;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%lld", &y[i]);
        ans2 += y[i] * (i - 1) - y[i] * (m - i), ans2 %= P;
    }
    ans1 = ans1 * ans2 % P;
    printf("%lld\n", (ans1 + P) % P);
    return 0;
}