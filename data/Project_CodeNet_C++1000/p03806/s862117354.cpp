#include <iostream>
#include <vector>

int main()
{
    int N, Ma, Mb;

    std::cin >> N >> Ma >> Mb;
    std::vector<int> a(N), b(N), c(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i] >> b[i] >> c[i];
    }

    constexpr int MAX = 400;
    constexpr int INF = 1e9;
    std::vector<std::vector<int>> dp(MAX + 1, std::vector<int>(MAX + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++)
        for (int j = MAX; j >= 0; j--)
            for (int k = MAX; k >= 0; k--) {
                if (dp[j][k] == INF) continue;
                int nj = j + a[i], nk = k + b[i];
                dp[nj][nk] = std::min(dp[nj][nk], dp[j][k] + c[i]);
            }

    int min_cost = INF;
    for (int i = 1; i <= MAX / std::max(Ma, Mb); i++) {
        min_cost = std::min(min_cost, dp[Ma * i][Mb * i]);
    }
    std::cout << (min_cost == INF ? -1 : min_cost) << std::endl;
    return 0;
}