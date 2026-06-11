#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const int MAX = 100005;
long long  X[MAX], Y[MAX];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%lld", &X[i]);
    for (int i = 0; i < m; i++) scanf("%lld", &Y[i]);

    long long x, y;
    x = y = 0;
    for (int i = 1; i <= n; i++) {
        x += ((i - 1) * X[i-1] - (n - i) * X[i-1]) % MOD;
        x %= MOD;
    }
    for (int i = 1; i <= m; i++) {
        y += ((i - 1) * Y[i-1] - (m - i) * Y[i-1]) % MOD;
        y %= MOD;
    }

    long long ans;
    ans = (x * y) % MOD;
    printf("%lld\n", ans);

    return 0;
}