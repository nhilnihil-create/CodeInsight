//written by newbiechd
#include <cstdio>
using namespace std;
const int N = 1000007, yyb = 1e9+ 7;
long long f[N], s;
int main() {
    register int n, i;
    scanf("%d", &n);
    f[n] = n, f[n - 1] = 1ll * n * n % yyb;
    for (i = n - 2; i > 0; --i)
        s = (s + f[i + 3]) % yyb,
            f[i] = (f[i + 1] + s + 1ll * (n - 1) *(n - 1) + i + 1) % yyb;
    printf("%lld", f[1]);
    return 0;
}
