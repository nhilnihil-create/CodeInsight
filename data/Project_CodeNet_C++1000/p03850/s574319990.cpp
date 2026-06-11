#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long int64;
static const int MAXN = 1e5 + 4;

int n, a[MAXN];
char op[MAXN];
int64 f[MAXN][3];

int main()
{
    scanf("%d%d", &n, &a[0]);
    for (int i = 1; i < n; ++i) {
        scanf(" %c %d", &op[i], &a[i]);
        if (op[i] == '-') a[i] = -a[i];
    }

    memset(f, 0x80, sizeof f);
    f[0][0] = a[0];
    for (int i = 1; i < n; ++i) {
        f[i][2] = f[i - 1][2] + a[i];
        f[i][1] = std::max(f[i][2], f[i - 1][1] - a[i]);
        f[i][0] = std::max(f[i][1], f[i - 1][0] + a[i]);
        if (a[i] < 0) {
            f[i][1] = std::max(f[i][1], f[i - 1][0] + a[i]);
            f[i][2] = std::max(f[i][2], f[i - 1][1] - a[i]);
        }
    }

    printf("%lld\n", std::max(std::max(f[n - 1][0], f[n - 1][1]), f[n - 1][2]));
    return 0;
}
