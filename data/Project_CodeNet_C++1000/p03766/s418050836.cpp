#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010, P = 1000000007;
int n, f[maxn];

int main() {
    scanf("%d", &n);
    f[1] = n, f[2] = 1LL * n * n % P;
    for (int i = 3, s = 0; i <= n; i++) {
        (s += f[i - 3]) %= P;
        f[i] = (f[i - 1] + s + 1LL * (n - 1) * (n - 1) + n - i + 2) % P;
    }
    printf("%d\n", f[n]);
    return 0;
}