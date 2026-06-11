#include <cstdio>
typedef long long int64;
static const int MAXN = 1e5 + 4;
static const int MODULUS = 1e9 + 7;
#define _  %  MODULUS
#define __ %= MODULUS

int n;
int x[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &x[i]);

    int64 ans = 1;
    int s = 0;
    for (int i = 0, j; i < n; i = j + 1) {
        for (j = i; j < n; ++j)
            if (x[j] >= 2 * s + 1) ++s;
            else { (ans *= (s + 1))__; break; }
    }

    for (int i = 1; i <= s; ++i) (ans *= i)__;
    printf("%lld\n", ans);
    return 0;
}
