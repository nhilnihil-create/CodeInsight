#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 5001;
const int MOD = (int)1e9 + 7;

char s[N];
int two[N], dp[2][N];

void update(int& x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

int main()
{
    two[0] = 1;
    for (int i = 1; i < N; ++ i) {
        two[i] = two[i - 1] * 2 % MOD;
    }
    int m;
    scanf("%d%s", &m, s);
    int n = strlen(s);
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < m; ++ i) {
        memset(dp[i + 1 & 1], 0, sizeof(dp[i + 1 & 1]));
        for (int j = 0; j <= m; ++ j) {
            update(dp[i + 1 & 1][std::max(j - 1, 0)], dp[i & 1][j]);
            if (j < m) {
                update(dp[i + 1 & 1][j + 1], dp[i & 1][j] * 2);
            }
        }
    }
    int result = dp[m & 1][n];
    for (int i = 0; i < n; ++ i) {
        result = result * 500000004LL % MOD;
    }
    printf("%d\n", result);
}
