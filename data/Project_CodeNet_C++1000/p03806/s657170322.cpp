#include <iostream>
#include <algorithm>

constexpr int MAX_N = 41, MAX_VOL = 410, INF = 1e4;

int dp[MAX_N][MAX_VOL + 20][MAX_VOL + 20];

int a[MAX_N], b[MAX_N], c[MAX_N];

int main()
{
    int n, ma, mb;
    std::cin >> n >> ma >> mb;

    for (int i = 1; i <= n; ++i)
        std::cin >> a[i] >> b[i] >> c[i];

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= MAX_VOL; ++j)
        {
            for (int k = 0; k <= MAX_VOL; ++k)
                dp[i][j][k] = INF;
        }
    }

    dp[0][0][0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= MAX_VOL; ++j)
        {
            for (int k = 0; k <= MAX_VOL; ++k)
            {
                if (dp[i - 1][j][k] != INF)
                    dp[i][j + a[i]][k + b[i]] =
                        std::min(dp[i][j + a[i]][k + b[i]], dp[i - 1][j][k] + c[i]);
                dp[i][j][k] = std::min(dp[i][j][k], dp[i - 1][j][k]);
            }
        }
    }

    int ans = INF;

    std::cerr << "DEBUG:BEGIN" << std::endl;

    for (int i = 1; i * ma <= MAX_VOL && i * mb <= MAX_VOL; ++i)
    {
        ans = std::min(ans, dp[n][i * ma][i * mb]);
        std::cerr << i << ' ' << dp[n][i * ma][i * mb] << std::endl;
    }

    std::cerr << "DEBUG:END" << std::endl;

    std::cout << ((ans == INF) ? -1 : ans) << std::endl;

    return 0;
}