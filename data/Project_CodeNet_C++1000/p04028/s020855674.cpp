#include <cstdio>
#include <cstring>
typedef long long int64;
static const int MAXN = 5004;
static const int MODULUS = 1e9 + 7;
#define _  %  MODULUS
#define __ %= MODULUS
static const int INV2 = 5e8 + 4;

int n, l;
char s[MAXN];
int64 f[MAXN][MAXN] = {{ 0 }};

int main()
{
    scanf("%d%s", &n, s);
    l = strlen(s);

    f[0][0] = 1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j) if (f[i][j] > 0) {
            (f[i + 1][j + 1] += f[i][j] * 2)__;
            (f[i + 1][j > 0 ? j - 1 : 0] += f[i][j])__;
        }

    int64 ans = f[n][l];
    for (int i = 0; i < l; ++i) (ans *= INV2)__;
    printf("%lld\n", ans);

    return 0;
}
