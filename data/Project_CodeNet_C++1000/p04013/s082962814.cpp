#include <iostream>
#include <vector>

typedef unsigned long long ull;


int main(int argc, char const *argv[]) {
    int N, A;
    std::cin >> N >> A;

    std::vector<int> x(N);
    for (int i = 0; i < N; i++) {
        std::cin >> x[i];
    }

    std::vector<std::vector<std::vector<ull> > > dp(N+1);
    for (int i = 0; i < N+1; i++) {
        dp[i].resize(N+1);
        for (int j = 0; j <= N; j++) {
            dp[i][j].resize(N*A+1, 0);
        }
    }

    dp[0][0][0] = 1;
    for (int k = 1; k <= N*A; k++) {
        dp[0][0][k] = 0;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= N*A; k++) {
                if (j > 0 && k >= x[i]) {
                    dp[i+1][j][k] = dp[i][j][k] + dp[i][j-1][k-x[i]];
                } else {
                    dp[i+1][j][k] = dp[i][j][k];
                }
            }
        }
    }

    ull ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += dp[N][i][i*A];
    }
    std::cout << ans << std::endl;

    return 0;
}
